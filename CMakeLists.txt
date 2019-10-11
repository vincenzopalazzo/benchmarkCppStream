cmake_minimum_required(VERSION 3.9)
project(benchmarkCppStream)

set(CMAKE_CXX_STANDARD 11)

find_package(ZLIB)
#GoogleBenchmark
find_package(benchmark)

find_package (Threads REQUIRED)

add_executable(${PROJECT_NAME}
        src/benchmark.cpp
        src/zlibutil.cpp)

add_executable(noBenchmark
        src/main.cpp
        src/zlibutil.cpp)

target_link_libraries(${PROJECT_NAME}  ${ZLIB_LIBRARIES})
target_link_libraries(${PROJECT_NAME} benchmark)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries(noBenchmark  ${ZLIB_LIBRARIES})
