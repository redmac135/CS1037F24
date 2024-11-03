#include "dllist.h"
#include <stdlib.h>

NODE *new_node(char value) {
  NODE *np = malloc(sizeof(NODE));
  np->data = value;
  np->next = NULL;
  np->prev = NULL;
  return np;
}

void dll_insert_start(DLL *dllp, NODE *np) {
  // case where dllp empty
  if (dllp->start == NULL) {
    dllp->start = np;
    dllp->end = np;
    dllp->length++;
    return;
  }

  // case where dllp not empty
  np->next = dllp->start;
  dllp->start->prev = np;
  dllp->start = np;
  return;
}

void dll_insert_end(DLL *dllp, NODE *np) {
  // case where dllp empty
  if (dllp->start == NULL) {
    dllp->start = np;
    dllp->end = np;
    dllp->length++;
    return;
  }

  // case where dllp not empty
  dllp->end->next = np;
  np->prev = dllp->end;
  dllp->end = np;
  dllp->length++;
  return;
}

void dll_delete_start(DLL *dllp) {
  // case where dllp empty
  if (dllp->start == NULL) {
    // just return
    return;
  }

  // case where only 1 node
  if (dllp->start == dllp->end) {
    free(dllp->start);
    dllp->start = NULL;
    dllp->end = NULL;
    dllp->length--;
    return;
  }

  // case where has more nodes
  NODE *temp = dllp->start;
  dllp->start = dllp->start->next;
  dllp->start->prev = NULL;
  free(temp);

  return;
}

void dll_delete_end(DLL *dllp) {
  // case where dllp empty
  if (dllp->start == NULL) {
    // just return
    return;
  }

  // case where only 1 node
  if (dllp->start == dllp->end) {
    free(dllp->start);
    dllp->start = NULL;
    dllp->end = NULL;
    dllp->length--;
    return;
  }

  // case where has more nodes
  NODE *temp = dllp->end;
  dllp->end = dllp->end->prev;
  dllp->end->next = NULL;
  free(temp);

  return;
}

void dll_clean(DLL *dllp) {
  NODE *curr = dllp->start;
  NODE *next = NULL;

  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }

  // reset doubly linked list
  dllp->start = NULL;
  dllp->end = NULL;
  dllp->length = 0;
  return;
}
