#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
int buffer_size = 100;
char choice;
int counter;

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


// Complete the main function
int main() {
    char line[buffer_size];
    char filename[buffer_size];

    while (1)
    {

        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit the program\n");

        // get the next character typed in and store in the 'choice'
        printf("\nEnter an option: ");
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the sdin and be read next time
        while (getchar() != '\n');

        char line[buffer_size];
        char filename[buffer_size];
        
        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':

            // get filename from the user
            printf("Please enter the name of the data file: ");

            // these lines read in a line from the stdin (where the user types)
            // and then takes the actual string out of it
            // this removes any spaces or newlines.
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", filename);

            FILE *input = fopen(filename, "r");
            if (!input)
            {
                printf("Error: File could not be opened\n");
                return 1;
            }
            
            break;

        case 'B':
        case 'b':
            while (fgets(line, buffer_size, filename) != NULL)
            {
                noOfRecords += 1;
            }

            printf("Number of records in file: %d\n",noOfRecords - 1);
            break;

        case 'C':
        case 'c':
            break;

        case 'D':
        case 'd':
            break;

        case 'E':
        case 'e':
            break;

        case 'F':
        case 'f':

            break;

        case 'G':
        case 'g':
            break;

        case 'Q':
        case 'q':
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}