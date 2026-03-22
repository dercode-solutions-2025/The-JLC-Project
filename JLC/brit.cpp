/*
Ported to C++ by dercode-solutions-2025
March 21, 2026
*/
// Removed <stdlib.h> because it wasn't being used.
#include <stdio.h>
#include <iostream>
#include <cstdlib>
int main(int argc, char** argv) {
    int c;
    FILE *f = fopen(argv[1], "w");
    if (argc < 2) {
        std::cout << "Usage: brit <file>" << "\n";
        return 1;
    }
    if (f == NULL) {
        perror("[ERROR]: File is empty.");
        std::exit(1);
        return 2;
    }
    // Essentially: While the next character isn't the End Of File (EOF), write the current character to the terminal.
    while ((c = fgetc(stdin)) != EOF) {
        fputc(c, stdout);
        fputc(c, f);
    }
    fclose(f);
    return 0;
}
