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
    if (argc != 2) {
        std::cout << "Usage: mat <file>" << "\n";
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror("[ERROR]: File is empty.");
        std::exit(1);
        return 2;
    }
    char buff[BUFFSIZE];
    while (fgets(buff, BUFFSIZE, f) != NULL) {
        std::cout << buff << "\n";
    }
    fclose(f);
    return 0;
}
