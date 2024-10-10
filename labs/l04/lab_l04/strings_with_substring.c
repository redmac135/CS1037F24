/**
 * -------------------------------------
 * @file  strings_with_substring.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author Ethan Zhao, 251346104, ezhao33@uwo.ca
 *
 * @version 2024-09-23
 *
 * -------------------------------------
 */
#include <stdio.h>
#include "functions.h"

void strings_with_substring(strings_array *data, char *substr) {
    for(int i = 0; i < data->lines; i++) {
        // the string we are looking at is *(data->strings + i * data->capacity)
        // use 2 pointer method to test if substring present
        int p1 = 0; // pointer to data string
        int p2 = 0; // pointer to substr

        // keep checking substring existence until we reach end of line
        while (*(*(data->strings + i) + p1) != '\0') {
            // if we are at end of substr, then this is a match
            if (*(substr + p2) == '\0') {
                printf("%s\n", *(data->strings + i));
                return;
            }

            // if the characters are the same, then move p2
            if (*(*(data->strings + i) + p1) == *(substr + p2)) {
                p2++;
            } else {
                // otherwise reset it
                p2 = 0;
            }

            // increment first pointer
            p1++;
        }
    }
}
