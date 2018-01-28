#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#ifndef PWD_INIT_BUFSIZE
#define INIT_BUFSIZE 1024
#endif

char* pwd();

int main(int argc, char *argv[]) {
    char* wd = pwd();
    if (wd != NULL) {
        printf("%s\n", wd);
        exit(0);
    }
    exit(1);
}

char* pwd() {
    char *buf, *tmp;
    size_t size = INIT_BUFSIZE;

    buf = malloc(size);
    if (!buf) return NULL;

    for(;;) {
        errno = 0;
        if (getcwd(buf, size)) {
            return buf;
        }
        if (errno != ERANGE) break;

        size *= 2;
        tmp = realloc(buf, size);
        if (!tmp) break;
        buf = tmp;
    }
    free(buf);
    return NULL;
}
