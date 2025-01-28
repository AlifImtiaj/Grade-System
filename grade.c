#include "grade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ShowInformation(struct Student* std) {
    printf("\nName : %s", std->name);
    printf("\nRoll : %d", std->roll);
}

void TakeInformation(struct Student* std) {

    printf("\nEnter name : ");
    scanf("%256[^\n]", std->name); // take input until new line (Enter) is pressed

    printf("\nEnter roll : ");
    scanf("%d", &std->roll);


    int totalCourses;
    printf("Enter total course : ");
    scanf("%d",&totalCourses);


    SaveStudentInfo(std, totalCourses);

}

void SaveStudentInfo(struct Student *std, int totalCourses)
{

    struct Course* courses = (struct Course*) malloc(sizeof(struct Course) * totalCourses);

    char str1[50];
    char filePath[200] = "data/";
    sprintf(str1, "%d",std->roll);
    strcat(str1, ".txt");
    strcat(filePath, str1);

    FILE* fp = fopen(filePath, "r");

    if (fp != NULL) {
        printf("Student information already exists. Please use overwrite fucntion to overwrite data!!!\n");
        fclose(fp);
        free(courses);
        return;
    }
    fp = fopen(filePath, "w");

    if (fp == NULL) {
        printf("Error while creating file!!!");
        return;
    }

    fprintf(fp, "Name : %s\t\t\tRoll : %d\n", std->name, std->roll);

    for (int i = 0; i < totalCourses; i++) {
        ClearInputBuffer();
        printf("Course name : ");
        scanf("%80[^\n]",courses[i].name);
        printf("Number : ");
        scanf("%f",&courses[i].number);
    }

    fprintf(fp, "Course name\t\t\t\tNumber\n");
    for (int i = 0; i < totalCourses; i++) {
        fprintf(fp, "%s\t\t\t\t%f\n", courses[i].name, courses[i].number);
    }

    free(courses);
    fclose(fp);
}

void SearchStudentInfo(int roll) {
    char str1[50]; // to store roll in it
    char filePath[200] = "data/";

    char line[500];

    sprintf(str1, "%d", roll);
    strcat(str1, ".txt");
    strcat(filePath, str1);

    FILE* fp = fopen(filePath, "r");
    if (fp == NULL) {
        printf("Student information does not exists!!!\n");
        return;
    }

    while(!feof(fp)) {
        if (fgets(line, sizeof(line), fp) != NULL)
            printf("%s", line);
    }

    fclose(fp);
    
}

void ClearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}