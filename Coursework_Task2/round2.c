#include "FitnessDataStruct.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

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
    int buffer_size;
    char line[buffer_size];
    char filename[buffer_size];

    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);
    
    FILE *file = open_file(filename, "r");
    FITNESS_DATA data;
    char stringsteps[1000000000];
    tokeniseRecord(filename, ",", data.date, data.time, stringsteps);

    
}