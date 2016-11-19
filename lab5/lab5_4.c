#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 

main() { 
	int shmid, status; 
	char *a, *b; 
	int i; 
	shmid = shmget(IPC_PRIVATE, 100*sizeof(char), 0777|IPC_CREAT); 
	
	if (fork() == 0) { 
		sleep(5);
		b = (char *) shmat(shmid, 0, 0); 
		printf("Child prints : ");
		for(i=0 ; i < 100 ; i++) {
			if (b[i]>= 97 && b[i]<=122)
				printf("%c",b[i]-32);
			else
				printf("%c",b[i]);
		}
		printf("\n");
		shmdt(b); 
	} 
	else { 
		a = (char *) shmat(shmid, 0, 0); 
		printf("\nText parent sents sents : ");
		scanf("%s", a);
		wait(&status); 
		shmdt(a); 
		shmctl(shmid, IPC_RMID, 0); 
	} 
} 