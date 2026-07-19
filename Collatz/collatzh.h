#ifndef _COLLATZH_H_
#define _COLLATZH_H_

#include <vector>
#include <atomic>
#include <cstdint>
#include <QString>

struct CollatzResult {
    std::uint64_t maxSteps = 0;
    std::uint64_t bestNumber = 0;
    double elapsedTimeMs = 0;
    QString errorMessage = "";
};

void Steps(std::vector<std::atomic_uint>& cache,
           std::uint64_t a,
           std::uint64_t n1,
           std::uint64_t place,
           std::uint64_t n,
           std::atomic_bool& exception_flag,
           const unsigned short int threads,
           std::vector<std::uint64_t>& results_steps,
           std::vector<std::uint64_t>& results_numbers);


CollatzResult calculateCollatzPool(std::uint64_t n, unsigned short int threads_count, std::atomic_bool& exception_flag);

#endif
