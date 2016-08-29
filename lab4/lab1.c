#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int n;

main() {
	char nChild;
	int p[2], i;
	
	pid_t pid;
	
	if(pipe(p) == -1) {
		perror("pipe call");
		exit(1);
	}
	
	pid = fork();
	
	if(pid == -1) {
		perror("Fork Failure");
		exit(2);
	}
	else if(pid == 0) {
		// child process
		close(p[1]);
		read(p[0], &nChild, sizeof(nChild));
		printf("Read from pipe complete\n");
		for(i=0;i<nChild;++i) 
			if(i % 2 != 0)
				printf("%d\n", i);
	}
	else {
		close(p[0]);
		printf("Enter a number\n");
		scanf("%d", &n);
		write(p[1], &n, sizeof(n));
		printf("Write to pipe done\n");
		close(p[1]);
	}
}