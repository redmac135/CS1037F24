#include "myrecord_sllist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NODE *sll_search(SLL *sllp, char *name) {
  NODE *curr = sllp->start;

  // iterate through singly linked list
  while (curr != NULL) {
    // case where node is found
    if (strcmp(name, curr->data.name) == 0) {
      return curr;
    }
    curr = curr->next;
  }

  // case where node is not found
  return NULL;
}

void sll_insert(SLL *sllp, char *name, float score) {
  // allocate memory and create node
  NODE *new_node = malloc(sizeof(NODE));
  strcpy(new_node->data.name, name);
  new_node->data.score = score;
  new_node->next = NULL;

  // case where list is empty
  if (sllp->start == NULL) {
    sllp->start = new_node;
    sllp->length++;
    return;
  }

  // prev pointer is right behind curr
  NODE *prev = NULL;
  // curr pointer searches, node is to be added before curr
  NODE *curr = sllp->start;

  while (curr != NULL && strcmp(name, curr->data.name) > 0) {
    prev = curr;
    curr = curr->next;
  }

  // case where at beginning of list
  if (prev == NULL) {
    sllp->start = new_node;
    new_node->next = curr;
  } // case where at end of list
  else if (curr == NULL) {
    prev->next = new_node;
  } else {
    // case where in middle of list
    prev->next = new_node;
    new_node->next = curr;
  }

  sllp->length++;
  return;
}

int sll_delete(SLL *sllp, char *name) {
  NODE *prev = NULL;
  NODE *curr = sllp->start;

  // iterate through singly linked list
  while (curr != NULL) {
    // case where node is found
    if (strcmp(name, curr->data.name) == 0) {
      if (prev != NULL) {
        prev->next = curr->next;
        free(curr);
        sllp->length--;
      }
      return 1;
    }
    prev = curr;
    curr = curr->next;
  }

  // case where node is not found
  return 0;
}

void sll_clean(SLL *sllp) {
  NODE *curr = sllp->start;
  NODE *next = NULL;

  // free all nodes in singly linked list
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }

  // reset singly linked list
  sllp->start = NULL;
  sllp->length = 0;
  return;
}

void import_data(const char *filename, SLL *sllp) {
  FILE *file = fopen(filename, "r");

  // account for case where file does not exist
  if (file == NULL) {
    return;
  }

  // read in data from file
  char name[NAME_MAX];
  int score;

  while (fscanf(file, "%[^,],%d\n", name, &score) != EOF) {
    // insert data into singly linked list
    sll_insert(sllp, name, score);
  }

  return;
}

double sqroot(double square) {
  // start with an initial guess for the square root (arbitrary choice)
  double root = square / 3;
  int i;

  // check if input is non-positive; square root is undefined for negative
  // numbers, and we return 0 as a safe response for both zero and negative
  // inputs.
  if (square <= 0)
    return 0;

  // iteratively improve the approximation of the square root
  // using the Babylonian (or Heron's) method.
  for (i = 0; i < 32; i++)
    root = (root + square / root) / 2;

  return root;
}

void process_data(SLL *sllp) {
  // case where list is empty
  if (sllp->length == 0 || sllp->start == NULL) {
    printf("%-10s0\n", "count");
    printf("%-10snull\n", "mean");
    printf("%-10snull\n", "stddev");
    printf("%-10snull\n", "median");
    return;
  }

  // count
  printf("%-10s%d\n", "count", sllp->length);

  // sum
  long int running_sum = 0;

  // median
  // find the n//2+1 smallest elements
  int smallest[sllp->length / 2 + 1];
  int smallest_index = 0;

  NODE *curr = sllp->start;

  // first pass to find the mean of the data
  while (curr != NULL) {
    running_sum += curr->data.score;

    if (smallest_index < sllp->length / 2 + 1) {
      // add to smallest array
      smallest[smallest_index] = curr->data.score;
      smallest_index++;
    } else {
      // find max in smallest array
      int max_index = 0;
      for (int i = 1; i < sllp->length / 2 + 1; i++) {
        if (smallest[i] > smallest[max_index]) {
          max_index = i;
        }
      }
      if (curr->data.score < smallest[max_index]) {
        smallest[max_index] = curr->data.score;
      }
    }

    curr = curr->next;
  }

  // print mean
  double mean = (float)running_sum / sllp->length;
  printf("%-10s%.1f\n", "mean", mean);

  // second pass to find the standard deviation
  double running_difference_squared = 0;
  curr = sllp->start;
  while (curr != NULL) {
    running_difference_squared +=
        (curr->data.score - mean) * (curr->data.score - mean);
    curr = curr->next;
  }
  // print standard deviation
  double stddev = sqroot(running_difference_squared / sllp->length);
  printf("%-10s%.1f\n", "stddev", stddev);

  // find median by finding first 2 largest elements in smallest array
  int largest[2] = {0, 0};
  for (int i = 0; i < sllp->length / 2 + 1; i++) {
    if (smallest[i] > largest[0]) {
      largest[1] = largest[0];
      largest[0] = smallest[i];
    } else if (smallest[i] > largest[1]) {
      largest[1] = smallest[i];
    }
  }

  // if median
  if (sllp->length % 2 == 0) {
    printf("%-10s%.1f\n", "median", (largest[0] + largest[1]) / 2.0);
  } else {
    printf("%-10s%d.0\n", "median", largest[0]);
  }
}
