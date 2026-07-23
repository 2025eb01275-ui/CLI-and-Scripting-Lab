#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0) {
        printf("Child process started. PID = %d\n", getpid());
        sleep(10);
        printf("Child process completed.\n");
        exit(0);
    } else {
        printf("Parent process monitoring child...\n");

        sleep(3);

        printf("Terminating child process...\n");
        kill(pid, SIGTERM);

        wait(NULL);

        printf("Zombie process prevented.\n");
        printf("Parent process exiting.\n");
    }

    return 0;
}
