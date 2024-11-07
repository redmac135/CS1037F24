#include "bt.h"
#include <stdio.h>
#include <stdlib.h>

int tree_member(int x, Tree *tree) {
  // Store current node
  Node *curr = *tree;

  // If we ever select a NULL node, then value doesn't exist
  while (curr != NULL) {
    // If value is greater, then value is to the right
    if (x > curr->value) {
      curr = curr->right;
    } else if (x == curr->value) {
      return 1;
      // if value is less, then value is to the left
    } else if (x < curr->value) {
      curr = curr->left;
    }
  }

  return 0;
}

void tree_free(Tree *tree) {
  // Case where tree is Null
  if (*tree == NULL) {
    return;
  }

  // Free left and right subtrees
  tree_free(&(*tree)->left);
  tree_free(&(*tree)->right);

  return;
}

Tree *tree_insert(int x, Tree *tree) {
  // Case where tree is NULL
  if (tree == NULL) {
    tree = malloc(sizeof(Tree));
    *tree = NULL;
  }

  // Case where tree is empty
  if (*tree == NULL) {
    // Allocate memory for new node
    Node *new_node = malloc(sizeof(Node));
    new_node->value = x;
    new_node->left = NULL;
    new_node->right = NULL;

    // Set tree to new node
    *tree = new_node;
    return tree;
  }

  Node *curr = *tree; // Not Null
  while (curr->value != x) {
    // If value is greater, then value is to the right
    if (x > curr->value) {
      // If right is NULL, then insert new node
      if (curr->right == NULL) {
        Node *new_node = malloc(sizeof(Node));
        new_node->value = x;
        new_node->left = NULL;
        new_node->right = NULL;

        curr->right = new_node;
        return tree;
      } else {
        curr = curr->right;
      }
    } else if (x < curr->value) {
      // If left is NULL, then insert new node
      if (curr->left == NULL) {
        Node *new_node = malloc(sizeof(Node));
        new_node->value = x;
        new_node->left = NULL;
        new_node->right = NULL;

        curr->left = new_node;
        return tree;
      } else {
        curr = curr->left;
      }
    }
  }

  // If value is already in tree, do nothing
  return NULL;
}

void pop_minimum(Tree *tree, int *min, Tree **new_tree) {
  // Case where minimum is the root
  if ((*tree)->left == NULL) {
    *min = (*tree)->value;
    *new_tree = &(*tree)->right;
    free(*tree);
    return;
  }

  // Get minimum node
  Node *curr = (*tree)->left;
  Node *prev = *tree;
  while (curr->left != NULL) {
    prev = curr;
    curr = curr->left;
  }

  // Case where minimum has no children
  if (curr->right == NULL) {
    *min = curr->value;
    prev->left = NULL;
    free(curr);
    *new_tree = tree;
    return;
  }

  // Find minimum of right subtree
  Node *min_right = curr->right; // not NULL
  Node *min_right_prev = NULL;
  while (min_right->left != NULL) {
    min_right_prev = min_right;
    min_right = min_right->left;
  }

  // Replace current node with minimum of right subtree
  prev->left = min_right;
  // If minimum of right subtree has right child, then we should make it a child
  // of this new head Note, if min_right_prev is NULL, then we are at the
  // minimum of the right subtree
  min_right->right = min_right_prev;
  min_right_prev->left = NULL;

  *new_tree = tree;
  return;
}
