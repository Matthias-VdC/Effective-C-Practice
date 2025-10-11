#include <stdio.h>

void func(int arr[5]) {};

int main(void) {
    unsigned int i = 0;
    unsigned int j = 0;
    int arr[3][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };
    func(arr[i]);
    int x = arr[i][j];
    printf("%d\n", x); // prints [0][0]
    return 0;
}