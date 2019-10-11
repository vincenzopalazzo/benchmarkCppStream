//
// Created by https://github.com/vincenzopalazzo on 10/11/19.
//
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "zlib.h"

#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
#  include <fcntl.h>
#  include <io.h>
#  define SET_BINARY_MODE(file) setmode(fileno(file), O_BINARY)
#else
#  define SET_BINARY_MODE(file)
#endif

#define CHUNK 16384

const std::string ROW_GRAPH_SPYCBLOCK = "Coinbase|5000000000|4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b|1231006505|1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa";

void saveFileWithZLib();

void saveFileWithOfstream();

void decompressFileWithZLib();

int main(int argc, char *argv[])
{
    saveFileWithZLib();
    printf("\n----- FINISH WRITE WITH ZLIB -----\n\n");

    saveFileWithOfstream();
    printf("\n----- FINISH WRITE WITH OFSTREAM -----\n\n");


    //printf("\n--------- DECOMPRESS AND READ THE FILE WITH ZLIB ---------");
    //decompressFileWithZLib();

}

void saveFileWithZLib()
{
    gzFile gzFile;
    gzFile = gzopen("res/fzFile.dat", "wb");
    long sizeData = sizeof(char) * ROW_GRAPH_SPYCBLOCK.size();
    for (int i = 0; i < 90000; i++) {
        gzwrite(gzFile, ROW_GRAPH_SPYCBLOCK.data(), sizeData);
    }
    gzclose(gzFile);
}

void saveFileWithOfstream()
{
    std::ofstream ofstream("res/ofstreamFile.tx");
    for (int i = 0; i < 90000; i++) {
        ofstream << ROW_GRAPH_SPYCBLOCK;
    }
    ofstream.close();
}

void decompressFileWithZLib()
{
    std::string filename = "res/fzFile.dat";
    gzFile inFileZ = gzopen("res/fzFile.dat", "rb");

    if (inFileZ == NULL) {
        printf("Error: Failed to gzopen %s\n", filename.c_str());
        exit(0);
    }
    unsigned char unzipBuffer[8192];
    unsigned int unzippedBytes;
    std::vector<unsigned char> unzippedData;
    while (true)
    {
        unzippedBytes = gzread(inFileZ, unzipBuffer, 8192);
        if (unzippedBytes > 0) {
            unzippedData.insert(unzippedData.end(), unzipBuffer, unzipBuffer + unzippedBytes);
        } else {
            break;
        }
    }

    for (auto character : unzippedData)
    {
        std::cout << character;

    }
}