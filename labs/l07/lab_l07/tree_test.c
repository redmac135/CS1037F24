#include "bt.h"
#include <stdio.h>
#include <stdlib.h>

void run_tests() {
  Tree tree = NULL;
  int min;

  // Test 1: Inserting values into the tree
  printf("Test 1: Inserting values into the tree\n");
  tree = *tree_insert(3, &tree);
  tree = *tree_insert(1, &tree);
  tree = *tree_insert(0, &tree);
  tree = *tree_insert(2, &tree);
  tree = *tree_insert(6, &tree);
  tree = *tree_insert(8, &tree);
  tree = *tree_insert(10, &tree);
  printf("Expected structure: 3 at root with left and right subtrees "
         "containing values 0-10\n\n");

  // Test 2: Checking membership of certain values
  printf("Test 2: Checking membership\n");
  printf("Is 6 in the tree? %s\n", tree_member(6, &tree) ? "Yes" : "No");
  printf("Is 4 in the tree? %s\n", tree_member(4, &tree) ? "Yes" : "No");
  printf("Is 10 in the tree? %s\n", tree_member(10, &tree) ? "Yes" : "No");
  printf("Expected results: Yes, No, Yes\n\n");

  // Test 3: Finding and removing the minimum value
  printf("Test 3: Removing minimum value\n");
  pop_minimum(&tree, &min, &tree);
  printf("Minimum value removed: %d\n", min);
  printf("Expected minimum: 0\n\n");

  // Test 4: Freeing the tree
  printf("Test 4: Freeing the tree\n");
  tree_free(&tree);
  printf("Tree should now be freed and empty.\n\n");
}

int main() {
  run_tests();
  return 0;
}
