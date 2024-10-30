/*
 * fork_demo.c
 *
 *  Created on: Aug 21, 2024
 *      Author: ranimtom
 */



#include "fork_demo.h"

#include <stdio.h>
#include <sys/types.h> // for pid_t type
#include <unistd.h> // to use fork()
#include <stdlib.h>

void run_fork(void){


	pid_t id;

	printf("Parent Process : Executed by parent process before fork() - "
		"PID = (%d)\n",getpid());

	// Before fork(), we have 1 virtual memory
	// After fork(), we will have 2 virtual memory

 	id = fork();  // from this point of code, the child and parent process both execute
 	// In the parent process: we have some int number
 	// In the child process: id = 0 in case of success


    if (id < 0 ){

    	printf("\n fork failed\n");
        exit(-1);
    }

    if(id > 0){

    	printf("\n -> We are in the parent section of the memory \n");

    	// this block of code will apply in the parent case
    	printf("\n \t - Parent Process: I have created child process with ID = (%d)\n",id);

    	printf("\n \t - getpid() return value = (%d)\n",getpid());
    	/*It should give the same number before the fork()*/



    }else{

    	// here in this case id = 0 ->  we are in child memory section

    	printf("\n -> I am child process, id value return by fork() (%d)\n",id);
    	// -> id = 0

    	printf("\n -> child process id is (%d)\n",getpid());
    	// here we have an id = some number in the memory of the parent process

    	printf("\n ->The creator of child process is (%d)\n",getppid());
    	// we will have the ide of the parent process
    	// notice that we have use the function getppid(), that is for the parent

    }



} // End run_fork()
