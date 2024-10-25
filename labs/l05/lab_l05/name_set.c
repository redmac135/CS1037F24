/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Ethan Zhao, ezhao33@uwo.ca, 251346104
 *
 * @version 2024-09-09
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set* name_set_initialize() {
    // Allocate memory to the data structure
    name_set *set = malloc(sizeof *set);
    // Initialize the header fields.
    set->front = NULL;
    set->rear = NULL;
    return set;
}

int name_set_free(name_set **set) {
    // Case where set pointer is null
    if (*set == NULL) {
        return 0;
    }

    // Case where set is empty
    if ((*set)->front == NULL) {
        return 0;
    }

    int count = 0;
    name_set_node *current = (*set)->front;
    name_set_node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        count++;
        current = next;
    }

    // Now free the set
    free(*set);

    return count;
}

BOOLEAN name_set_append(name_set *set, const char *first_name, const char *last_name) {
    // Case where set pointer is null
    if (set == NULL) {
        return FALSE;
    }

    name_set_node *current = set->rear;

    // Iterate through each name, checking if name already exists
    if (name_set_contains(set, first_name, last_name)) {
        return FALSE;
    }

    // Now we can guarentee the name is unique
    // current pointer now pointing at last node

    // create new node
    name_set_node *new_node = malloc(sizeof *new_node);
    strcpy(new_node->first_name, first_name);
    strcpy(new_node->last_name, last_name);
    new_node->next = NULL;

    // Case where set is empty
    if (set->front == NULL) {
        set->front = new_node;
    } else {
        current->next = new_node;
    }

    // Append new node to the end of the list
    set->rear = new_node;

    return TRUE;
}

BOOLEAN name_set_contains(const name_set *set, const char *first_name, const char *last_name) {
    // Case where set pointer is null
    if (set == NULL) {
        return FALSE;
    }

    // Case where set is empty
    if (set->front == NULL) {
        return FALSE;
    }

    name_set_node *current = set->front;

    // Iterate through each name, checking if name already exists
    while (current != NULL) {
        if (strcmp(first_name, current->first_name) == 0 && strcmp(last_name, current->last_name) == 0) {
            return TRUE;
        }
        current = current->next;
    }

    return FALSE;
}

void name_set_print(const name_set *set) {
    // Case where set pointer is null
    if (set == NULL) {
        return;
    }

    // Case where set is empty
    if (set->front == NULL) {
        return;
    }

    name_set_node *current = set->front;
    name_set_node *next = set->front->next;
    while (next != NULL) {
        printf("%s, %s\n", current->last_name, current->first_name);
        current = next;
        next = current->next;
    }
}
