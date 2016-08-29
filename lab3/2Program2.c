#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
	int pid;
	printf("I am a process with pid %d\n", (int)getpid());
	pid = fork();
	printf("Fork Returned %d\n", pid);
	printf("I am a process with pid %d\n", (int)getpid());
}