#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    char *str1 = "Hello, world!\n";
    char str2[15] = { 72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33, 10, 0 };
    printf("%s\n", str1);
    printf("%s\n", str2);
    exit(0);
}
