//FitnessData_2023.csv

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#include <math.h>

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char choice;
int counter = 0;
char stringsteps[10];
FITNESS_DATA data[100];
int buffer_size = 100;
float mean = 0;
int u = 0;
int w = 0;
int t = 0;
char lowest[1000];

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
            else{
                printf("File successfully loaded.\n");
            }
            break;

        case 'B':
        case 'b':
            counter = 0;
        
            while (fgets(line, buffer_size, input) != NULL)
            {
                counter ++;
            }

            printf("Number of records in file: %d\n",counter);
            break;

        case 'C':
        case 'c':
            data;

            counter = 0;
            while (fgets(line, buffer_size, input))
            {
                // split up the line and store it in the right place
               // using the & operator to pass in a pointer to the bloodIron so it stores it
                tokeniseRecord(line, ",", data[counter].date, data[counter].time, stringsteps);
                if (lowest > data[counter].steps)
                {
                    lowest = data[counter].date;
                }
                counter++;
            }
            printf("Your lowest blood iron was %.2s\n", lowest);
            fclose(input);
            break;


        case 'D':
        case 'd':
            
            break;

        case 'E':
        case 'e':
            mean = 0;
            counter = 0;

            while (fgets(line, buffer_size, input) != NULL)
            {
                FITNESS_DATA data;

                tokeniseRecord(line, ",", data.date, data.time, stringsteps);
                mean += atoi(stringsteps);
                counter ++;
            }

            mean = mean/counter;
            printf("Mean step count: %.0f\n", mean);
            break;

        case 'F':
        case 'f':
            
            break;

        case 'G':
        case 'g':
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
}