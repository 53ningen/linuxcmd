#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stdout, "Usage: %s filename\n", argv[0]);
        exit(1);
    }
    if (unlink(argv[1]) < 0) {
        perror(argv[1]);
        exit(1);
    }
    exit(0);
}
