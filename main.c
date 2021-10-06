#include <stdio.h>
#include <stdlib.h>


char* readFile(char* path);

char* readFile(char* path) {
    FILE *f = fopen(path, "r");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *string = malloc(fsize + 1);
    fread(string, 1, fsize, f);
    fclose(f);
    string[fsize] = 0;
    return string;
}

int main() {
    char* path = "/Users/acohen/.sinkerrc.json";
    char* s = readFile(path);
    printf("%s", s);
    free(s);
    return 0;
}