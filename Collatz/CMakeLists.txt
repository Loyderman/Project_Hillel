cmake_minimum_required(VERSION 3.19)
project(Collatz LANGUAGES CXX)


find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Concurrent)

qt_standard_project_setup()

qt_add_executable(Collatz
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    Collatz.cpp
    collatzh.h
)

target_link_libraries(Collatz
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Concurrent
)

install(TARGETS Collatz
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Collatz
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
