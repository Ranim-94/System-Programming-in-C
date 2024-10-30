



#include "race_condition.h"

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* increment_routine(void);

int some_nb = 0;

#define ITER_NB 100


void run_race_condition_demo(void){

	pthread_t t1, t2;

	/*step 2: To create the thread*/
	pthread_create(&t1,NULL,&increment_routine,NULL);
	pthread_create(&t2,NULL,&increment_routine,NULL);


	/*step 3: wait the thread to be executed*/
	pthread_join(t1,NULL);

	printf("\t -> some_nb value after thread 1 = %d \n",some_nb);

	pthread_join(t2,NULL);

	printf("\t -> some_nb value after thread 2 = %d \n",some_nb);



} // End run_race_condition_demo()



void* increment_routine(void){

	for(int i = 0; i<ITER_NB ; i++){
		some_nb++;
	}


} // End increment_routine()

