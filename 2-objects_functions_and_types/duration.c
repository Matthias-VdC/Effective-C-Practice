#include <stdio.h>

void increment(void) {
    // static = make lifetime static (entire program lifecycle) 
    // unsigned = can only hold positive values and 0
    static unsigned int counter = 0; // scope does not change ; only visible within increment function
    counter++;
    printf("%d\n", counter);
}

int main(void) {
    for(int i = 0 ; i < 5 ; i++) {
        increment();
    }
    return 0;
}

/*
int *func(int i) {
    const int j = i; // ok
    static int k = j; // error ; static objects cannot be initialized with a variable
    return &k;
}
*/