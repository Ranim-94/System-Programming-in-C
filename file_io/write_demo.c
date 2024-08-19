/*
 * write_demo.c
 *
 *  Created on: Jul 9, 2024
 *      Author: ranimtom
 */


#include "write_demo.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>
#include <unistd.h>

void run_write_demo(void){

	int sz;
	char buf[100];

	strcpy(buf,"This is example of O_TRUNC: Sample file write2 using append flag\n");

	  /* O_TRUNC => write to file from beginning , discarding old contents*/
	  /* O_APPEND => write the contents of file from the end of existing file contents*/

	 // As always we need to open the file
	 int fd = open("dummy_file", O_WRONLY|O_APPEND);
	 // we add O_APPEND flag if we don't want to
	 // discard old content

	  if (fd < 0){
	     perror("Error occurred during open");
	     exit(1);
	  }

	  printf("-> length of buf is (%d)",(int)strlen(buf));

	  // writing content to the text file
	  // it will return the number of bytes written
	  sz = write(fd, buf, strlen(buf));

	  printf("\n write() returned  %d\n", sz);

	  close(fd); // closing file descriptor





} // End run_write_demo()
