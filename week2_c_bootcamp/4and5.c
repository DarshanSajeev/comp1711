#include <stdio.h>

int main(){
    int num;
    printf("Insert a number: ");
    scanf("%d",&num);

    if (((num % 4) == 0) || ((num % 5) == 0))
    {
        printf("%d is divisible by 4 or 5\n", num);
    }
    else
    {
        printf("The number is not divisible by 4 or 5\n");
    }
}