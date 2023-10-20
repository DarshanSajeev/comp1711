#include <stdio.h>

int area(const radius)
{
    int area_ = radius * radius * 3.14;
}

int main()
{
    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f",&radius);
    printf("The area of th circle is %f", area(radius));
}