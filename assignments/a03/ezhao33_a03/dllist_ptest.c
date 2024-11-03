#include "dllist.h"
#include <stdio.h>
#include <stdlib.h>

DLL *create_dll() {
  DLL *dllp = malloc(sizeof(DLL));
  dllp->length = 0;
  dllp->start = NULL;
  dllp->end = NULL;
  return dllp;
}

void add_example_data(DLL *dllp) {
  NODE *np1 = new_node('A');
  NODE *np2 = new_node('B');
  NODE *np3 = new_node('C');
  NODE *np4 = new_node('D');

  dll_insert_start(dllp, np1);
  dll_insert_start(dllp, np2);
  dll_insert_start(dllp, np3);
  dll_insert_start(dllp, np4);

  return;
}

void reset_node_relations(NODE *np) {
  np->next = NULL;
  np->prev = NULL;
  return;
}

void print_node(NODE *np) {
  if (np == NULL) {
    printf("null\n");
    return;
  }
  printf("%c\n", np->data);
}

void print_dll_forwards(DLL *dllp) {
  printf("length %d forward ", dllp->length);
  NODE *curr = dllp->start;
  while (curr != NULL) {
    printf("%c ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

void print_dll_backwards(DLL *dllp) {
  printf("length %d backward ", dllp->length);
  NODE *curr = dllp->end;
  while (curr != NULL) {
    printf("%c ", curr->data);
    curr = curr->prev;
  }
  printf("\n");
}

int main() {
  printf("------------------\n");
  printf("Test: new_node\n\n");

  // create new nodes
  NODE *np1 = new_node('A');
  printf("new_node(A): ");
  print_node(np1);

  NODE *np2 = new_node('B');
  printf("new_node(B): ");
  print_node(np2);

  NODE *np3 = new_node('C');
  printf("new_node(C): ");
  print_node(np3);

  NODE *np4 = new_node('D');
  printf("new_node(D): ");
  print_node(np4);

  printf("\n");

  printf("------------------\n");
  printf("Test: dll_insert_start\n\n");

  // create a new doubly linked list
  DLL *dllp1 = create_dll();
  printf("given dll: ");
  print_dll_forwards(dllp1);

  printf("dll_insert_start(A): ");
  dll_insert_start(dllp1, np1);
  print_dll_forwards(dllp1);

  printf("dll_insert_start(B): ");
  dll_insert_start(dllp1, np2);
  print_dll_forwards(dllp1);

  printf("dll_insert_start(C): ");
  dll_insert_start(dllp1, np3);
  print_dll_forwards(dllp1);

  printf("dll_insert_start(D): ");
  dll_insert_start(dllp1, np4);
  print_dll_forwards(dllp1);

  // free dllp1
  free(dllp1);
  dllp1 = NULL;

  // reset nodes
  reset_node_relations(np1);
  reset_node_relations(np2);
  reset_node_relations(np3);
  reset_node_relations(np4);

  printf("\n");

  printf("------------------\n");
  printf("Test: dll_insert_end\n\n");

  // create a new doubly linked list
  DLL *dllp2 = create_dll();
  printf("given dll: ");
  print_dll_forwards(dllp2);

  printf("dll_insert_end(A): ");
  dll_insert_end(dllp2, np1);
  print_dll_forwards(dllp2);

  printf("dll_insert_end(B): ");
  dll_insert_end(dllp2, np2);
  print_dll_forwards(dllp2);

  printf("dll_insert_end(C): ");
  dll_insert_end(dllp2, np3);
  print_dll_forwards(dllp2);

  printf("dll_insert_end(D): ");
  dll_insert_end(dllp2, np4);
  print_dll_forwards(dllp2);

  printf("resulted dll: ");
  print_dll_backwards(dllp2);

  // free dllp2
  free(dllp2);
  dllp2 = NULL;

  // reset nodes
  reset_node_relations(np1);
  reset_node_relations(np2);
  reset_node_relations(np3);
  reset_node_relations(np4);

  printf("\n");

  printf("------------------\n");
  printf("Test: dll_delete_start\n\n");

  // create a new doubly linked list
  DLL *dllp3 = create_dll();
  add_example_data(dllp3);

  printf("given dll: ");
  print_dll_forwards(dllp3);

  printf("dll_delete_start(A): ");
  dll_delete_start(dllp3);
  print_dll_forwards(dllp3);

  printf("dll_delete_start(B): ");
  dll_delete_start(dllp3);
  print_dll_forwards(dllp3);

  printf("dll_delete_start(C): ");
  dll_delete_start(dllp3);
  print_dll_forwards(dllp3);

  printf("dll_delete_start(D): ");
  dll_delete_start(dllp3);
  print_dll_forwards(dllp3);

  // free dllp3
  free(dllp3);
  dllp3 = NULL;

  // reset nodes
  reset_node_relations(np1);
  reset_node_relations(np2);
  reset_node_relations(np3);
  reset_node_relations(np4);

  printf("\n");

  printf("------------------\n");
  printf("Test: dll_delete_end\n\n");

  // create a new doubly linked list
  DLL *dllp4 = create_dll();
  add_example_data(dllp4);

  printf("given dll: ");
  print_dll_forwards(dllp4);

  printf("dll_delete_end(A): ");
  dll_delete_end(dllp4);
  print_dll_forwards(dllp4);

  printf("dll_delete_end(B): ");
  dll_delete_end(dllp4);
  print_dll_forwards(dllp4);

  printf("dll_delete_end(C): ");
  dll_delete_end(dllp4);
  print_dll_forwards(dllp4);

  printf("dll_delete_end(D): ");
  dll_delete_end(dllp4);
  print_dll_forwards(dllp4);

  // free dllp and all nodes
  dll_clean(dllp4);
  free(dllp4);
  dllp4 = NULL;

  return 0;
}
