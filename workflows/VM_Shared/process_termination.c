/*-----------------------------------------------------------
Student Name: Muhammad Fahad
Student Number: c00311349
Program: Demonstrating Process Destruction using kill commands
-----------------------------------------------------------*/

#include <stdio.h>      // For printf()
#include <stdlib.h>     // For exit()
#include <unistd.h>     // For fork(), getpid(), sleep()
#include <signal.h>     // For kill() and signal constants
#include <sys/wait.h>   // For wait()

int main() {
    pid_t pid = fork();  // Line 1: Create a new process using fork()

    if (pid < 0) {
        // Line 2: If fork fails
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Line 3: Child process
        printf("Child Process (PID: %d) started and running...\n", getpid());
        // Line 4: Infinite loop to simulate a long-running process
        while (1) {
            sleep(1);
        }
    }
    else {
        // Line 5: Parent process
        printf("Parent Process (PID: %d) created Child (PID: %d)\n", getpid(), pid);
        sleep(3);  // Line 6: Give child time to start

        printf("\nUsing 'kill PID' to terminate child gracefully (SIGTERM)...\n");
        kill(pid, SIGTERM);  // Line 7: Send graceful termination signal
        sleep(2);

        // Line 8: Check if child still alive
        if (waitpid(pid, NULL, WNOHANG) == 0) {
            printf("Child still running! Using 'kill -9 PID' to force terminate...\n");
            kill(pid, SIGKILL);  // Line 9: Send force kill signal
        }

        // Line 10: Wait for the child to terminate
        wait(NULL);
        printf("Child process terminated successfully.\n");
    }

    return 0;  // Line 11: End of program
}
