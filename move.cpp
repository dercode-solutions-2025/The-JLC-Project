/*
Ported to C++ by dercode-solutions-2025
March 21, 2026
*/
#include <stdio.h>
#include <iostream>
#include <cstdlib>
int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Usage: move <file> <destination>" << "\n";
        return 1;
    }
    if (rename(argv[1], argv[2]) != 0) {
        perror("[ERROR]: Could not move file.");
        std::exit(1);
        return 2;
    }
    return 0;
}
