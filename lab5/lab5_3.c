#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h>    /*  This file is necessary 
for using shared memory constructs */ 
main() 
{ 
	int shmid, status, shmid2; 
        char *a, *b; 
		int *c, *d;
        int i; 
/*    The  operating  system  keeps  track  of  the  set  of 
shared  memory    segments.  In 
order to acquire shared memory, we must first reque
st the shared memory from the OS 
using  the  shmget()  system  call.  The  second  paramete
r  specifies  the  number  of  bytes  of 
memory requested. shmget() returns a shared memory 
 identifier (SHMID) which is an 
integer. Refer to the online man pages for details 
on the other two parameters of shmget() 
*/ 
 shmid = shmget(IPC_PRIVATE, 100*sizeof(char), 0777|IPC_CREAT); 
 shmid2 = shmget(IPC_PRIVATE, 1*sizeof(int), 0777|IPC_CREAT); 
                        /* We request an array of t
wo integers */ 
        /* 
After forking, the parent and child must "attach" t
he shared  memory to its local 
data segment. This is done by the shmat()  system c
all. shmat() takes the SHMID of the 
shared memory segment as input parameter and return
s the address at which  the 
segment has been attached. Thus shmat() returns a c
har  pointer.  */
if (fork() == 0) { 
                /* Child Process */ 
                /*  shmat() returns a char pointer 
which is typecast here  to int and the address 
is stored in the int pointer b. */ 
                b = (char *) shmat(shmid, 0, 0);
				c = (int *) shmat(shmid2, 0, 0);
				sleep(5);
				char *n;
				n = b;
				int a = *c;
				printf("Child\n");
                for( i=0; i < a; i++) 
                        if(b[i] <= 'z')
							printf("%c", (char)b[i] - 32);
						else 
							printf("%c", (char)b[i]);
						
				printf("\n");
             /* each process should "detach" itself
 from the  shared memory after it is used */ 
                shmdt(b); 
        } 
        else { 
                /* Parent Process */ 
                /*  shmat() returns a char pointer 
which is typecast here  to int and the address 
is stored in the int pointer a. Thus the memory loc
ations a[0] and a[1] of the parent  are 
the  same  as  the  memory  locations  b[0]  and  b[1]  of  t
he  parent,  since  the  memory  is 
shared. */ 		char str[100];
                a = (char *) shmat(shmid, 0, 0); 
				d = (int *) shmat(shmid2, 0, 0);
                printf("Enter a String\n");
				scanf("%s", str);
				*d =  strlen(str);
				printf("len %d \n", strlen(str));
				for( i=0; i < strlen(str); i++)
					a[i] = str[i];
                wait(&status);
              /* each process should "detach" itsel
f from the shared memory after it is used */ 
                shmdt(a); 
                /* Child has exited, so parent proc
ess should delete the cretaed shared memory. 
Unlike attach and detach,  which is to be done for 
each process separately,  deleting the 
shared  memory  has  to  be  done  by  only  one  process  af
ter  making  sure  that  noone  else 
will be using it  */ 
                shmctl(shmid, IPC_RMID, 0); 
        } 
} 