#include <stdio.h>
//Creates the start of the program 
int main() {
    //Creates a string with a max of 15 characters 
    char name[15];

    printf("Hello, please enter your name: ");
    //Takes in the input and stores it in name
    scanf("%s", &name);
    printf("Your name is %s\n", name);
    
    //Returns 0 if success 
    return 0;
}