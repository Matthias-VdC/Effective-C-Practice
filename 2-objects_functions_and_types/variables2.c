#include <stdio.h>

void swap(int *pa, int *pb) { // * references the address in memory
    int t = *pa;
    *pa = *pb;
    *pb = t;
    printf("swap: a = %d, b = %d\n", *pa, *pb);
};

int main(void) {
    int a = 21;
    int b = 17;

    swap(&a, &b); // & is the address of the variable
    printf("main: a = %d, b = %d\n", a, b);
    return 0;
}
