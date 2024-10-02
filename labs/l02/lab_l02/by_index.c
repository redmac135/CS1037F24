/**
 * -------------------------------------
 * @file  by_index.c
 * Lab 2 Index Functions Source Code File
 * -------------------------------------
 * @author Ethan Zhao, 251346104, ezhao33@uwo.ca
 *
 * @version 2024-09-06
 *
 * -------------------------------------
 */
#include "by_index.h"

void fill_values_by_index(int values[], int size) {

    for(int i = 0; i < size; i++) {
        values[i] = i + 1;
    }
}

void fill_squares_by_index(int values[], long int squares[], int size) {

    // iterate through both arrays and set squares array to the square of values array
    for(int i = 0; i < size; i++) {
        squares[i] = values[i] * values[i];
    }
}

void print_by_index(int values[], long int squares[], int size) {

    // prints header of table
    printf("Value  Squares\n");
    printf("-----  -----------\n");

    // loops through both arrays, printing numbers left-padded with spaces to right align to table header
    for (int i = 0; i < size; i++) {
        printf("%5d  %11d\n", values[i], squares[i]);
    }
}
