/*-----------------------------------------------------------
Student Name: Muhammad Fahad
Student Number: c00311349
Program: Demonstrating Process Scheduling in Linux
-----------------------------------------------------------*/

#include <stdio.h>        	 // Predefined library: for input/output functions
#include <unistd.h>       	 // Predefined library: includes fork(), getpid(), execlp()
#include <stdlib.h>       	 // Predefined library:  for exit.
#include <sys/wait.h>     	 // Predefined library: includes wait() for process sync.

int main() {              	 // User-defined function: program execution starts here
	 pid_t pid;       	 // pid_t used to store process ID (unique identifier)
	pid = fork();     	 // System call: creates a new child process
    if (pid == 0) {       	 // Condition: executing inside the child process
        nice(-5);         	 // Set higher priority (lower nice value)
        for(int i=0;i<5;i++){    // Loop to simulate repeated execution
            printf("High-priority process running\n");      // display child process activity
            sleep(1);            // Pause to allow scheduler switching
        }                                                   
    }
                                                       
    else {                       // Parent process section
        nice(5);             	 // Set lower priority (higher nice value)
        for(int i=0;i<5;i++){  	 // Loop to simulate repeated execution
            printf("Low-priority process running\n");        //13  Show parent process activity
            sleep(1);        	 // Pause to allow scheduler switching
        }                                                   
        wait(NULL);	      	 // Parent waits until the child process finishes execution
    }                                                       
    return 0;                    // Normal program termination
}                                                           
