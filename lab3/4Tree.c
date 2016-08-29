#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
	int parentpid = (int)getpid();
	int p1pid, p2pid, p3pid, p4pid, p5pid, p6pid;

	p1pid = fork(); // P1
	
	if(p1pid < 0)
		perror("Fork failed\n");
	
	
	if(p1pid == 0) { //P1
		printf("P1 = %d\n", (int)getpid());
		printf("A\n");
		
		p2pid = fork(); //p2
		
		if(p2pid == 0) { 
		    printf("P2 = %d\n", (int)getpid());
		    printf("B\n");
		    p4pid = fork();  //p4
		    if(p4pid == 0) {
		      printf("P4 = %d\n", (int)getpid());
		      printf("D\n");
		    }
		}
		else {
		   p3pid = fork(); //p3
		   if(p3pid > 0) {
		      p5pid = fork();
		      if(p5pid>0) {
			p6pid = fork();
			if(p5pid == 0) {
			  printf("P6 = %d\n", (int)getpid());
			  printf("F\n");
			}
		      }
		      else {
			printf("P5 = %d\n", (int)getpid());
			printf("E\n");
		      }
		  }
		  else {
		    printf("P3 = %d\n", (int)getpid());
		    printf("C\n");
		  }
		}

	}

}
