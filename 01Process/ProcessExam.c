#include <stdio.h>
#include <sys/types.h>//for fork()
#include <unistd.h> //for fork()
#include <stdlib.h>
#include <errno.h>
#include <time.h> //for time(),ctime()
#include <wait.h>//for wait()
#define FORKNUM 10 // child process number


int main(){
	

	pid_t pid, pids,childpid;
	int runProcess;  
	int count; 
	int childstatus;
	time_t nowtime; // store time data

	time(&nowtime);
	pid = getpid(); // insert parent process's PID 
	for( runProcess =0; runProcess<FORKNUM; runProcess++){ //make 5 child process
		if(pid==getpid()) // block child process makes child process
			pids= fork(); // make child process
	}
	
	if(pids==0){ // child process code

	for(count = 1; count<101;count++){
	printf("[PID = %d , Count =#%3d , PPID= %d] datetime = %s",getpid(),count,getppid(),ctime(&nowtime));
	}
			
	}
	else if (pids<0) return -1; //if fork fail return -1;
	
	for(runProcess=0;runProcess<FORKNUM;runProcess++){ 
	
		if(pids>0){	 // parent process code
			
			childpid=wait(&childstatus);// waiting until child process finished and return child porcess's pid at childpid
			
			printf("Child has finished: PID = %d\n",childpid);
			}
		
	
	}
		
		

	

	return 0;
}

