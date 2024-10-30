


#include <stdio.h>

#include "fork_demo.h"
#include "wait_basics.h"
#include "wait_example.h"
#include "waitpid_example.h"

#define DEMO_CHOICE 1

int main(){

	printf("\n Welcome to processes in C! \n");

	int demo_list_choice[] = {0, // fork_demo
		1, // wait_basics
		2, // wait example : a programming example
		3}; // wait for a specific process

	int demo_to_run = demo_list_choice[DEMO_CHOICE];

	switch (demo_to_run) {

		case 0:
			run_fork();
			break;

		case 1:
			run_wait_basics();
			break;

		case 2:
			run_wait();
			break;

		case 3:
			run_waitpid_example();
			break;

		default:
			break;

	} // End switch case



    return 0;




} // end main
