#include <stdio.h>

float area(float radius)
{
    float area_ = radius * radius * 3.14 * 4;
}

int main()
{
    float radius;
    printf("Enter the radius of the sphere: ");
    scanf("%f",&radius);
    printf("The area of the sphere is %f", area(radius));
}