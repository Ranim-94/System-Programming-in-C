/*
 * lseek.c
 *
 *  Created on: Jul 17, 2024
 *      Author: ranimtom
 */


#include "lseek_demo.h"

// libraries

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void run_lseek_demo(void){

	// declare some variables
	int some_size , seek_pos = 0;

	char buff[BUFFER_SIZE];


	int fd = open("dummy_file",O_RDWR);

	// checking error for open()
	if (fd<0){

		perror("Error occur during open() \n");
		exit(1);

	} // End if()

	/*
	 * Some info about lseek()
	 *
	 * signature: off_t lseek (int fd, off_t pos, int origin);
	 *
	 * lseek() depends on origin
	 *
	 * In our example we use origin =  SEEK_END
	 *
	 * this mean the fd points to the begining of the file
	 * by some offset = pos
	 *
	 * */


	// case 1: pos = 0
	// origin = SEEK_SET -> seek_pos points to the
	// beginning of the file
	seek_pos = lseek(fd,0,SEEK_SET);

	printf("\n =-> Initial file position = %d bytes \n",seek_pos);

	// case 2: pos = 2
	seek_pos = lseek(fd,2,SEEK_SET);

	printf("\n  orig = 2 | file position = %d bytes \n",seek_pos);

	// case 3: pos = 3 and orig = SEEK_CUR
	// we have SEEK_CUR -> travel from the current position
	// 6 bytes -> it will give 8 bytes after the call
	seek_pos = lseek(fd,6,SEEK_CUR);

	printf("\n -> orig = 2 | file position = %d bytes \n",seek_pos);

	// now we will read for example 10 bytes
	some_size = read(fd,buff,10); // reading 10 bytes

	// insert a null terminator at the END
	buff[some_size] = '\0';

	// printing the content
	printf("\n -> Displaying content after lseek(): \n");

	printf("\n \t %s \n",buff);

	// moving to the END of the file <-> use SEEK_END and pos = 0
	seek_pos = lseek(fd,0,SEEK_END);

	strcpy(buff,"New data appended using SEEK_END for lseek() demo");

	printf("\n \t new buff =  %s \n",buff);

	// write the content to the file
	// but after moving to the END -> so it is like appending
	some_size = write(fd,buff,strlen(buff));

	close(fd);// release the file descriptor after usage



} // End run_lseek_demo()
