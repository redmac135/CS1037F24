/**
 * -------------------------------------
 * @file  strings_length.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author Ethan Zhao, 251346104, ezhao33@uwo.ca
 *
 * @version 2024-09-23
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long, int length) {
    // iterate through each line
    for(int i = 0; i < data->lines; i++) {

        // iterate through each character on the line
        int ptr = 0;
        while (*(*(data->strings + i) + ptr) != '\0') {
            ptr++;
        }

        // the length of the line is the position of the ptr
        if (ptr < length) {
            fprintf(fp_short, "%s\n", *(data->strings + i));
        } else {
            fprintf(fp_long, "%s\n", *(data->strings + i));
        }
    }
}
