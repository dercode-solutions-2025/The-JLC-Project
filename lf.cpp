/*
Ported to C++ by dercode-solutions-2025
March 21, 2026
*/
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <iostream>

int main(int argc, char** argv) {
    struct dirent* de;
    DIR* dir;
    char** names = NULL;
    int count = 0;
   if (argc < 2) {
       dir = opendir (".");
   }
    else if (argc > 2) {
        fprintf(stderr, "Usage: lf [directory]\n");
        return 1;
    }
    else {
        dir = opendir(argv[1]);
    }
    if (dir == NULL) {
        perror("[ERROR]: Directory is empty.\n");
        std::exit(1);
        return 2;
    }
    while ((de = readdir(dir)) != NULL) {
        names = realloc(names, sizeof(char*) * (count + 1));
        names[count++] = strdup(de->d_name);
    }
    closedir(dir);
    for (int i = 0; i < count - 1; i++) {
       for (int j = 0; j < count - i - 1; j++) {
           if (strcmp(names[j], names[j + 1]) > 0) {
               char* tmp = names[j];
               names[j] = names[j + 1];
               names[j + 1] = tmp;
           }
       }
    }
    for (int i = 0; i < count; i++) {
        std::cout << names[i] << "\n";
        free(names[i]);
    }
    return 0;
}
