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

/**
 * Gets the path to the config file. If the env var SINKER_CONFIG_DIR is
 * set, returns that path + ".sinkerrc.json". Otherwise returns
 * $HOME/.sinkerrc.json.
 */
char* getConfigFilePath() {
    char* envp = getenv("SINKER_CONFIG_PATH");
    const char* CONFIG_FILE_NAME = ".sinkerrc.json";
    if (! envp) {
        char* path = getenv("HOME");
        sprintf(path, "%s/%s", getenv("HOME"), CONFIG_FILE_NAME);
        return path;
    }
    sprintf(envp, "%s/%s", envp, CONFIG_FILE_NAME);
    return envp;
}
int main() {
    char* path = getConfigFilePath();
    char* s = readFile(path);
    if (! s) {
        perror("Error opening sinker config file");
        exit(-1);
    }
    printf("%s", s);
    free(s);
    return 0;
}
