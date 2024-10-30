
/*
    Source file contains some useful function defintion for arrays,
    such as displaying content, random generation,....
*/

#include"array_manip.h"

#include<stdio.h>
#include<time.h> // for time
#include<stdlib.h> // to use RAND_MAX


// display content of some array
void display_1D_array(float some_arr[], size_t arr_size){

printf("\t \n Printing content of array \n");

// print the content  of the array using array name and index 
for (int i=0; i<arr_size; i++){

    printf("\t -> # %d = %f \n",i,some_arr[i]) ;

	} // End for loop printing

} // End display_array()


void generate_random_1D_array(float* array_ptr,size_t arr_size,
							  float limit){

// by using this type of implementation, the array_ptr is pointing to some declared array
// in the local main program (or where this function is being called in some source file)

// so we can generate random numbers each time we run the code
srand(time(NULL));

// fill in the array randomly between 0 and ARRAY_SIZE
// but pay attention here we are using the pointer and not the actual array
for (int i=0; i<arr_size; i++){

    array_ptr[i] = (float)rand()/((float)RAND_MAX); // here we have a floating point between 0 and 1
    array_ptr[i] *= limit; // scale up to ARRAY_SIZE

	} // End for loop filling content

} // End generate_random_1D_array()
