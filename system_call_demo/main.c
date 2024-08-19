

#include <stdio.h>
#include <string.h>

#include <unistd.h> // for linux processes

int main(){

	printf("\n Welcome to system programming in C! \n");

	// Declaring and initializing some variables
	int msg_len = 0;

	char buff[100];

	// copying string into buff
	strcpy(buff,"some example of system call using write()");

	// taking the actual length
	msg_len = strlen(buff);

	// printing to the screen using write() system call function
	size_t sentence = write(1,buff,msg_len);
	// 1 -> to stdout (the screen)




} // End main()
