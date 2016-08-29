#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
	int childpid;
	int count1=0, count2=0;
	printf("Before it forks!\n");
	childpid = fork();
	if(childpid == 0) {
		printf("This is a child process with pid %d\n", (int)getpid());
		while(count1 < 10) {
			printf("Child Process: %d\n", count1);
			sleep(1);
			count1++;
		}
	}
	else {
		printf("This is a parent process with pid %d\n", (int)getpid());
		while(count2 <20) {
			printf("Child Process: %d\n", count2);
			sleep(1);
			count2++;
		}
	}
}