#include <stdio.h>
#include <stdlib.h>

void con_fraction(int numer, int denom) {
    if (denom == 0) {
        return;
    }
    if (denom == 1) {
        printf("%d ", numer);
    } else {
        printf("%d ", (numer / denom));
        con_fraction(denom, (numer % denom));
    }
}

void main() {
    int numer, denom;
    scanf("%d", &numer);
    if (numer <= 0) {
        printf("numerator must be a positive integer.\n");
        exit(1);
    }
    scanf("%d", &denom);
    if (denom <= 0) {
        printf("denominator must be a positive integer.\n");
        exit(1);
    }
    printf("Your input: %d/%d\n", numer, denom);
    con_fraction(numer, denom);
    printf("\n");
}