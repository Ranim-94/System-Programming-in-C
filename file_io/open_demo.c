/*
 * read_demo.c
 *
 *  Created on: Jul 9, 2024
 *      Author: ranimtom
 */

#include <stdio.h>

#include <fcntl.h> // to use open()

#include <errno.h> // for linux processes
#include "open_demo.h"

void run_open_demo(void){

	int file_des;

	file_des = open("dummy_file",O_RDONLY);
	// open() takes flags
	// in this example: we took a read only flag
	// which means that the file exist


	/*
		 *
		 *
		 * To use multiple flags
		 *
		 * we can:
		 *
		 * file_des = open("dummy_file",O_RDONLY|O_CREAT);
		 *
		 * if file doesn't exist, it will creat
		 *
		 *
		 *
		 * */

		if (file_des == -1){
			// In this block, this means that something wrong

			printf(" error in open() - errno = %d \n",errno);

			perror("Error: \n");
			// the errno variable will be printed here in this statment


		}else {
			// successfull open the file in read only mode
			printf("\t open() is done successfully \n");

			printf("\t associated file desc = %d",file_des);

		} // End if-else selection


} // End run_open_demo()

