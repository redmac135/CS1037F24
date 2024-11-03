#include "stack.h"
#include <stdlib.h>

void push(STACK *sp, NODE *np) {
  // add node to top and increment length
  np->next = sp->top;
  sp->top = np;
  sp->length++;

  return;
}

NODE *pop(STACK *sp) {
  // remove top node and decrement length
  NODE *np = sp->top;
  sp->top = np->next;
  sp->length--;
  np->next = NULL;
  return np;
}

void stack_clean(STACK *sp) {
  // remove all nodes from stack
  while (sp->top != NULL) {
    NODE *np = sp->top;
    sp->top = np->next;
    free(np);
  }

  // reset stack
  sp->length = 0;

  return;
}
