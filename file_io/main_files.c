

#include <stdio.h>
#include "open_demo.h"
#include "read_demo.h"
#include "write_demo.h"
#include "lseek_demo.h"

#define DEMO_CHOICE 3 // choose what demo to run

int main(){

	printf("\n Welcome to system programming in C! \n");

	printf("\t -> Topic: Files systems \n ");


	int demo_list_choice[] = {0,1, // open(), read() demo
	2,3}; // write() ; lseek()

	int demo_to_run = demo_list_choice[DEMO_CHOICE];

	switch (demo_to_run){

		case 0:

		run_open_demo(); // demo 0
		break;

		case 1:
		run_read_demo(); // demo 1
		break;

		case 2:
		run_write_demo(); // demo 2
		break;

		case 3:
		run_lseek_demo(); // demo 3
		break;

		default:
		break;

	} // end switch case


} // End main()
