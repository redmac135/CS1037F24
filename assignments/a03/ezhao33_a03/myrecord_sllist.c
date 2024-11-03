#include "myrecord_sllist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NODE *sll_search(SLL *sllp, char *name) {
  NODE *curr = sllp->start;

  while (curr != NULL) {
    if (strcmp(name, curr->data.name) == 0) {
      return curr;
    }
    curr = curr->next;
  }

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
  if (prev != NULL) {
    prev->next = curr;
  }

  // case where at end of list
  if (curr != NULL) {
    new_node->next = curr->next;
  }

  sllp->length++;
  return;
}

int sll_delete(SLL *sllp, char *name) {
  NODE *prev = NULL;
  NODE *curr = sllp->start;

  while (curr != NULL) {
    if (strcmp(name, curr->data.name) == 0) {
      if (prev != NULL) {
        prev->next = curr->next;
        free(curr);
        sllp->length--;
      }
      return 1;
    }
  }

  return 0;
}

void sll_clean(SLL *sllp) {
  NODE *curr = sllp->start;
  NODE *next = NULL;

  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }

  sllp->start = NULL;
  sllp->length = 0;
  return;
}

void import_data(const char *filename, SLL *sllp) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return;
  }

  char name[NAME_MAX];
  int score;

  while (fscanf(file, "%[^,]s,%d", name, &score) != EOF) {
    sll_insert(sllp, name, score);
  }
}

void process_data(SLL *sllp) {
  // case where lsit is empty
  if (sllp->length == 0 || sllp->start == NULL) {
    printf("%10s0\n", "count");
    printf("%10snull\n", "mean");
    printf("%10snull\n", "stddev");
    printf("%10snull\n", "median");
    return;
  }

  // count
  printf("%10s%d\n", "count", sllp->length);

  // sum
  long int running_sum = 0;

  // stddev
  long int running_sum_squared = 0;

  // median
  // find my selected the n//2+1 smallest elements
  int smallest[sllp->length / 2 + 1];
  int smallest_index = 0;

  NODE *curr = sllp->start;

  while (curr != NULL) {
    running_sum += curr->data.score;
    running_sum_squared += curr->data.score * curr->data.score;

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
  }

  // print mean
  float mean = (float)running_sum / sllp->length;
  printf("%10s%.1f\n", "mean", mean);

  // print standard deviation
  float stddev = (float)running_sum_squared / sllp->length - mean * mean;
  printf("%10s%f\n", "stddev", stddev);

  // print median
  if (sllp->length % 2 == 0) {
    printf("%10s%.1f\n", "median", (float)smallest[sllp->length/2] + smallest[sllp->length/2 + 1]) / 2);
  } else {
    // add decimal point to match format
    printf("%10s%d.0\n", "median", smallest[sllp->length / 2]);
  }
}
