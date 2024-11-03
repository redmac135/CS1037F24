#include "expression.h"
#include <stdlib.h>

QUEUE infix_to_postfix(char *infixstr) {
  // create queue to store postfix expression
  QUEUE *queue = malloc(sizeof(QUEUE));
  queue->length = 0;
  queue->front = NULL;
  queue->rear = NULL;

  // create stack to store operators
  STACK *stack = malloc(sizeof(STACK));
  stack->length = 0;
  stack->top = NULL;
}

int evaluate_postfix(QUEUE queue) {}

int mypriority(char op) {
  if (op == '+' || op == '-') {
    return 0;
  } else if (op == '*' || op == '/' || op == '%') {
    return 1;
  }

  return -1;
}
