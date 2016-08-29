#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char string[100];

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
		read(p[0], string, sizeof(string));
		printf("Read from pipe complete : Output : \n");
		for(i=0;i<sizeof(string);++i) {
			if(string[i] > 'a')
				printf("%c", string[i] - 32);
			else
				printf("%c", string[i]);
		}
		printf("\n");
	}
	else {
		close(p[0]);
		printf("Enter a String\n");
		scanf("%s", string);
		write(p[1], string, sizeof(string));
		printf("Write to pipe done\n");
		close(p[1]);
	}
}