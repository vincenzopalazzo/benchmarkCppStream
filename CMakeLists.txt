cmake_minimum_required(VERSION 3.9)
project(benchmarkCppStream)

set(CMAKE_CXX_STANDARD 11)

find_package(ZLIB)
#GoogleBenchmark
find_package(benchmark)

find_package (Threads REQUIRED)

add_executable(benchmarkofstream_zlib
        src/benchmark_ofstream_zlib.cpp
        src/zlibutil.cpp)

add_executable(benchmarkofstream
        src/benchmark_ofstream.cpp)

add_executable(benchmarkcfile_zlib
        src/benchmark_cfile_zlib.cpp)
       

add_executable(benchmarkcfile
        src/benchmark_cfile.cpp)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/zlibutil.cpp)

target_link_libraries(benchmarkofstream_zlib  ${ZLIB_LIBRARIES})
target_link_libraries(benchmarkofstream_zlib benchmark)
target_link_libraries(benchmarkofstream_zlib ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries(benchmarkofstream benchmark)
target_link_libraries(benchmarkofstream ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries(benchmarkcfile benchmark)
target_link_libraries(benchmarkcfile ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries(benchmarkcfile_zlib  ${ZLIB_LIBRARIES})
target_link_libraries(benchmarkcfile_zlib benchmark)
target_link_libraries(benchmarkcfile_zlib ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries(${PROJECT_NAME}  ${ZLIB_LIBRARIES})
