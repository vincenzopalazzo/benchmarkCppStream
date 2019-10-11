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

void saveFileWithZLib(int iteration);
void saveFileWithOfstreamZLib(int iteration);
void saveFileWithOFStrem(int iteration);
void saveCFile(int iteration);


//BM
void BM_ZLIB100(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithZLib(100);
    }
}

void BM_ZLIB1000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithZLib(1000);
    }
}

void BM_ZLIB10000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithZLib(10000);
    }
}

void BM_OFSTREAMZLIB100(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOfstreamZLib(100);
    }
}

void BM_OFSTREAMZLIB1000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOfstreamZLib(1000);
    }
}

void BM_OFSTREAMZLIB10000(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOfstreamZLib(10000);
    }
}

BENCHMARK(BM_ZLIB100)->Arg(8);
BENCHMARK(BM_ZLIB1000)->Arg(8);
BENCHMARK(BM_ZLIB10000)->Arg(8);
BENCHMARK(BM_OFSTREAMZLIB100)->Arg(8);
BENCHMARK(BM_OFSTREAMZLIB1000)->Arg(8);
BENCHMARK(BM_OFSTREAMZLIB10000)->Arg(8);

//No Compression
void BM_C_STREAM100(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveCFile(100);
    }
}

void BM_OFSTREAM(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        saveFileWithOFStrem(100);
    }
}

BENCHMARK(BM_C_STREAM100)->Arg(8);
BENCHMARK(BM_OFSTREAM)->Arg(8);

//Method for benchmark
void saveFileWithZLib(int iteration) {
    gzFile gzFile;
    gzFile = gzopen("res/fzFile.dat", "wb");
    long sizeData = sizeof(char) * ROW_GRAPH_SPYCBLOCK.size();
    for (int i = 0; i < 90000; i++) {
        gzwrite(gzFile, ROW_GRAPH_SPYCBLOCK.data(), sizeData);
    }
    gzclose(gzFile);
}

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

//Not compression
void saveFileWithOFStrem(int iteration)
{
    std::ofstream ofstream("res/ofstreaNoZLib.txt");
    for (int i = 0; i < 90000; i++) {
        ofstream << ROW_GRAPH_SPYCBLOCK;
    }
    ofstream.close();
}

void saveCFile(int iteration)
{
    FILE *fptr = fopen("res/cfilestream.txt","w");
    for (int i = 0; i < 90000; i++) {
        fprintf(fptr, ROW_GRAPH_SPYCBLOCK.c_str());
    }
    fclose(fptr);
}

BENCHMARK_MAIN();
