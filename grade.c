#include "grade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AddStudentInformation(struct Student* std) {
    FILE* fp;

    printf("Name : ");
    scanf("%256[^\n]",&std->name);
    printf("Roll : ");
    scanf("%d",&std->roll);

    char str1[50];
    char filePath[200] = "data/";
    sprintf(str1, "%d",std->roll);
    strcat(str1, ".txt");
    strcat(filePath, str1);
    fp = fopen(filePath, "r");

    if (fp != NULL) {
        printf("Student information already exists!!!\n");

        fclose(fp);
        return;
    }


    fp = fopen(filePath, "w");

    if (fp == NULL) {
        printf("Error while creating file!!!\n");
        return;
    }

    fprintf(fp, "Name : %s\t\t\tRoll : %d\n", std->name, std->roll);

}

void AddMark(int roll) {
    char sem[50];

    char str1[50]; // to store roll in it
    char filePath[200] = "data/";

    sprintf(str1, "%d", roll);
    strcat(str1, ".txt");
    strcat(filePath, str1);

    FILE* fp = fopen(filePath, "r");
    if (fp == NULL) {
        printf("Student information does not exists!!!\n");
        return;
    }
    fclose(fp);

    fp = fopen(filePath, "a");

    ClearInputBuffer();

    printf("Semester name : ");
    scanf("%50[^\n]", sem);

    fprintf(fp, "%s\n",sem);

    int totalCourses;
    printf("Enter total course : ");
    scanf("%d",&totalCourses);
    ClearInputBuffer();

    struct Course* courses = (struct Course*) malloc(sizeof(struct Course) * totalCourses);
    if (courses == NULL) {
        printf("Memory Allocation Error 102!!!\n"); // 102 = courses memory allocation
        return;
    }
    float* gp = (float*)malloc(sizeof(float)*totalCourses);
    if (gp == NULL) {
        printf("Memory Allocation Error 103!!!\n");
        free(courses);
        return;
    }

    for (int i = 0; i < totalCourses; i++) {
        ClearInputBuffer();

        printf("Course name : ");
        scanf("%80[^\n]",courses[i].name);

        printf("Number : ");
        scanf("%f",&courses[i].number);
        gp[i] = CalculateGPA(&courses[i]);
    }

    int courseCount = 0;
    float cg = 0;
    for (int i = 0; i < totalCourses; i++) {
        if (gp[i] == 0)
            continue;
        
        courseCount++;
        cg += gp[i];
    }
    cg = cg / courseCount;

    fprintf(fp, "Course name\t\tNumber\t\tGrade letter\t\tGrade point\n");

    for (int i = 0; i < totalCourses; i++) {
        fprintf(fp, "%s\t\t%.2f\t\t%s\t\t\t%.2f\n", courses[i].name,
        courses[i].number, courses[i].gl, courses[i].gp);
    }
    fprintf(fp, "CGPA : %.2f", cg);

    free(gp);
    free(courses);
    fclose(fp);

}

void ShowInformation(struct Student *std)
{
    printf("\nName : %s", std->name);
    printf("\nRoll : %d", std->roll);
}

float CalculateGPA(struct Course* crs) {
    float marks = crs->number;
    while (marks > 100 || marks < 0) {
        printf("\nOut of range, please input between 0 to 100\nNumber : ");
        scanf("%f",&marks);
    }
    crs->number = marks;

    if (marks >= 0 && marks < 40) {
        strcpy(crs->gl, "F");
        crs->gp = 0;
    } else if (marks >= 40 && marks < 45) {
        strcpy(crs->gl, "D");
        crs->gp = 2.0;
    } else if (marks >= 45 && marks < 50) {
        strcpy(crs->gl, "C");
        crs->gp  = 2.25;
    } else if (marks >= 50 && marks < 55) {
        strcpy(crs->gl, "C+");
        crs->gp = 2.5;
    } else if (marks >= 55 && marks < 60) {
        strcpy(crs->gl, "B-");
        crs->gp = 2.75;
    } else if (marks >= 60 && marks < 65) {
        strcpy(crs->gl, "B");
        crs->gp = 3.0;
    } else if (marks >= 65 && marks < 70) {
        strcpy(crs->gl, "B+");
        crs->gp = 3.25;
    } else if (marks >= 70 && marks < 75) {
        strcpy(crs->gl, "A-");
        crs->gp = 3.5;
    } else if (marks >= 75 && marks < 80) {
        strcpy(crs->gl, "A");
        crs->gp = 3.75;
    } else {
        strcpy(crs->gl, "A+");
        crs->gp = 4.0;
    }
    return crs->gp;

}



void SaveStudentInfo(struct Student *std, int totalCourses)
{
    struct Course* courses = (struct Course*) malloc(sizeof(struct Course) * totalCourses);
    if (courses == NULL) {
        printf("Error allocating memory for course structure!!!\n");
        return;
    }
    float* gpa = (float*)malloc(sizeof(float)*totalCourses);
    if (gpa == NULL) {
        printf("Error allocating memory for gpa!!!\n");
        return;
    }

    char str1[50];
    char filePath[200] = "data/";
    sprintf(str1, "%d",std->roll);
    strcat(str1, ".txt");
    strcat(filePath, str1);

    FILE* fp = fopen(filePath, "r");

    if (fp != NULL) {
        printf("Student information already exists!!!\n");

        fclose(fp);

        free(courses);
        free(gpa);

        return;
    }

    for (int i = 0; i < totalCourses; i++) {
        ClearInputBuffer();

        printf("Course name : ");
        scanf("%80[^\n]",courses[i].name);

        printf("Number : ");
        scanf("%f",&courses[i].number);
        gpa[i] = CalculateGPA(&courses[i]);
    }

    int courseCount = 0;
    float cg = 0;
    for (int i = 0; i < totalCourses; i++) {
        if (gpa[i] == 0)
            continue;
        
        courseCount++;
        cg += gpa[i];
    }
    cg = cg / courseCount;


    fp = fopen(filePath, "w");

    if (fp == NULL) {
        printf("Error while creating file!!!\n");

        free(courses);
        free(gpa);

        return;
    }

    fprintf(fp, "Name : %s\t\t\tRoll : %d\n", std->name, std->roll);

    fprintf(fp, "Course name\t\tNumber\t\tGrade letter\t\tGrade point\n");

    for (int i = 0; i < totalCourses; i++) {
        fprintf(fp, "%s\t\t%.2f\t\t%s\t\t\t%.2f\n", courses[i].name,
        courses[i].number, courses[i].gl, courses[i].gp);
    }
    fprintf(fp, "CGPA : %.2f", cg);

    free(gpa);
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