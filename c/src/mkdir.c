#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void do_mkdir(char *dir);

int main(int argc, char *argv[]) {
    int i;

    if (argc < 2) {
        printf("%s", "usage: mkdir directory ...");
        exit(0);
    }
    for(i = 1; i < argc; i++) {
        do_mkdir(argv[i]);
    }
    exit(0);
}

void do_mkdir(char *dir) {
    if (mkdir(dir, 0777) < 0) {
        perror(dir);
        exit(1);
    }
}
