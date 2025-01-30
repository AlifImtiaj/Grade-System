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

    int choice;
    int totalNumberOfStudent;
    int roll;

    printf("1. Add student information\n");
    printf("2. Add marks for semester\n");
    printf("3. Search student information\n");
    printf("4. Exit\n");
    do {
        printf("Enter : ");
        scanf("%d",&choice);
        ClearInputBuffer();

        switch (choice)
        {
        case 1:
            printf("Total students : ");
            scanf("%d",&totalNumberOfStudent);

            struct Student* students = (struct Student*)malloc(sizeof(struct Student)*totalNumberOfStudent);

            if (students == NULL) {
                printf("Memory Allocation failed 101!!!\n");
                return 1;
            }

            for (int i = 0; i < totalNumberOfStudent; i++) {
                ClearInputBuffer();
                AddStudentInformation(&students[i]);
            }

            free(students);

            break;
        case 2:
            printf("Roll : ");
            scanf("%d",&roll);

            AddMark(roll);

            break;
        case 3:
            printf("Roll : ");
            scanf("%d",&roll);
            SearchStudentInfo(roll);

            break;
        case 4:
            printf("Exiting the program\n");
            return 0;

        default:
            printf("Enter correct option!!!\n");
            break;
        }


    } while(choice < 1 || choice > 4);
    

    // int roll;
    // printf("Enter roll to search : ");
    // scanf("%d",&roll);

    // SearchStudentInfo(roll);

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