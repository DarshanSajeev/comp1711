#include <stdio.h>

int main(){
    int option;
    printf("Pick an option: ");
    scanf("%d", &option);
    switch (option)
    {
        case 1: printf("Menu option 1 selected\n");
        break;

        case 2: printf("Menu option 2 selected\n");
        break;

        case 3: printf("Menu option 3 selected\n");
        break;

        case 4: printf("Menu option 4 selected\n");
        break;

        case 5: printf("Menu option 5 selected\n");
        break;

        default: printf("Pick a number between 1 and 5\n");
    }
    return 0;
}