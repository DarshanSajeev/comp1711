#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printColumn(int a[][4], int colIndex, int rows, char when) {
    switch (when) {
        case 'B':
            printf("Values in column %d before change:\n", colIndex); break;

        case 'A':
            printf("Values in column %d after change:\n", colIndex); break;

        default: 
            printf("Invalid option\n");
            return;
    }

    for (int i = 0; i < rows; ++i) {
        printf("%d\n", a[i][colIndex]);
    }
}

void changeColumn(int a[][4], int colIndex, int rows, int newValue) {
    for (int i = 0; i < rows; ++i) {
        a[i][colIndex] = newValue;
    }
}

int main() {
    int array1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int array[3][4];
    int i, j;

    // Seed the random number generator
    srand(time(NULL));

    // Assign random values to each element of the array
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            array[i][j] = rand() % 11; // rand() % 11 gives a range 0 to 10
        }
    }

    // Print the array to verify
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;

    int colIndexToChange = 2; // Change the values in the third column (column at index 2)
    int newValue = 20;

    printColumn(array1, colIndexToChange, 3, 'B'); // 'B' stands for Before
    changeColumn(array1, colIndexToChange, 3, newValue);
    printColumn(array1, colIndexToChange, 3, 'A'); // 'A' stands for After
    printColumn(array, colIndexToChange, 3, 'B');

    return 0;
}