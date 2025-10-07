#include <stdio.h>

void swap(int a, int b) { // arguments are copied in their own variable
    int t = a;
    a = b;
    b = t;
    printf("swap: a = %d, b = %d\n", a, b);
};

int main(void) {
    int a = 21;
    int b = 17;

    swap(a, b);
    // original values remain unchanged
    printf("main: a = %d, b = %d\n", a, b);
    return 0;
}