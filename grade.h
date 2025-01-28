#pragma once

struct Student {
    char name[256];
    int roll;
};

struct Course {
    char name[80];
    float number;
    char gpa[3];
};

void ShowInformation(struct Student* std);

void TakeInformation(struct Student* std);
void SaveStudentInfo(struct Student* std, int totalCourses);
void SearchStudentInfo(int roll);
