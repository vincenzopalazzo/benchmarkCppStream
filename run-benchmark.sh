#!/bin/bash
cmake CMakeList.txt -DCMAKE_BUILD_TYPE=Release -DBENCHMARK_ENABLE_LTO=true
make
./benchmarkCppStream --benchmark_out=res/result/i5-6300U@4x_3GH_gcc7.4.0.json