// process | brust time | arrival time | priority
/*

 2 9 2 0
 5 9 2 0
 3 3 3 0
 1 1 4 0
 4 4 9 0
 
 */
#include<iostream>

using namespace std;

class Process {
public:
	int burst_time;
	int arrival_time;
	int priority;
	int p_no;
};

int n;
int time_slice;

void sort_on_arrival(Process p[]) {
	Process t;
	for(int i=0; i<n;++i) {
		for(int j=0;j<n-i-1;++j) {
			if(p[j].arrival_time > p[j+1].arrival_time) {
				t = p[j];
				p[j] = p[j+1];
				p[j+1] = t;
			}
		}
	}
}

void print(Process p[]) {
	cout << "process\t|\tburst time\t|\tarrival time\t|\tpriority\n";
	for(int i=0; i<n;++i)
		cout << "p" << p[i].p_no << "\t|\t\t" << p[i].burst_time << "\t|\t\t" << p[i].arrival_time << "\t|\t\t" <<p[i].priority << "\n";
}

void input(Process p[]) {
	cout << "Enter no of processes :";
	cin >> n;
	cout << "Enter process number, Burst time, Arrival time and Priority of processes \n";
	for(int i=0; i<n; ++i) {
		cin >> p[i].p_no >> p[i].burst_time >> p[i].arrival_time >> p[i].priority;
	}
	cout << "Enter time slice :";
	cin >> time_slice;
}

void sjf(Process p[]) {
	
}

void premptive_sjf(Process p[]) {
	
}

void round_robin(Process p[]) {
	int temp=0, i=0;
	while(1) {
		if(p[i].burst_time>0 && p[i].arrival_time >= i) {
			cout << "P" << p[i].p_no << " ";
			p[i].burst_time -= time_slice;
		    if(p[i].burst_time <= 0)
				temp++;
			
		}
		i++;
		if(temp==n-1)
			break;
		
		if(i == n)
			i=0;
		
		
	}
}

int main() {
	Process p[100];
	input(p);
	sort_on_arrival(p);
	print(p);
	int c=0;
	while(c!=4) {
		cout << "\nEnter 1 for SJF\n";
		cout << "Enter 2 for premptive sjf\n";
		cout << "Enter 3 for Round robin\n";
		cout << "Enter 4 to exit\n->";
		cin >> c;
		switch(c) {
			case 1: sjf(p);
			break;
			case 2: premptive_sjf(p);
			break;
			case 3: round_robin(p);
			break;
			case 4: break;
		}
	}
}