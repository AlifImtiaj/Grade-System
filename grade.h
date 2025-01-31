#pragma once

struct Student {
    char name[256];
    int roll;
};


struct Course {
    char name[80];
    float number;
    float courseCredit;
    float gp;
    char gl[3]; // grade letter
};

void AddStudentInformation(struct Student* std);
void AddMark(int roll);

void ShowInformation(struct Student* std);
void SaveStudentInfo(struct Student* std, int totalCourses);
void SearchStudentInfo(int roll);

float CalculateGPA(struct Course* crs);
void ClearInputBuffer();