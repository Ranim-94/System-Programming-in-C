

#include <stdio.h>
#include "open_demo.h"
#include "read_demo.h"

#define DEMO_CHOICE 1 // choose what demo to run

int main(){

	printf("\n Welcome to system programming in C! \n");

	printf("\t -> Topic: Files systems \n ");


	int demo_list_choice[] = {0, // open() demo
			1}; // read() demo

	int demo_to_run = demo_list_choice[DEMO_CHOICE];

	switch (demo_to_run){

		case 0:

		run_open_demo(); // demo 0
		break;

		case 1:
		run_read_demo(); // demo 1
		break;

		default:
		break;


	} // end switch case

} // End main()
