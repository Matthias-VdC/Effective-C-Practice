#include <stdio.h>

int j; // j = file scope

void f(int i) { // i = block scope
    int j = 1;  // j = block scope ; hides file scope j
    i++;
    for(int i = 0 ; i < 2 ; i++) { // i = block scope in loop
        int j = 2; // j = block scope ; hides outer j
        printf("%d\n", j); // prints block scoped j (2)
    }
    printf("%d\n", j); // j = outer j in scope (1)
}
void g(int j); // j = function prototype scope ; hides file-scope j

int main(void){
    f(0);
    return 0;
}

