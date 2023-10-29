#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
int noOfRecords = 0;


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

int main(int noOfRecords) 
{
    char filename [] = "FitnessData_2023.csv";
    char stringsteps[10];
    
    FILE *file = open_file(filename, "r");
    FITNESS_DATA data;

    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        tokeniseRecord(line_buffer, ",", data.date, data.time, stringsteps);
        noOfRecords += 1;
        //printf("Date: %s\n", data.date);
        //printf("Time: %s\n", data.time);
        //printf("Steps: %s\n", stringsteps);
        if (noOfRecords <= 4)
        {
            printf("%s,%s,%s", data.date, data.time, stringsteps);
        }
    }
    printf("Number of Records in this file: %d\n",noOfRecords - 1);
    
    fclose(file);
    return 0;
}