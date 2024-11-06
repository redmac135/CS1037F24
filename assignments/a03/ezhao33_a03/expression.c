#include "expression.h"
#include "common.h"
#include <stdlib.h>

QUEUE infix_to_postfix(char *infixstr) {
  // create queue to store postfix expression
  QUEUE queue = {0};
  queue_init(&queue);

  // create stack to store operators
  STACK *stack = malloc(sizeof(STACK));
  stack_init(stack);

  // iterate through infix expression
  int i = 0;
  int num_to_enqueue = 0;

  char *curr_char = infixstr;
  int curr_type;
  char curr_num[100];
  char *curr_num_ptr = curr_num;

  // iterate through infix expression
  while (*curr_char != '\0') {
    curr_type = mytype(*curr_char);

    switch (curr_type) {
    case 0:
      // if digit, search for all digits and convert to int
      while (mytype(*curr_char) == 0) {
        *curr_num_ptr = *curr_char;
        curr_num_ptr++;
        curr_char++;
      }

      // end with null terminator and enqueue
      *curr_num_ptr = '\0';
      curr_char--;
      enqueue(&queue, new_node(atoi(curr_num), 0));
      curr_num_ptr = curr_num;
      break;
    case 1:
      // if operator, pop off all lower or equal priority operators
      while (stack->length > 0 &&
             mypriority(stack->top->data) >= mypriority(*curr_char)) {
        enqueue(&queue, pop(stack));
      }

      push(stack, new_node(*curr_char, 1));
      break;
    case 2:
      // if left parenthesis, add to stack
      push(stack, new_node(*curr_char, 2));
      break;
    case 3:
      // if right parenthesis, pop off all operators until left parenthesis
      while (stack->length > 0 && mytype(stack->top->data) != 2) {
        enqueue(&queue, pop(stack));
      }

      // remove left parenthesis
      pop(stack);
      break;
    }

    curr_char++;
  }

  // pop off remaining operators
  while (stack->length > 0) {
    enqueue(&queue, pop(stack));
  }

  // free stack
  clean(&stack->top);
  free(stack);

  return queue;
}

int evaluate_postfix(QUEUE queue) {
  // create stack to store operands
  STACK *stack = malloc(sizeof(STACK));
  stack_init(stack);

  // iterate through postfix expression
  NODE *np = dequeue(&queue);
  int num1, num2;

  while (np) {
    switch (np->type) {
    case 0:
      // if digit, add to stack
      push(stack, np);
      break;
    case 1:
      // if operator, pop off two numbers and perform operation
      num2 = stack->top->data;
      free(pop(stack));
      num1 = stack->top->data;
      free(pop(stack));

      switch (np->data) {
      case '+':
        push(stack, new_node(num1 + num2, 0));
        break;
      case '-':
        push(stack, new_node(num1 - num2, 0));
        break;
      case '*':
        push(stack, new_node(num1 * num2, 0));
        break;
      case '/':
        push(stack, new_node(num1 / num2, 0));
        break;
      }
      break;
    }

    np = dequeue(&queue);
  }

  // verify stack is now empty
  if (stack->length != 1) {
    return -1;
  }

  // get result
  int result = stack->top->data;

  // free stack
  free(stack);

  // get result
  return result;
}

int evaluate_infix(char *infixstr) {
  // convert infix expression to postfix
  // and evaluate postfix expression
  return evaluate_postfix(infix_to_postfix(infixstr));
}

int mypriority(char c) {
  switch (c) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
  case '%':
    return 2;
  }

  return 0;
}
