     1	/*-----------------------------------------------------------
     2	Student Name: Muhammad Fahad
     3	Student Number: c00311349
     4	Program: Demonstrating Process Destruction using kill commands
     5	-----------------------------------------------------------*/
     6	#include <stdio.h>      // Predefined library: for input/output functions
     7	#include <stdlib.h>     // Predefined library: for exit.
     8	#include <unistd.h>     // Predefined library: include fork(), getpid(), sleep()
     9	#include <signal.h>     // Predefined library:  For kill() and signal constants
    10	#include <sys/wait.h>   // Predefined library: includes wait() for process sync
    11	int main() { 		//User-defined function: program execution starts here
    12	    pid_t  pid;		//pid_t to store process ID   
    13  	   pid = fork();	//System call: creates anew child process
    14	    if (pid < 0) {	// Condition: fork failed (negative value)
    15	        perror("Fork failed");
    16	        exit(1);
    17	    }
    18	    else if (pid == 0) {// Condition: executing inside the child process
    19	        // Child process
    20	        printf("Child Process (PID: %d) started and running...\n", getpid());
    21	        // Infinite loop to simulate a long-running process
    22	        while (1) {
    23	            sleep(1);
    24	        }
    25	    }
    26	    else {
    27	        // Parent process
    28	        printf("Parent Process (PID: %d) created Child (PID: %d)\n", getpid(), pid);
    29	        sleep(3);  // Give child time to start
    30	        printf("\nUsing 'kill PID' to terminate child gracefully (SIGTERM)...\n");
    31	        kill(pid, SIGTERM);  // Send graceful termination signal
    32	        sleep(2);
    33	        // Check if child still alive
    34	        if (waitpid(pid, NULL, WNOHANG) == 0) { 
    35	            printf("Child still running! Using 'kill -9 PID' to force terminate...\n");
    36	            kill(pid, SIGKILL);  // Send force kill signal
    37	        wait(NULL); // Parent waits until the child process finishes execution
    38	        printf("Child process terminated successfully.\n");
    39	    } 
    40	    return 0;  // Normal program termination
    41	}
