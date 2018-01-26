#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>

static void get_branch(char *buf, int depth);
static void do_tree(char *path, int depth);

int main(int argc, char *argv[]) {
    int i;

    if (argc < 2) {
        do_tree(".", 0);
        exit(0);
    }
    for(i = 1; i < argc; i++) {
        do_tree(argv[i], 0);
    }
    exit(0);
}

static void get_branch(char *buf, int depth) {
    int i;

    sprintf(buf, "%s", "");
    for (i = 0; i < depth; i++) {
        sprintf(buf, "%s%s", buf, "    ");
    }
    sprintf(buf, "%s%s", buf, "├── ");
}

static void do_tree(char *path, int depth) {
    DIR *d;
    struct dirent *ent;
    char cd[1024];
    char branch[8 * depth + 1];
    get_branch(branch, depth);

    d = opendir(path);
    if (!d) {
        perror(path);
        exit(1);
    }
    while ((ent = readdir(d))) {
        if (!strcmp("..",ent->d_name) || !strcmp(".",ent->d_name)) continue;

        printf("%s%s\n", branch, ent->d_name);
        if (ent->d_type == DT_DIR) {
            sprintf(cd, "%s/%s", path, ent->d_name);
            do_tree(cd, depth + 1);
        }
    }
    closedir(d);
}
