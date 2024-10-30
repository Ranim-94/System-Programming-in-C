
#include "wait_basics.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void run_wait_basics(void){

	/* Declaring some variables*/
	pid_t cpid;
	int status = 0;

	cpid = fork();
	/* Now both parent and child code can be executed*/
	/* Always recall that fork() will give the id of the
	 * child that is different from 0 <=> it will be some positive nb
	 *
	 * */

	/* Handling error*/
	 if(cpid == -1){
	     exit(-1);
	 }

	    if(cpid == 0){
	        /* Here is the child section of code */

	    	printf("\n child section; its pid = (%d)\n",getpid());
	        sleep(20);
	        printf("Child pid = %d\n", getpid());
	        exit(1);
	    }

	    if(cpid != 0){


	    	/*Parent process seciton of the code*/

	    	printf("\n Parent executing before wait()\n");

	        /* When we reach wait(), the parent process stop executing
	         *
	         * and wait() till the child process to finish
	         *
	         *
	         * wait() returns the child process we are waiting
	         * */
	        cpid = wait(NULL);


	        //cpid = wait(&status);

	        printf("\n wait() in parent is done\nParent pid = %d\n", getpid());
	        printf("\n cpid returned value = (%d) [this is true pid for the child]\n",cpid);
	        printf("\n status is (%d)\n",status);

	        /*
	         * if child process terminate properly, the
	         * status value >= 2^8 = 256 (represented by upper 8 bits of the 16 bits)
	         *
	         * else < 128 = 2^7 (represented by lower 8 bits)
	         *
	         *
	         * */

	    } /* End parent code*/


	    /*
	     * Another note about wait()
	     * if we have multiple processes (like a fork() inside the child)
	     * wait() will wait for all the processes <=> it doesn't have control
	     * to which process it will wait 1st
	     *
	     * */




} /* End run_wait_basics() */

