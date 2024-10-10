#define STR_LARGE 100

// Define a Node Structure
typedef struct node {
    char task[STR_LARGE];
    struct node *next;
} NODE;

// Create a new node
NODE *createNode(char *task);

// Add a new task to the list
// **start needs 2 stars to pass the pointer by reference instead of by copy
void addNode(NODE **start, NODE *newNode);

// Print all tasks in list
void printNodes(NODE *start);