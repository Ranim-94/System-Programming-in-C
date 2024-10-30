

#include "thread_demo.h"

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


void* some_routine(void);

void run_thread_demo(void){

 /* step 1: create a struct to store information about the thread */

	/* We will create 2 thread in order to
	 * see the function work in parallel
	 *
	 * */

	pthread_t t1, t2;

	/*step 2: To create the thread*/
	pthread_create(&t1,NULL,&some_routine,NULL);
	pthread_create(&t2,NULL,&some_routine,NULL);


	/*
	 * 1st and 3rd argument: pointers to our structure that hold the threads and function
	 * to be executed during this thread
	 *
	 * 2nd argument: some customization we can do about our thread
	 * since we don't want for now, we pass it NULL
	 *
	 * 4th argument: if we have some input to pass it to the function
	 * Now we don't have -> we pass NULL
	 *
	 * */


	/*step 3: wait the thread to be executed*/
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	/*
	 * 2nd argument: if we have some return value from the thread
	 * if no pass NULL
	 *
	 *Important note about pthread_join()
	 * - we call pthread_join() after all the pthread_create()
	 * in above, so we can have a multithreaded environment
	 *
	 * - if we do it this way:
	 * 	pthread_create(&t1)
	 * 	pthread_join(t1)
	 *
	 * 	pthread_create(&t2)
	 * 	pthread_join(t2)
	 *
	 *
	 *We will not have a multithreaded environment
	 *
	 * */


} // End run_thread_demo()


void* some_routine(void){

	printf("-> Hello from thread in routine() \n");
	sleep(3);

	printf("Ending thread \n");

}
