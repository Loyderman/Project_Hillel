#include <thread>
#include <climits>
#include <atomic>
#include <vector>
#include <chrono>
#include <cstdint>
#include <Intrin.h>
#include "collatzh.h"

void Steps(std::vector<std::atomic_uint>& cache,
           std::uint64_t a,
           std::uint64_t n1,
           std::uint64_t place,
           std::uint64_t n,
           std::atomic_bool& exception_flag,
           const unsigned short int threads,
           std::vector<std::uint64_t>& results_steps,
           std::vector<std::uint64_t>& results_numbers)
{
    struct Interval {
        std::uint64_t steps = 0;
        std::uint64_t number = 1;
    };

    std::vector<Interval> buffer;
    buffer.reserve(1000);

    std::uint64_t maximum = 0;
    std::uint64_t MaxNum = 0;
    std::uint64_t copy_a = a;
    std::uint64_t not_odd = 0;

    for (; copy_a <= n; copy_a += threads)
    {
        a = copy_a;
        if (exception_flag.load() == true)
        {
            break;
        }
        while (a != 1)
        {
            if (a > UINT64_MAX)
            {
                exception_flag.store(true);
                break;
            }
            if ((a & 1) != 0)
            {
                if (a > n1)
                {
                    buffer.push_back({ 1,a });
                    a = a * 3 + 1;
                }
                else
                {
                    if (cache.at(a / 2) == 0)
                    {
                        buffer.push_back({ 1,a });
                        a = a * 3 + 1;
                    }
                    else
                    {
                        if (!buffer.empty())
                        {
                            buffer.back().steps += cache[a / 2];
                            a = 1;
                        }
                        else
                        {
                            Interval temp = { cache[a / 2], a };
                            buffer.push_back(temp);
                            a = 1;
                        }
                    }
                }
            }
            else if ((a & 1) == 0)
            {
                if (!buffer.empty())
                {
                    if ((a & (a - 1)) == 0)
                    {
                        unsigned long exp;
                        _BitScanForward64(&exp, a);
                        buffer.back().steps += exp;
                        a = 1;
                    }
                    else
                    {
                        buffer.back().steps += 1;
                        a >>= 1;
                    }
                }
                else
                {
                    if ((a & (a - 1)) == 0)
                    {
                        unsigned long exp;
                        _BitScanForward64(&exp, a);
                        not_odd += exp;
                        a = 1;
                    }
                    else
                    {
                        not_odd += 1;
                        a >>= 1;
                    }
                }
            }
        }

        std::uint64_t Initial = 0;

        if (!buffer.empty())
        {
            for (size_t i = buffer.size(); i-- > 0;)
            {
                if (buffer[i].number <= n1)
                {
                    cache[(buffer[i].number) / 2] = Initial + ((buffer[i]).steps);
                    Initial = Initial + (buffer[i]).steps;
                }
                else
                {
                    Initial += (buffer[i]).steps;
                }
            }
            Initial += not_odd;
            not_odd = 0;
            if (Initial > maximum || Initial == maximum)
            {
                maximum = Initial;
                MaxNum = copy_a;
            }
        }
        else
        {
            maximum = not_odd;
            MaxNum = copy_a;
        }
        buffer.clear();
    }

    results_steps[place] = maximum;
    results_numbers[place] = MaxNum;
}

CollatzResult calculateCollatzPool(std::uint64_t n, unsigned short int threads_count, std::atomic_bool& exception_flag)
{
    CollatzResult res;
    std::vector<std::uint64_t> local_steps(threads_count, 0);
    std::vector<std::uint64_t> local_numbers(threads_count, 0);

    try
    {
        std::vector<std::thread> pool;
        pool.reserve(threads_count);

        std::uint64_t cache_size = (n > 2500000000) ? 2500000000 : (n / 2) + 1;
        std::vector<std::atomic_uint> cache(cache_size);


        auto start = std::chrono::high_resolution_clock::now();

        for (unsigned short int i = 0; i < threads_count; i++)
        {
            pool.emplace_back(Steps,
                              std::ref(cache),
                              (n / 2) + i,
                              cache_size,
                              i,
                              n,
                              std::ref(exception_flag),
                              threads_count,
                              std::ref(local_steps),
                              std::ref(local_numbers));
        }

        for (auto& th : pool)
        {
            if (th.joinable()) th.join();
        }


        auto end = std::chrono::high_resolution_clock::now();

        res.elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();

        if (exception_flag.load()) {
            res.errorMessage = "Обчислення перервано користувачем або перевищено ліміт інту!";
            return res;
        }

        std::uint64_t max_s = local_steps[0];
        std::uint64_t max_n = local_numbers[0];

        for (unsigned short int i = 1; i < threads_count; i++)
        {
            if (max_s <= local_steps[i])
            {
                max_s = local_steps[i];
                max_n = local_numbers[i];
            }
        }

        res.maxSteps = max_s;
        res.bestNumber = max_n;
    }
    catch (...)
    {
        res.errorMessage = "Критична помилка обчислень";
    }

    return res;
}