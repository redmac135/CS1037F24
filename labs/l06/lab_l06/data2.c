/**
 * -------------------------------------
 * @file  data.h
 * Data Type Source Code File
 * -------------------------------------
 * @author 
 *
 * @version 2024-09-11
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
// Includes
#include <stdio.h>

#include "data2.h"

// Functions

char* data_string(char *string, size_t size, data_ptr data) {
    strncpy(string, data, size);
    return string;
}

void data_copy(data_ptr target, data_ptr source) {
    strcpy(target, source);
}

int data_compare(const data_ptr source, data_ptr target) {
    return strcmp(target, source);
}

void data_free(data_ptr *source) {
    free(*source);
    *source = NULL;
    return;
}
