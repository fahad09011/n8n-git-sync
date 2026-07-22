     1	/*-----------------------------------------------------------
     2	Student Name: Muhammad Fahad
     3	Student Number: c00311349
     4	Program: Demonstrating Process Scheduling in Linux
     5	-----------------------------------------------------------*/
       
     6	#include <stdio.h>        	 // Predefined library: for input/output functions
     7	#include <unistd.h>       	 // Predefined library: includes fork(), getpid(), execlp()
     8	#include <stdlib.h>       	 // Predefined library:  for exit.
     9	#include <sys/wait.h>     	 // Predefined library: includes wait() for process sync.
       
    10	int main() {              	 // User-defined function: program execution starts here
    11		 pid_t pid;       	 // pid_t used to store process ID (unique identifier)
    12		pid = fork();     	 // System call: creates a new child process
    13	    if (pid == 0) {       	 // Condition: executing inside the child process
    14	        nice(-5);         	 // Set higher priority (lower nice value)
    15	        for(int i=0;i<5;i++){    // Loop to simulate repeated execution
    16	            printf("High-priority process running\n");      // display child process activity
    17	            sleep(1);            // Pause to allow scheduler switching
    18	        }                                                   
    19	    }
    20	                                                       
    21	    else {                       // Parent process section
    22	        nice(5);             	 // Set lower priority (higher nice value)
    23	        for(int i=0;i<5;i++){  	 // Loop to simulate repeated execution
    24	            printf("Low-priority process running\n");        //13  Show parent process activity
    25	            sleep(1);        	 // Pause to allow scheduler switching
    26	        }                                                   
    27	        wait(NULL);	      	 // Parent waits until the child process finishes execution
    28	    }                                                       
    29	    return 0;                    // Normal program termination
    30	}                                                           
