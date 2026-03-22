/*
Ported to C++ by dercode-solutions-2025
March 21, 2026
*/
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#define BUFFSIZE 1024
int main(int argc, char** argv) {
    if (argc > 2) {
        std::cout << "Usage: hn\n" << "\n";
        std::cout << "Usage: hn <name>\n" << "\n";
        return 1;
    }
    char buf[BUFFSIZE];
    FILE *f = NULL;
    if (argc == 2) {
        f = fopen("/etc/hostname", "r");
        if (f == NULL) {
            perror("[ERROR]: There was a problem opening the hostname.");
            std::exit(1);
            return 2;
        }
        while (fgets(buf, BUFFSIZE, f) != NULL) {
            std::cout << buf << "\n";
        }
        fclose(f);
        return 0;
    }
    f = fopen("/etc/hostname", "w");
    if (f == NULL) {
        perror("[ERROR]: There was a problem opening the hostname.");
        std::exit(1);
        return 2;
    }
    fprintf(f, "%s", argv[1]);
    fclose(f);
    return 0;
}
