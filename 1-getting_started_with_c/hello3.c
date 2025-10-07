#include <stdio.h>
#include <stdlib.h>

int main(void) {
        if(printf("%s\n", "Hello World!") == EOF) { // \n is for the next print to appear on the next line
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
