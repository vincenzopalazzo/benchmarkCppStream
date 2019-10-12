//
// Created by https://github.com/vincenzopalazzo on 10/11/19.
//
#include <iostream>
#include <fstream>


#include <zlib.h>
#include <benchmark/benchmark.h>
#include <cstring>

#include "zlibutil.hpp"

using namespace ZLibUtil;

std::string ROW_GRAPH_SPYCBLOCK = "Coinbase|5000000000|4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b|1231006505|1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa";

void saveFileWithOfstreamZLib(int iteration);

void BM_100(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOfstreamZLib(100);
    }
}

void BM_1000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOfstreamZLib(1000);
    }
}

void BM_10000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOfstreamZLib(10000);
    }
}

void BM_100000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOfstreamZLib(100000);
    }
}

void BM_1000000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOfstreamZLib(100000);
    }
}

void BM_10000000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOfstreamZLib(1000000);
    }
}

void BM_100000000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOfstreamZLib(10000000);
    }
}

BENCHMARK(BM_100)->Arg(8);
BENCHMARK(BM_1000)->Arg(8);
BENCHMARK(BM_10000)->Arg(8);
BENCHMARK(BM_100000)->Arg(8);
BENCHMARK(BM_1000000)->Arg(8);
BENCHMARK(BM_10000000)->Arg(8);
BENCHMARK(BM_100000000)->Arg(8);

void saveFileWithOfstreamZLib(int iteration)
{   
    ZlibUtil zlibUtli;
    std::ofstream ofstream("res/ofstreamFile.dat");
    for (int i = 0; i < 90000; i++) {
        std::string tmp = zlibUtli.compressString(ROW_GRAPH_SPYCBLOCK.c_str(), ZlibUtil::BEST_COMPRESSIOn);
        ofstream << tmp;
    }
    ofstream.close();
}

BENCHMARK_MAIN();
