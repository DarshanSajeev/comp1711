#include <stdio.h>

int main() {
    int int1, int2, sum;
    printf("What is the first number? ");
    scanf ("%d", &int1);
    printf("What is the second number? ");
    scanf ("%d", &int2);
    sum = int1 + int2;
    printf("%d", sum);

    return 0;
}