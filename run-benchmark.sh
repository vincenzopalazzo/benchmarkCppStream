#!/bin/bash
cmake CMakeList.txt -DCMAKE_BUILD_TYPE=Release -DBENCHMARK_ENABLE_LTO=true
make
./benchmarkofstream_zlib --benchmark_out=res/result/benchmark_ofstream_zlib.json
./benchmarkofstream --benchmark_out=res/result/benchmark_ofstream.json
./benchmarkcfile_zlib --benchmark_out=res/result/benchmark_cfile_zlib.json
./benchmarkcfile --benchmark_out=res/result/benchmark_cfile.json