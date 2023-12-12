#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "FitnessDataStruct.h"

#define MAX_RECORDS 1000
#define BUFFER_SIZE 100

FITNESS_DATA data[MAX_RECORDS];
int buffer_size = BUFFER_SIZE;
char date[11];
char time[6];
char steps[10];

void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps) {
    char *inputCopy = strdup(input);
    char *token = strtok(inputCopy, delimiter);

    if (token != NULL) {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }

    free(inputCopy);
}

void openFile(const char *filename) {
    
    input = fopen(filename, "r");
    if (input != NULL) {
        fclose(input);
    }


    if (!input) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    counter = 0;

    while (fgets(line, buffer_size, input) != NULL) {
        tokeniseRecord(line, ",", date, time, steps);
        strncpy(data[counter].date, date, sizeof(data[counter].date));
        strncpy(data[counter].time, time, sizeof(data[counter].time));
        data[counter].steps = atoi(steps);
        counter++;
    }
}

void displayTotalRecords() {
    printf("Total records: %i\n", counter);
}

void findFewestSteps() {
    if (counter > 0) {
        for (int i = 1; i < counter; i++) {
            if (data[i].steps < data[lowest].steps) {
                lowest = i;
            }
        }
        printf("Time slot with fewest steps: %s %s\n", data[lowest].date, data[lowest].time);
    }
}

void findLargestSteps() {
    if (counter > 0) {
        for (int i = 1; i < counter; i++) {
            if (data[i].steps > data[highest].steps) {
                highest = i;
            }
        }
        printf("Time slot with largest steps: %s %s\n", data[highest].date, data[highest].time);
    }
}

void calculateMeanSteps() {
    if (counter > 0) {
        for (int i = 0; i < counter; i++) {
            mean += data[i].steps;
        }
        mean = mean / counter;

        int rounded = (mean - (int)mean) > 0 ? (int)mean + 1 : (int)mean;
        printf("Mean step count: %d\n", rounded);
    }
}

void findLongestPeriodAbove500Steps() {
    if (counter > 0) {
        for (int i = 0; i < counter; i++) {
            if (data[i].steps > 500) {
                if (currentStart == -1) {
                    currentStart = i;
                }
            } else {
                if (currentStart != -1) {
                    if ((start == -1) || (i - currentStart > end - start)) {
                        start = currentStart;
                        end = i;
                    }
                    currentStart = -1;
                }
            }
        }

        if ((currentStart != -1) && (counter - currentStart > end - start)) {
            start = currentStart;
            end = counter;
        }

        if (start != -1) {
            printf("Longest continuous period above 500 steps start: %s %s\n", data[start].date, data[start].time);
            printf("Longest continuous period above 500 steps end: %s %s\n", data[end - 1].date, data[end - 1].time);
        }
    }
}

int main() {
    char line[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    char user_input;

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

        switch (user_input) {
            case 'A':
            case 'a':
                printf("Input filename: ");
                fgets(line, buffer_size, stdin);
                sscanf(line, " %s ", filename);
                openFile(filename);
                break;

            case 'B':
            case 'b':
                displayTotalRecords();
                break;

            case 'C':
            case 'c':
                findFewestSteps();
                break;

            case 'D':
            case 'd':
                findLargestSteps();
                break;

            case 'E':
            case 'e':
                calculateMeanSteps();
                break;

            case 'F':
            case 'f':
                findLongestPeriodAbove500Steps();
                break;

            case 'Q':
            case 'q':
                if (input != NULL) {
                    fclose(input);
                }
                return 0;
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
