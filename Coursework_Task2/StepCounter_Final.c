#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
FITNESS_DATA data[1000];
int buffer_size = 100;
char user_input;
int counter = 0;
int lowest = 0;
int highest = 0;
double mean = 0.0;
int start = -1;
int end = -1;
int currentStart = -1;
FILE *input = NULL; // File pointer is initialized to NULL
int i;
char date[11];
char time[6]; 
char steps[10];

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

    while (1) {
        printf("A: Specify the filename to be imported - you need to check that the file opened correctly.\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");                     
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");                    
        printf("E: Find the mean step count of all the records in the file\n");       
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");                   
        printf("Q: Exit\n");

        user_input = getchar();
        while (getchar() != '\n');
        
        char line[buffer_size];
        char filename[buffer_size];

        switch (user_input) {
            case 'A':
            case 'a':
                if (input != NULL) {
                    fclose(input);
                }

                printf("Input filename: ");
                fgets(line, buffer_size, stdin);
                sscanf(line, " %s ", filename);

                input = fopen(filename, "r");
                if (!input) {
                    printf("Error: File could not be opened\n");
                    return 1;
                }
                // Reset the counter when a new file is opened
                counter = 0;
                while (fgets(line, buffer_size, input) != NULL) {
                    tokeniseRecord(line, ",", date, time, steps);
                    strncpy(data[counter].date, date, sizeof(data[counter].date));
                    strncpy(data[counter].time, time, sizeof(data[counter].time));
                    data[counter].steps = atoi(steps);
                    counter++;
                }
                break;

            case 'B':
            case 'b':

                printf("Total records: %i\n", counter);

                break;
        
            case 'C':
            case 'c':
                if (counter > 0) 
                {   

                    for (i = 1; i < counter; i++) 
                    {

                        if (data[i].steps < data[lowest].steps) 
                        {

                            lowest = i;

                        }
                    }

                    printf("Fewest steps: %s %s\n", data[lowest].date, data[lowest].time);
                } 
                break;

            case 'D':
            case 'd':
                if (counter > 0) 
                {
                    
                    for (i = 1; i < counter; i++) 
                    {

                        if (data[i].steps > data[highest].steps) 
                        {
                            highest = i;
                        }
                    }
                    printf("Largest steps: %s %s\n", data[highest].date, data[highest].time);
                } 
                break;

            case 'E':
            case 'e':
                if (counter > 0) {
                    for (int i = 0; i < counter; i++) {
                        mean += data[i].steps;
                    }
                    mean = mean / counter;

                    // Check for fractional part
                    int rounded = (mean - (int)mean) > 0 ? (int)mean + 1 : (int)mean;

                    printf("Mean step count: %d\n", rounded);
                }

                break;


            case 'F':
            case 'f':
                if (counter > 0) {

                    for (i = 0; i < counter; i++) {
                        if (data[i].steps > 500) {
                            if (currentStart == -1) {
                                currentStart = i;
                            }
                        } else {
                            if (currentStart != -1) {
                                // Check if the current period is longer than the longest recorded
                                if ((start == -1) || (i - currentStart > end - start)) {
                                    start = currentStart;
                                    end = i;
                                }
                                currentStart = -1;
                            }
                        }
                    }

                    // Check if the last period is longer than the longest recorded
                    if ((currentStart != -1) && (counter - currentStart > end - start)) {
                        start = currentStart;
                        end = counter;
                    }

                    if (start != -1) {
                        printf("Longest period start: %s %s\n", data[start].date, data[start].time);
                        printf("Longest period end: %s %s\n", data[end - 1].date, data[end - 1].time);
                    } 
                }
                break;


            case 'Q':
            case 'q':
                return 0;
                break;
            
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}