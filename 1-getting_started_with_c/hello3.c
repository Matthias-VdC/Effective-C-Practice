#include <stdio.h>
#include <stdlib.h>

int main(void) {
        if(printf("%s\n", "Hello World!") == EOF) {
            // \n is for the next print to appear on the next line
            // %s is a string placeholder. which printf replaces with the 2nd argument.
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
