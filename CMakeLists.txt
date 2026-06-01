cmake_minimum_required(VERSION 3.14)
project(strcat)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE Release)

include(FetchContent)

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0
)
FetchContent_MakeAvailable(googletest)

set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL_DOCS OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL_TOOLS OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG        v1.9.5
)
FetchContent_MakeAvailable(benchmark)

set(BUILD_TOOLS OFF CACHE BOOL "" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
  cctz
  GIT_REPOSITORY https://github.com/google/cctz.git
  GIT_TAG        v2.5
)
FetchContent_MakeAvailable(cctz)

FetchContent_Declare(
  abseil-cpp
  GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
  GIT_TAG        20260107.1
)
FetchContent_MakeAvailable(abseil-cpp)


add_executable(strcat_benchmark microbench.cpp)
target_link_libraries(strcat_benchmark benchmark absl::strings)

add_executable(strcat_test test.cpp)
target_link_libraries(strcat_test gtest_main)

message(WARNING "Make sure to run cpupower in performance mode before running the benchmark: cpupower frequency-set --governor performance")
find_program(CPUPOWER cpupower)
if(NOT CPUPOWER)
    message(WARNING "No cpupower binary found!")
endif()
