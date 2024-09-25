
#include "functions.h"

int main(int argc, char *argv[]) {
    // Set stdout buffering to NULL for immediate console output (useful in some environments).
    setbuf(stdout, NULL);

    // Call the function to handle and print the parameters.
    parameters(argc, argv);

    return 0;
}
