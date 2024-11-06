
typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Tree;

/*
 * Check if integer x is a member of the tree.
 * Return 1 if x is a member of the tree, 0 otherwise.
 *
 * @param x: integer to check
 * @param tree: binary tree
 */
int tree_member(int x, Tree *tree);

/*
 * Free all memory associated with the tree
 *
 * @param tree: binary tree
 */
void tree_free(Tree *tree);

/*
 * Insert integer x into the tree.
 * If x is already in the tree, do nothing.
 * Return a pointer to the tree.
 *
 * @param x: integer to insert
 * @param tree: binary tree
 */
Tree *tree_insert(int x, Tree *tree);

/*
 * Remove the minimum value from the tree.
 * Set min to the minimum value removed.
 * Set new_tree to the tree with the minimum value removed.
 *
 * @param tree: binary tree
 * @param min: pointer to integer to store minimum value
 * @param new_tree: pointer to tree to store new tree
 */
void pop_minimum(Tree *tree, int *min, Tree **new_tree);
