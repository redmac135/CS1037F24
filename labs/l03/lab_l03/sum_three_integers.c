/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author Ethan Zhao, 251346104, ezhao33@uwo.ca
 *
 * @version 2024-09-09
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {
    int nums[3] = {0,0,0};
    char input[STRING_SMALL];

    while(1) {
        // prompt user for input
        printf("Enter three comma-separated integers: ");

        // get the users input
        // if there is no input, break
        if(fgets(input, sizeof(input), stdin) == NULL) {
            break;
        } 

        // attempt to get input format
        if(sscanf(input, "%d,%d,%d", &nums[0], &nums[1], &nums[2]) == 3) {
            return nums[0] + nums[1] + nums[2];
        }

        // if failed to get input, repeat attempt
        printf("The integers were not properly entered.\n");
    }

    // return -1 if function failed
    return -1;
}
