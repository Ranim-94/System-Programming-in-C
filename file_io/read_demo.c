/*
 * read_demo.c
 *
 *  Created on: Jul 9, 2024
 *      Author: ranimtom
 */


#include "read_demo.h"

#include <stdio.h>

#include <fcntl.h> // to use open()

#include <unistd.h> // read()

#include <errno.h> // for linux processes
#include <stdlib.h>

void run_read_demo(void){


	  int fd, sz;
	  char buf[20] = {0};

	  // open the file input
	  fd = open("dummy_file", O_RDONLY);

	  if (fd < 0){
	      perror("Error:"); exit(1);
	      // we exit from program
	  }

	  // read 10 bytes
	  sz = read(fd, buf, 10);
	  // this will copy content of input file to buff

	  printf("call 1 - called read. fd = %d,  %d bytes  were read.\n", fd, sz);

	  buf[sz] = '\0'; // insert null terminator
	  printf("Read bytes are as follows: \n \t <%s>\n", buf);

	  printf("\n Note the next set of bytes read from file, it is continuos\n \n");

	  sz = read(fd, buf, 11);
	  printf("call 2 - called read. fd = %d,  %d bytes  were read.\n", fd, sz);

	  buf[sz] = '\0';
	  printf("Displaying content after call #2:\n \t <%s>\n", buf);

	  sz = read(fd, buf, 10);
	  printf("call 3 - called read. fd = %d,  %d bytes  were read.\n", fd, sz);

	  printf("Displaying content after call #3:\n \t <%s>\n", buf);

	  if(sz == 0){
	      printf("EOF Reached\n");
	  } // End if()


	  close(fd);


} // End run_read_demo()
