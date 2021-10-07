#include <stdio.h>
#include <stdlib.h>


char* readFile(char* path);
char* getConfigFilePath(void);

char* readFile(char* path) {
    FILE *f = fopen(path, "r");
    if (f == NULL) {
        return NULL;
    }
    fseek(f, 0, SEEK_END);

    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *string = malloc(fsize + 1);
    fread(string, 1, fsize, f);
    fclose(f);
    string[fsize] = 0;
    return string;
}

char* getConfigFilePath() {
    char* envp = getenv("SINKER_CONFIG_FILE");
    const char* CONFIG_FILE_NAME = ".sinkerrc.json";
    if (! envp) {
        char* path = getenv("HOME");
        sprintf(path, "%s/%s", getenv("HOME"), CONFIG_FILE_NAME);
        return path;
    }
    return envp;
    /* if (envp !=  NULL) { */
    /*     printf("%s", envp); */
    /*     printf("%lu", sizeof(envp)); */


}
int main() {
    printf("%s", getConfigFilePath());
    /* char* path = "/Users/acohen/.sinkerrc.json"; */
    /* char* s = readFile(path); */
    /* if (! s) { */
    /*     perror("Error opening sinker config file"); */
    /*     exit(-1); */
    /* } */
    /* printf("%s", s); */
    /* free(s); */
    return 0;
}
