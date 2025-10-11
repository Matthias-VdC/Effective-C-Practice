#include <stdio.h>
#include <string.h>

struct sigrecord {
  int signum; // 4 bytes
  char signame[20]; // 20 bytes
  char sigdesc[100]; // 100 bytes
} sigline, *sigline_p;
/**
struct sigrecord sigline;
struct sigrecord *sigline_p;
*/

int main(void) {
    sigline.signum = 5;
    // strcpy copies a string into an array
    strcpy(sigline.signame, "SIGINT");
    strcpy(sigline.sigdesc, "Interrupt from keyboard");

    // assign the address of sigline to sigline_p
    sigline_p = &sigline;

    // -> is used to assign values to the same sigline structure
    // assigns the exact same values to the same address as previously
    sigline_p->signum = 5;
    strcpy(sigline_p->signame, "SIGINT");
    strcpy(sigline_p->sigdesc, "Interrupt from keyboard");

    // Converts unsigned long to int. Boundary will not be reached here.
    printf("%d\n", sizeof(struct sigrecord));
    printf("signum: %d, signame: %s, sigdesc: %s\n", sigline.signum, sigline.signame, sigline.sigdesc);

    return 0;
}
