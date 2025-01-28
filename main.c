#include "grade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include <direct.h>
    #include <io.h>
#else
    #include <sys/stat.h>
    #include <unistd.h>
#endif

void CreateDir();

int main() {
    CreateDir();
    

    int totalNumberOfStudent;
    printf("Total students : ");
    scanf("%d",&totalNumberOfStudent);

    struct Student* students = (struct Student*)malloc(sizeof(struct Student)*totalNumberOfStudent);


    for(int i = 0; i < totalNumberOfStudent; i++) {
        ClearInputBuffer(); // clears the input buffer
        TakeInformation(&students[i]);
        // SaveStudentInfo(&students[i]);
    }


    free(students);




    // struct Student student[10];

    // for (int i = 0; i < sizeof(student)/sizeof(student[0]); i++) {
    //     student[i] = TakeInformation();
    //     SaveStudentInfo(&student[i]);
    //     fflush(stdin); // clears the input buffer
    // }

    // struct Course* courses = (struct Course*) malloc(sizeof(struct Course)*5);
    // strcpy(courses[2].name, "Alif Imtiaj");

    // printf("%s",courses[2].name);

    // free(courses);

    int roll;
    printf("Enter roll to search : ");
    scanf("%d",&roll);

    SearchStudentInfo(roll);

    return 0;

}

void CreateDir() {
    #ifdef _WIN32
        if (_access("data", 0) != 0) {
            if (_mkdir("data") != 0) {
                perror("Error creating folder");
            }
        }
    #else
        struct stat st = {0};
        if (stat("data", &st) == -1) {
            if (mkdir("data", 0755) != 0) {
                perror("Error creating folder");
            }
        }
    #endif
}