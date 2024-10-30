



/*
 * Task: write a program that print from 1 ->10 (1 by 1)
 *
 * From 1->5, it should be print by the child process
 *
 * From 6->10; it should be print by the main process
 *
 * */


#include "wait_example.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>



void run_wait(void){

	printf("\n \t -> Starting wait demo \n \n");

	// creating a child process.

	pid_t id = fork();

	// it is necessary to declare the variable n here
	// so it can be common and used by the 2 processes (parent and the child)
	int n;


	if(id == 0){
		// here we are in the child
		n = 1;

	}else{
		// since we have only 1 fork() -> so in total we have 2 process
		// here we are in the main process
		n = 6;
	}

	if(id != 0){
		// id not 0 -> definitely not a child process
		// here we are in the parent process

		wait(NULL); // ->

		/*
		 * -we are waiting for the child process to finish its execution
		 * - we use NULL as argument because I am not interested by the status of
		 *   the child process when it is finished
		 *
		 * -wait() also the pid of the child process we are waiting for
		 *
		 * - if there is no child process to wait for, wait() returns -1
		 *
		 * */

	}

	for(int i = n; i< n+5 ; i++){

		printf("%d",i);

	} // End for

	if(id != 0){
		printf("\n");

		// we let a blank line only once
		// this why we write it in the parent process
		// Also the child will print the upper part

	}


} // End run_wait()
