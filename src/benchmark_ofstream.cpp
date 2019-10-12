//
// Created by https://github.com/vincenzopalazzo on 10/11/19.
//
#include <iostream>
#include <fstream>

#include <benchmark/benchmark.h>
#include <cstring>

std::string ROW_GRAPH_SPYCBLOCK = "Coinbase|5000000000|4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b|1231006505|1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa";

void saveFileWithOFStrem(int iteration);

void BM_100(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOFStrem(100);
    }
}

void BM_1000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOFStrem(1000);
    }
}

void BM_10000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOFStrem(10000);
    }
}

void BM_100000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOFStrem(100000);
    }
}

void BM_1000000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOFStrem(100000);
    }
}

void BM_10000000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOFStrem(1000000);
    }
}

void BM_100000000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOFStrem(10000000);
    }
}

BENCHMARK(BM_100)->Arg(8);
BENCHMARK(BM_1000)->Arg(8);
BENCHMARK(BM_10000)->Arg(8);
BENCHMARK(BM_100000)->Arg(8);
BENCHMARK(BM_1000000)->Arg(8);
BENCHMARK(BM_10000000)->Arg(8);
BENCHMARK(BM_100000000)->Arg(8);

void saveFileWithOFStrem(int iteration)
{
    std::ofstream ofstream("res/ofstreaNoZLib.txt");
    for (int i = 0; i < 90000; i++) {
        ofstream << ROW_GRAPH_SPYCBLOCK;
    }
    ofstream.close();
}

BENCHMARK_MAIN();
