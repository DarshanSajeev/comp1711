#include <stdio.h>

int main() 
{
    //Creates a file with the name data.txt
    char filename [] = "data.txt";
    //Opens the file in write and creates a pointer to the file
    FILE *file = fopen(filename, "w");// "a", "r", "w+", "a+", "r+"
    //If the file does not work for any reason, the error message "" pops up
    if (file == NULL) 
    {
        perror("");
        return 1;
    }

    fclose(file);
    return 0;
}