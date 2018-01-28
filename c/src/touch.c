#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <utime.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stdout, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    if (utime(argv[1], NULL) < 0) {
        perror(argv[1]);
        exit(1);
    }
    exit(0);
}
