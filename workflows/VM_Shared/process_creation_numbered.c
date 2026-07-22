 1   /*-----------------------------------------------------------
 2  Student Name: Muhammad Fahad
 3  Student Number: c00311349
 4  Program: Demonstrating Process Creation.
 5  -----------------------------------------------------------*/

 6  #include <stdio.h>        // Predefined library: for input/output functions
 7  #include <unistd.h>       // Predefined library: includes fork(), getpid(), execlp()
 8  #include <sys/wait.h>     // Predefined library: includes wait() for process sync.
 9
10  int main(){               // User-defined function: program execution starts here
11      pid_t pid;            // pid_t used to store process ID (unique identifier)
12      pid = fork();         // System call: creates a new child process
13
14      if(pid < 0){          // Condition: fork failed (negative value)
15          perror("fork failed");  // Displays error if process creation fails
16          return 1;
17      }
18      else if (pid == 0){   // Condition: executing inside the child process
19       printf("Child process created with PID %d\n", getpid());  // Display child PID
20      execlp("/bin/ls","ls", NULL);  // Replace child process image with 'ls' program
21      }
22      else {                // Condition: executing inside the parent process
23          printf("Parent process PID %d waiting for child....\n", getpid());
24          wait(NULL);       // Parent waits until the child process finishes execution
25          printf("Child finished execution. Parent exiting.\n");
26      }
27      return 0;             // Normal program termination
28  }

