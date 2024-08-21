


#include <stdio.h>

#include "fork_demo.h"

#define DEMO_CHOICE 0

int main(){

	printf("\n Welcome to processes in C! \n");

	int demo_list_choice[] = {0, // fork_demo
		1,
		2,
		3};

	int demo_to_run = demo_list_choice[DEMO_CHOICE];

	switch (demo_to_run) {

		case 0:
			run_fork();
			break;

		default:
			break;

	} // End switch case



    return 0;




} // end main
