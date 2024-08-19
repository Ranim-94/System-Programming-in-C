/*
 * lseek_demo.h
 *
 *  Created on: Jul 17, 2024
 *      Author: ranimtom

 */

#pragma once

void run_lseek_demo(void);

/*  Some information about lseek():

Some applications, however,
want to jump around in a file, providing random rather than linear access.

The lseek() system call is provided to set the file position
of a file descriptor to a given value.
Other than updating the file position, it performs no other action,
and initiates no I/O

 * */
