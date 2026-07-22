 #include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
pid_t pid;
pid = fork();
if(pid < 0){
perror("fork failed");
return 1;
}
else if (pid == 0){
printf("child process created with PID %d\n", getpid());
execlp("/bin/ls","ls", NULL);
}
else {
printf("Parent process PID %d waiting for child....\n", getpid());
wait(NULL);
printf("Child finished execution. Parent exiting. \n");
}
return 0 ;
}

