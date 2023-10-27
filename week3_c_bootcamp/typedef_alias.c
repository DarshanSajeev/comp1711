#include <stdio.h>

typedef struct {
    char name [20];
    char student_id [11]; // Assuming up to 10 digits.
    unsigned mark;
} student;

//int printNames (number_of_students, student students){
    
    //for (int i = 0; i < number_of_students; i++) 
    //{
        //printf("-------------\n");
        //printf("Student name: %s\n", students[i].name);
        //printf("Student ID: %s\n", students[i].student_id);
        //printf("Final mark: %u\n", students[i].mark);
    //}
    
    //printf("-------------\n");

    //return 0;
//}

int main () {
    int number_of_students = 10, i;
    student students [] = {
        {"Darshan", "12345678910", 1234},
        {"Not Darshan", "13246193246", 62},
    }; 

    for (int i = 0; i < number_of_students; i++) 
    {
        printf("-------------\n");
        printf("Student name: %s\n", students[i].name);
        printf("Student ID: %s\n", students[i].student_id);
        printf("Final mark: %u\n", students[i].mark);
    }

    printNames(number_of_students, students)
    
    printf("-------------\n");
    return 0;
}