#include <stdio.h>

char concatStrings(char string1, char string2)
{
    char newString;
    newString = string1 + string2;
    return newString;
}

int main()
{
    printf(concatStrings("Hello ", "World"));
}