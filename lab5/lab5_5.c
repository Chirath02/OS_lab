#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <string.h>

main() { 
	int shmid, status; 
	char *a, *b, *c, l1, l2; 
	int i; 
	shmid = shmget(IPC_PRIVATE, 100*sizeof(char), 0777|IPC_CREAT); 
	
	if (fork() == 0) { 
		b = (char *) shmat(shmid, 0, 0); 
		
		printf("Process 1 writes 1\n");
		b[0] = '1'; 
		
		sleep(7);
		printf("Process 1 prints : ");
		for(i=1 ; i < l1+l2 ; i++) {
			if (b[i]>= 97 && b[i]<=122)
				printf("%c",b[i]-32);
			else
				printf("%c",b[i]);
		}
		printf("\n");
		shmdt(b); 
	} 
	else { 
		
		if (fork() == 0) {
			a = (char *) shmat(shmid, 0, 0); 
			char str[100];
			sleep(1);
			scanf("%s", str);
			a[0] = 2;
			l1 = strlen(str);
			printf("\n Process 2 writes : %s", str);
			for(i=0; i< l1;++i)
				a[i+1] = str[i];
			wait(&status); 
			shmdt(a); 
			shmctl(shmid, IPC_RMID, 0); 
		}
		else {
			c = (char *) shmat(shmid, 0, 0); 
			char str[100];
			sleep(4);
			scanf("%s", str);
			l2 = strlen(str);
			printf("\n Process 3 writes : %s", str);
			for(i=0; i< l2;++i)
				a[i] = str[i];
			wait(&status); 
			shmdt(a); 
			shmctl(shmid, IPC_RMID, 0); 
		}
		
	} 
} 