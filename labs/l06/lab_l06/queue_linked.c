/**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author Ethan Zhao, 251346104, ezhao33@uwo.ca
 *
 * @version 2024-10-22
 *
 * -------------------------------------
 */
// Includes
#include "queue_linked.h"
#include "data.h"

// Functions

queue_linked *queue_initialize() {
  // Allocation memory for queue_linked
  queue_linked *source = malloc(sizeof *source);

  // Initialize the front and rear of the queue
  source->front = NULL;
  source->rear = NULL;
  source->count = 0;

  return source;
}

void queue_free(queue_linked **source) {
  // Verify source is not NULL
  if (*source == NULL) {
    return;
  }

  // Free linked data
  while ((*source)->front != NULL) {
    queue_node *node_to_free = (*source)->front;
    (*source)->front = node_to_free->next;
    (*source)->count--;
    free(node_to_free);
  }

  (*source)->rear = NULL;

  // Free the source
  free(*source);
  *source = NULL;
  return;
}

BOOLEAN queue_empty(const queue_linked *source) {
  if (source->count == 0) {
    return TRUE;
  }
  return FALSE;
}

int queue_count(const queue_linked *source) { return source->count; }

void queue_insert(queue_linked *source, data_ptr item) {
  // Allocate space for new node
  queue_node *new_node = malloc(sizeof(queue_node));
  int *new_data = malloc(sizeof(data_ptr));

  // set new_node data fields
  *new_data = *item;
  new_node->next = NULL;
  new_node->item = new_data;

  // set rear node to point to new node
  if (source->rear != NULL) {
    source->rear->next = new_node;
  }

  // if queue is empty, set front to new_node
  if (queue_empty(source)) {
    source->front = new_node;
  }

  // update source with new data
  source->rear = new_node;
  source->count++;
  return;
}

BOOLEAN queue_peek(const queue_linked *source, data_ptr item) {
  // Check if queue is empty
  if (queue_empty(source)) {
    return FALSE;
  }
  // Set the value of the data_ptr to the value of the item at the front
  *item = *(source->front->item);
  return TRUE;
}

BOOLEAN queue_remove(queue_linked *source, data_ptr *item) {
  queue_node *top_node = source->front;
  *item = top_node->item;
  source->front = top_node->next;
  free(top_node);
  source->count--;
  return TRUE;
}

void queue_print(const queue_linked *source) {
  char string[DATA_STRING_SIZE];
  queue_node *current = source->front;

  while (current != NULL) {
    printf("%s\n", data_string(string, sizeof string, current->item));
    current = current->next;
  }
  return;
}
