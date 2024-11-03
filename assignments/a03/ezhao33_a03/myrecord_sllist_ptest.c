#include "myrecord_sllist.h"
#include <stdio.h>
#include <stdlib.h>

// print contents of singly linked list
void print_sll_inline(SLL *sllp) {
  NODE *curr = sllp->start;
  printf("length %d ", sllp->length);
  while (curr != NULL) {
    printf("%s %.1f ", curr->data.name, curr->data.score);
    curr = curr->next;
  }
  printf("\n");
}

void print_sll_newline(SLL *sllp) {
  NODE *curr = sllp->start;
  printf("length:%d\n", sllp->length);
  while (curr != NULL) {
    printf("%s,%.1f\n", curr->data.name, curr->data.score);
    curr = curr->next;
  }
}

// print contents of node
void print_node(NODE *np) {
  if (np == NULL) {
    printf("not found\n");
    return;
  }
  printf("%s %.1f\n", np->data.name, np->data.score);
}

SLL *create_sll() {
  SLL *sllp = malloc(sizeof(SLL));
  sllp->length = 0;
  sllp->start = NULL;
  return sllp;
}

void add_example_data(SLL *sllp) {
  sll_insert(sllp, "A0", 100.0);
  sll_insert(sllp, "A1", 10.0);
  sll_insert(sllp, "A2", 20.0);
  sll_insert(sllp, "A3", 30.0);
  sll_insert(sllp, "A4", 40.0);
  sll_insert(sllp, "A5", 50.0);
  sll_insert(sllp, "A6", 60.0);
  sll_insert(sllp, "A7", 70.0);
  sll_insert(sllp, "A8", 80.0);
  sll_insert(sllp, "A9", 90.0);

  return;
}

void test_no_datafile() {
  printf("------------------\n");
  printf("Test: ssl_insert\n\n");

  // create a new singly linked list
  SLL *sllp1 = create_sll();

  printf("given linked list:");
  print_sll_inline(sllp1);

  printf("sll_insert(A9, 90.0): ");
  sll_insert(sllp1, "A9", 90.0);
  print_sll_inline(sllp1);

  printf("sll_insert(A8, 80.0): ");
  sll_insert(sllp1, "A8", 80.0);
  print_sll_inline(sllp1);

  printf("sll_insert(A7, 70.0): ");
  sll_insert(sllp1, "A7", 70.0);
  print_sll_inline(sllp1);

  printf("sll_insert(A6, 60.0): ");
  sll_insert(sllp1, "A6", 60.0);
  print_sll_inline(sllp1);

  // delete sllp1
  sll_clean(sllp1);
  free(sllp1);
  sllp1 = NULL;

  printf("\n");

  printf("------------------\n");
  printf("Test: ssl_search\n\n");

  // create a new singly linked list
  SLL *sllp2 = create_sll();
  add_example_data(sllp2);

  printf("given linked list:");
  print_sll_inline(sllp2);

  NODE *np;
  printf("sll_search(A1): ");
  np = sll_search(sllp2, "A1");
  print_node(np);

  printf("sll_search(A3): ");
  np = sll_search(sllp2, "A3");
  print_node(np);

  printf("sll_search(A5): ");
  np = sll_search(sllp2, "A5");
  print_node(np);

  printf("sll_search(A10): ");
  np = sll_search(sllp2, "A10");
  print_node(np);

  // delete sllp2
  sll_clean(sllp2);
  free(sllp2);
  sllp2 = NULL;

  printf("\n");

  printf("------------------\n");
  printf("Test: ssl_delete\n\n");

  // create a new singly linked list
  SLL *sllp3 = create_sll();
  add_example_data(sllp3);

  printf("given linked list:");
  print_sll_inline(sllp3);

  printf("sll_delete(A2): ");
  sll_delete(sllp3, "A2");
  print_sll_inline(sllp3);

  printf("sll_delete(A4): ");
  sll_delete(sllp3, "A4");
  print_sll_inline(sllp3);

  printf("sll_delete(A6): ");
  sll_delete(sllp3, "A6");
  print_sll_inline(sllp3);

  printf("sll_delete(A8): ");
  sll_delete(sllp3, "A8");
  print_sll_inline(sllp3);

  // delete sllp3
  sll_clean(sllp3);
  free(sllp3);
  sllp3 = NULL;

  return;
}

void test_with_datafile(char *datafile) {
  printf("------------------\n");
  printf("Test: import_data\n\n");

  // create a new singly linked list
  SLL *sllp = create_sll();

  printf("Import data from file\n");
  import_data(datafile, sllp);
  print_sll_newline(sllp);

  printf("\n");

  printf("Test: process_data\n\n");

  process_data(sllp);

  printf("\n");

  return;
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    test_no_datafile();
  } else if (argc == 2) {
    test_with_datafile(argv[1]);
  } else {
    printf("Usage: %s or %s <datafile path>\n", argv[0], argv[0]);
  }

  return 0;
}
