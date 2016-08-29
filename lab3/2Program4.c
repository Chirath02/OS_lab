#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
	int pid;
	printf("I am a process with pid %d\n", (int)getpid());
	pid = fork();
	if(pid < 0)
		perror("Fork failed\n");
	if(pid == 0) {
		printf("I am a process with pid %d\n", (int)getpid());
		exit(0);
	}
	printf("I am a process with pid %d\n", (int)getpid());
}