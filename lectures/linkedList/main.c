#include <stdio.h>
#include "task.h"

int main() {
    NODE *task1 = createNode("Task 1");
    NODE *task2 = createNode("Task 2");
    NODE *task3 = createNode("Task 3");

    NODE *start = task1;

    addNode(&start, task2);
    addNode(&start, task3);

    printNodes(start);

    return 0;
}