/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author Ethan Zhao, 251346104, ezhao33@uwo.ca
 *
 * @version 2024-09-25
 *
 * -------------------------------------
 */
#include "functions.h"
#include <stdio.h>

void int_array_read(int *array, int size) {
    // initalize two variables to store the current num input and the string of the input
    int currnum;
    char input[STRING_SMALL];

    // begin the program by mentioning size of array
    printf("Ethan %d values for an array of int.\n", size);

    // iterate through each element, populating the array
    for(int i = 0; i < size; i++) {
        printf("Value for index %d: ", i);

        // get the users input
        // if there is no input, break
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        if (sscanf(input, "%d", &currnum) == 1) {
            *(array + i) = currnum;
        } else {
            // if not a valid integer, move cursor back 1 step to repeat if statement run
            printf("Not a valid integer\n");
            i--;
        }
    }
}
