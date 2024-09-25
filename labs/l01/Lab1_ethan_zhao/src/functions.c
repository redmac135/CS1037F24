
#include "functions.h"

void parameters(int argc, char *const argv[]) {
    // print header
    printf("Program Parameters:\n\n");

    // if no arguments passed, then print notice and return
    if (argc == 1) {
        printf("no arguments passed.");
        return;
    }

    // otherwise, print each argument started with the second element in the argv array
    // this is to avoid the first element which is the command
    for (int i = 1; i < argc; i++) {
        printf("argument %d: %s\n", i, argv[i]);
    }
}
