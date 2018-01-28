/*

$ kill -l
HUP INT QUIT ILL TRAP ABRT EMT FPE KILL BUS SEGV SYS PIPE ALRM TERM URG STOP TSTP CONT CHLD TTIN TTOU IO XCPU XFSZ VTALRM PROF WINCH INFO USR1 USR2

$ ./bin/trap

$ ps aux | grep ./bin/trap
gomi_ningen      24008   0.0  0.0  2451236   2000 s002  S+   10:05PM   0:00.00 grep ./bin/trap
gomi_ningen      23986   0.0  0.0  2432780   1648 s008  S+   10:04PM   0:00.00 ./bin/trap

$ kill INT 23986
$ kill INT 23986
$ kill INT 23986
$ kill TERM 23986

# got
^CGot signal 2
^CGot signal 2
^CGot signal 2
 Got signal 15

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef void (*sighandler_t)(int);
static sighandler_t trap_signal(int sig, sighandler_t handler);
static void print(int sig);
static void print_exit(int sig);

int main(int argc, char *argv[])
{
    trap_signal(SIGINT, print);
    trap_signal(SIGTERM, print_exit);

    while (1) {
        pause();
    }
    exit(0);
}

static sighandler_t trap_signal(int sig, sighandler_t handler) {
    struct sigaction act;
    struct sigaction old;

    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_RESTART;
    return sigaction(sig, &act, &old) < 0 ? NULL : old.sa_handler;
}

static void print(int sig) {
    printf("Got signal %d\n", sig);
}

static void print_exit(int sig) {
    printf("Got signal %d\n", sig);
    exit(0);
}
