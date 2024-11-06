#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void stack_init(STACK *sp) {
  // initialize stack
  sp->top = NULL;
  sp->length = 0;

  return;
}

void push(STACK *sp, NODE *np) {
  // case where node is null
  if (np == NULL) {
    return;
  }

  if (sp->length > 0) {
    // case where stack is not empty
    np->next = sp->top;
  }

  // add node to top and increment length
  sp->top = np;
  sp->length++;

  return;
}

NODE *pop(STACK *sp) {
  // case where stack is empty
  if (sp->length == 0) {
    return NULL;
  }

  // get top node
  NODE *np = sp->top;

  // remove top node
  sp->top = np->next;
  np->next = NULL;
  sp->length--;

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
