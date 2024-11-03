#include "queue.h"
#include <stdlib.h>

void enqueue(QUEUE *qp, NODE *np) {
  // case where the queue is empty
  if (qp->length == 0) {
    qp->front = np;
    qp->rear = np;
  } else {
    // add the node to the rear of the queue
    qp->rear->next = np;
    qp->rear = np;
  }
  // update the length of the queue
  qp->length++;

  return;
}

NODE *dequeue(QUEUE *qp) {
  // case where the queue is empty
  if (qp->length == 0) {
    return NULL;
  }

  // remove the front node from the queue
  NODE *np = qp->front;
  // update the front of the queue
  qp->front = qp->front->next;
  np->next = NULL;
  // update the length of the queue
  qp->length--;
  return np;
}

void queue_clean(QUEUE *qp) {
  NODE *np = NULL;
  // keep dequeueing until the queue is empty
  while (qp->front) {
    np = dequeue(qp);
    free(np);
  }

  // reset the queue
  qp->rear = NULL;
  qp->length = 0;

  return;
}
