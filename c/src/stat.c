#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

static char *filetype(mode_t mode);

int main(int argc, char *argv[])
{
    struct stat st;

    if (argc != 2) {
        fprintf(stdout, "Usage: %s filename\n", argv[0]);
        exit(1);
    }
    if (lstat(argv[1], &st) < 0) {
        perror(argv[1]);
        exit(1);
    }
    printf("type:\t%o (%s)\n", (st.st_mode & S_IFMT) ,filetype(st.st_mode));
    exit(0);
}

static char *filetype(mode_t mode) {
    if (S_ISREG(mode)) return "file";
    if (S_ISDIR(mode)) return "directory";
    if (S_ISCHR(mode)) return "chardev";
    if (S_ISBLK(mode)) return "blocdev";
    if (S_ISFIFO(mode)) return "fifo";
    if (S_ISLNK(mode)) return "symlink";
    if (S_ISSOCK(mode)) return "socket";
    return "unknown";
}
