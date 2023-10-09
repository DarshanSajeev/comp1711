#include <stdio.h>

int main() {
    float radius, area;
    printf("What is the radius of the circle? ");
    scanf ("%f", &radius);
    area = 3.14 * radius * radius;
    printf("%f", area);

    return 0;
}