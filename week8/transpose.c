#include <stdio.h>
#include <string.h>

int main(){
    int array[2][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            array[i][j] = rand() % 11; // Generates random values between 0 and 10
        }
    }
}