
#include "mutex_demo.h"

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* increment_routine_mutex(void);

int some_nb_demo2 = 0;

/*create a mutex*/
pthread_mutex_t mutex_some_nb;

#define ITER_NB 100
#define NB_THREDAS 2



void run_mutex_demo(void){


	pthread_t t[NB_THREDAS];

	/*initialize the mutex*/
	pthread_mutex_init(&mutex_some_nb,NULL);

	/*step 2: To create the thread*/

	// pthread_create(&t[0],NULL,&increment_routine_mutex,NULL);
	// pthread_create(&t[1],NULL,&increment_routine_mutex,NULL);


	for(int i = 0 ; i< NB_THREDAS; i++){

	 pthread_create(&t[i],NULL,(void*) &increment_routine_mutex,NULL);

	} /*End for() */


	for(int i = 0 ; i< NB_THREDAS; i++){

		pthread_join(t[i],NULL);

	} /*End for() */

	printf("\t -> some_nb value after thread = %d \n",some_nb_demo2);

	/*
	 * We use different loops in order
	 * to use threads in // manner
	 * */

	/*free the mutex resource*/
	pthread_mutex_destroy(&mutex_some_nb);




} // End run_mutex_demo()


void* increment_routine_mutex(void){

	for(int i = 0; i<ITER_NB ; i++){

		pthread_mutex_lock(&mutex_some_nb);
		some_nb_demo2++;
		pthread_mutex_unlock(&mutex_some_nb);

	}


} // End increment_routine()

/*
 *
 * When we use pthread_join()
 * and printf() statment, it doesn't mean that
 * th1, then th2 will finish in that order
 * It is just the way that we are listing and printing
 *
 *
 * */


