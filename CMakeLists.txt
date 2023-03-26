cmake_minimum_required(VERSION 3.25)
project(aos_vs_soa)

set(CMAKE_CXX_STANDARD 23)

find_package(benchmark CONFIG REQUIRED)

add_executable(aos_vs_soa main.cpp)
target_link_libraries(aos_vs_soa PRIVATE benchmark::benchmark benchmark::benchmark_main)
