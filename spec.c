#include <stdio.h>
#include <string.h>
#define BUFSIZ 1024
int main(int argc, char** argv) {
   char buf[BUFSIZ];
   char buf2[BUFSIZ];
   if (argc < 2) {
      printf("Usage: spec filename\n");
      return 1;
   }
   FILE *f = fopen(argv[1], "r");
   if (f == NULL) {
      perror("FATAL ERROR");
      return 2;
   }
   while (fgets(buf, BUFSIZ, f) != NULL) {
      if (strcmp(buf, buf2) != 0) {
         printf("%s", buf);
      }
      memcpy(buf2, buf, BUFSIZ);
   }
   fclose(f);
   return 0;

}