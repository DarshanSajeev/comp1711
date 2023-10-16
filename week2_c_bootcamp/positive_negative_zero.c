#include <stdio.h>

int main(){
    int num = -2125;

    if (num > 0)
    {
        printf("%d is positive \n", num);
    }
    else if (num < 0)
    {
        printf("%d is negative \n", num);  
    }
    else
    {
        printf("%d is zero \n", num);
    }
}