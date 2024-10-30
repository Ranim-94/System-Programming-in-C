


/*
 * Task:
 * - sum elements of 10 array using threads
 * - we will use 2 threads
 * 		- each thread takes 5 elements
 * 		- sum the 5 number in each thread
 * 		- then in the main thread sum the 2 half sum we obtained
 * */



#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#include "array_manip.h"


/*Initializing the array we will work with*/
#define ARRAY_SIZE 10
int primes_array[ARRAY_SIZE] = {2,3,5,7,11,13,17,19,23,29};

/*setting some number of threads*/
#define NB_THREDAS 2


void* sum_half_1d_array(void* arg);

void run_sum_1D_array(void){

	/* declaring threads */
	pthread_t th[NB_THREDAS];

	for(int i = 0 ; i < NB_THREDAS ; i++){

		/* allocating some index variable */
		int* vec_index = malloc(sizeof(int));
		/*
		 * It will be used so we can control access to
		 * the array
		 * */

		*vec_index = i*5;

		/*
		 * - Thread 1: (i = 0) -> we sum from 0 -> 4 (1st 5 elements)
		 * - Thread 2: (i = 1) -> we sum from 5 -> 9 (last 5 elements)
		 * 		- so for i = 1 -> *vec_index = 5
		 * 		 it will be as starting position for the 2nd thread
		 * */

		pthread_create(&th[i],NULL,&sum_half_1d_array,vec_index);
		/*
		 * - Here we are passing vec_index as input to the thread
		 * - this input is passed to the function sum_half_1d_array()
		 *
		 * */

	} // End for() for thread creation

	/*variable will hold the result of complete sum*/
	/* after each thread finished its work*/
	int complete_sum = 0;

	/*Now waiting for the threads and getting back some results*/
	for(int i = 0; i < NB_THREDAS ; i++){

		int* half_sum;

		pthread_join(th[i],(void**)&half_sum);
		/* Now we have some return value from the thread routine
		 * we use the 2nd argument of pthread_join() to get it back
		 */

		complete_sum += *half_sum;

		free(half_sum);
	} // End for


	printf("\t -> Complete sum = %d \n",complete_sum);


} // End run_sum_1D_array()


void* sum_half_1d_array(void* arg){

	int vec_index = *(int*)(arg);
	/*
	 * *(int*)(arg) means:
	 * 1- we are casting from void* to int*
	 * 2- then we are assigning value
	 * */

	int half_sum = 0;

	for(int i = 0 ; i< (int) ARRAY_SIZE/2; i++){

		half_sum += primes_array[vec_index + i];

	} // End for()

	printf("\t -> Local sum = %d \n",half_sum);

	/* assign the half_sum result to arg */
	*(int*)arg = half_sum;

	return (void*)arg;

} // End sum_half_1d_array()

