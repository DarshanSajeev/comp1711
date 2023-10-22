#include <stdio.h>
int prime(int number)
{
    if (number % 2 == 0 | number % 3 == 0 | number % 4 == 0 | number % 5 == 0 | number % 6 == 0 | number % 7 == 0 | number % 8 == 0 | number % 9 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (prime(number) == 1)
    {
        printf("The number is not prime");
    }
    else
    {
        printf("The number is prime");
    }
    return 0;
}