#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main() {
	int pid;
	
	if((pid = fork()) < 0)
		exit(1);
	
	if(pid == 0) {
		printf("Valuer of pid: %d\n", pid);
		execlp("/bin/ls", "ls", NULL);
		exit(1);
	}
}