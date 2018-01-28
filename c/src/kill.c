#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    int pid;

    if (argc != 2) {
        fprintf(stdout, "Usage: %s <pid>\n", argv[0]);
        exit(1);
    }

    pid = atoi(argv[1]);
    if (kill(pid, SIGKILL) < 0) {
        perror(argv[1]);
        exit(1);
    }
    exit(0);
}
