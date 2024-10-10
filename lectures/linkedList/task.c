#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

NODE *createNode(char *task) {
    NODE *newNode = (NODE*) malloc(sizeof(NODE));
    strcpy(newNode->task, task);
    newNode->next = 0;
    return newNode;
}

void addNode(NODE **start, NODE *newNode) {
    newNode->next = *start;
    *start = newNode;
}

void printNodes(NODE *start) {
    NODE *current = start;
    while (current != NULL) {
        printf("%s\n", current->task);
        current = current->next;
    }
}