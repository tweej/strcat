cmake_minimum_required(VERSION 3.1)
project(strcat)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE Release)


add_subdirectory(googletest) # https://github.com/google/googletest

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Disable buggy C++03/C++11 related tests" FORCE)
add_subdirectory(benchmark) # https://github.com/google/benchmark

set(BUILD_TESTING OFF CACHE BOOL "Disable tests which depend on benchmark" FORCE)
add_subdirectory(cctz) # https://github.com/google/cctz.git

add_subdirectory(abseil-cpp) # https://github.com/abseil/abseil-cpp.git


add_executable(strcat_benchmark microbench.cpp)
target_link_libraries(strcat_benchmark benchmark absl::strings)

add_executable(strcat_test test.cpp)
target_link_libraries(strcat_test gtest_main)

message(WARNING "Make sure to run cpupower in performance mode before running the benchmark: cpupower frequency-set --governor performance")
find_program(CPUPOWER cpupower)
if(NOT CPUPOWER)
    message(WARNING "No cpupower binary found!")
endif()
