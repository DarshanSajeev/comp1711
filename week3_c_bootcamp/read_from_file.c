#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char filename[], char mode[])
    {
        FILE *file = fopen(filename, mode);
        if (file == NULL)
        {
            perror("");
            exit(1); // Exits program with return status 1.
        }
        return file;
    }

int main() 
{
    char filename [] = "data.txt";
    FILE *file = open_file(filename, "r");

    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        printf("%s", line_buffer);
        //atoi changes a string to an int
    }

    fclose(file);
    return 0;
}