

#include <stdio.h>
#include "thread_demo.h"
#include "race_condition.h"
#include "mutex_demo.h"
#include "sum_array.h"


/* from 0 -> 3*/
#define DEMO_CHOICE 0

int main(void){

	printf("\t ====== Starting threading in C ======= \n ");

	int demo_list_choice[] = {0, /* thread_demo */
		1, /*race_condition*/
		2,  /*mutex demo*/
		3}; /* sum of 1D array example*/

	int demo_to_run = demo_list_choice[DEMO_CHOICE];

	switch (demo_to_run) {

		case 0:
			run_thread_demo();
			break;

		case 1:
			run_race_condition_demo();
			break;

		case 2:
			run_mutex_demo();
			break;

		case 3:
			  run_sum_1D_array();
			  break;

		default:
			break;

	} // End switch case




} // End main()

