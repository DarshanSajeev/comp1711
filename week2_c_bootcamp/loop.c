#include <stdio.h>
#include <stdbool.h>

int main(){
    int num;
    bool loop = true;
    while (loop == true)
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num == -1)
        {
            loop = false;
            printf("Terminated\n");
        }
        else if (100 >= num && num >= -1)
        {
            
        }
        else
        {
            printf("Enter a number between 0 and 100\n");
        }
    }
}