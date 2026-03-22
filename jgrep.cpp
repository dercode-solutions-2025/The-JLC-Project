/*
Ported to C++ by dercode-solutions-2025
March 21, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#define BUFFSIZE 1024
int main(int argc, char** argv) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: jgrep <pattern> <file>\n");
        return 2;
    }
    FILE* file;
    if (argc == 3) {
        file = fopen(argv[2], "r");
        if (file == NULL) {
            perror("[ERROR]: File is empty.\n");
            std::exit(1);
            return 3;
        }
    } else {
        file = stdin;
    }
    size_t capacity = BUFFSIZE;
    char* buf = malloc(capacity);
    int found = 0;
    for (;;) {
        size_t len = 0;
        int got_line = 0;

        for (;;) {
            if (fgets(buf + len, capacity - len, file) == NULL) {
                got_line = (len > 0);
                break;
            }
            len = strlen(buf);
            if (buf[len - 1] == '\n') { got_line = 1; break; }

            capacity *= 2;
            char *tmp = realloc(buf, capacity);
            if (tmp == NULL) { perror("realloc"); free(buf); return 4; }
            buf = tmp;
        }

        if (!got_line) break;

        if (strstr(buf, argv[1]) != NULL) {
            std::cout << buf << "\n";
            found = 1;
        }
    }
    if (buf == NULL) {
        perror("[ERROR]: Buffer = Null!");
        std::exit(1);
        return 1;
    }
    if (!found) {
        printf("[ERROR]: Not found!\n");
    }
    free(buf);
    if (argc == 3) {
        fclose(file);
    }
    return 0;
}
