/*
Ported to C++ by dercode-solutions-2025
March 21, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#define BUFFSIZE 1024
int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Usage: cpy <source> <destination>" << "\n";
        return 1;
    }
    FILE *source = fopen(argv[1], "rb");
    FILE *destination = fopen(argv[2], "wb");
    if (source == NULL) {
        perror("[ERROR]: Source does not exist.\n");
        std::exit(1);
        return 2;
    }
    if (destination == NULL) {
        perror("[ERROR]: Destination does not exist.\n");
        std::exit(1);
        return 2;
    }
    char buff[BUFFSIZE];
    while (fread(buff, 1, BUFFSIZE, source) > 0) {
        if (fwrite(buff, 1, BUFFSIZE, destination) < 0) {
            perror("[ERROR]: fwrite() failed.\n");
            std::exit(1);
            return 3;
        }
    }
    fclose(source);
    fclose(destination);
    return 0;
}
