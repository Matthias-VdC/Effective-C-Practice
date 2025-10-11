#include <stdio.h>

int main (void) {
    char str[11];
    for(unsigned int i = 0; i < 10; i++) {
        // from the char 'o' in memory (111)
        // goes 1 further from this point in memory
        str[i] = 'o' + i;
        // is equal to:
        // *(str + i) = (char)(111 + i)
    }
    str[10] = '\0'; // Marks the end of a string (null terminator/character). ASCII value 0.
    printf("%s\n", str);
    return 0;
}
