#include <stdio.h>

int main() {
    int side1;
    int side2;
    int area;
    printf("What is the length of the first side? ");
    scanf ("%d", &side1);
    printf("What is the length of the second side? ");
    scanf ("%d", &side2);
    area = side1 * side2;
    printf("The area of the rectangle is %d.\n", area);

    return 0;
}