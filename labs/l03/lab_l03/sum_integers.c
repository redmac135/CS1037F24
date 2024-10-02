/**
 * -------------------------------------
 * @file  sum_integers.c
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

int sum_integers(void) {
    // initalize two ints to store the numbers and a char array to store the input
    int sum = 0;
    int num;
    char input[STRING_SMALL];

    while (1) {
        // get the users input
        // if there is no input, break
        if(fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // try to parse int
        if(sscanf(input, "%d", &num) == 1) {
            // add to sum if successfully parsed
            sum += num;
        } else {
            // if no int found, break
            break;
        }
    }

    return sum;
}
