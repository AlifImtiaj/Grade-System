#include<stdio.h>   /*Declare header(s) or header file(s) for standard input or output*/
#include <stdlib.h>
#include<string.h>

char* grade(int size, float *mark){
	
	// Allocate memory for the array
    char* Gr = (char*)malloc(2*size * sizeof(char));
    
    // Check if memory allocation was successful
    if (Gr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit the program if allocation fails
    }
    
    for(int num=0; num<size; num++)
    if (*(mark+num)<0 || *(mark+num) >100) {
		Gr[num*2]='N';
		Gr[num*2+1]='A';
		/*Gr[num*3+2]='\0';
		GradePoint[num]=0.00;
		printf("Wrong input.\n");*/
		}
	
	else if (*(mark+num)>=80 && *(mark+num)<=100){
		Gr[num*2]='A';
		Gr[num*2+1]='+';
		/*Gr[num*3+2]='\0';
		printf("The grade is %s\n",Gr[num]);
		coursenumber=coursenumber+1;
		GradePoint[num]=4.00;
		printf("The grade is: 'A+'\n");
		printf("The grade point is: %f \n",GradePoint[num]);*/
		}
	
	else if (*(mark+num)>=75 && *(mark+num)<80) {
		Gr[num*2]='A';
		Gr[num*2+1]='\0';
		/*Gr[num*3+2]='\0';
		printf("The grade is %s\n",Gr[num]);
		coursenumber=coursenumber+1;
		GradePoint[num]=3.75;
		/*printf("The grade is: 'A'\n");
		printf("The grade point is: %f \n",GradePoint[num]);*/
	}
	
	else if (*(mark+num)>=70 && *(mark+num)<75) {
		Gr[num*2]='A';
		Gr[num*2+1]='-';
		/*Gr[num*3+2]='\0';
		printf("The grade is %s\n",Gr[num]);
		coursenumber=coursenumber+1;
		GradePoint[num]=3.5;
		/*printf("The grade is 'A-'\n");
		printf("The grade point is: %f \n",GradePoint[num]);*/
	}
	
	else if (*(mark+num)>=65 && *(mark+num)<70) {
		Gr[num*2]='B';
		Gr[num*2+1]='+';
		/*Gr[num*3+2]='\0';
		printf("The grade is %s\n",Gr[num]);
		coursenumber=coursenumber+1;
		GradePoint[num]=3.25;
		/*printf("The grade is 'B+'\n");
		printf("The grade point is: %f \n",GradePoint[num]);*/
	}
	
	else if (*(mark+num)>=60 && *(mark+num)<65) {
		Gr[num*2]='B';
		Gr[num*2+1]='\0';
		/*Gr[num*3+2]='\0';
		printf("The grade is '%s'\n",Gr[num]);
		coursenumber=coursenumber+1;
		GradePoint[num]=3.00;
		/*printf("The grade is 'B'\n");
		printf("The grade point is: %f \n",GradePoint[num]);*/
	}
	
	else if (*(mark+num)>=55 && *(mark+num)<60) {
		Gr[num*2]='B';
		Gr[num*2+1]='-';
		/*Gr[num*3+2]='\0';
		printf("The grade is '%s'\n",Gr[num]);
		coursenumber=coursenumber+1;
		GradePoint[num]=2.75;
		/*printf("The grade is 'B-'\n");
		printf("The grade point is: %f \n",GradePoint[num]);*/
	}
	
	else if (*(mark+num)>=50 && *(mark+num)<55) {
		Gr[num*2]='C';
		Gr[num*2+1]='+';
		/*Gr[num*3+2]='\0';
		printf("The grade is '%s'\n",Gr[num]);
		coursenumber=coursenumber+1;
		GradePoint[num]=2.50;
		/*printf("The grade is 'C+'\n");
		printf("The grade point is: %f \n",GradePoint[num]);*/
	}
	
	else if (*(mark+num)>=45 && *(mark+num)<50) {
		Gr[num*2]='C';
		Gr[num*2+1]='\0';
		/*Gr[num*3+2]='\0';
		printf("The grade is '%s'\n",Gr[num]);
		coursenumber=coursenumber+1;
		GradePoint[num]=2.25;
		/*printf("The grade is 'C'\n");
		printf("The grade point is: %f \n",GradePoint[num]);*/
	}
	
	else if (*(mark+num)>=40 && *(mark+num)<45) {
		Gr[num*2]='D';
		Gr[num*2+1]='\0';
		/*Gr[num*3+2]='\0';
		printf("The grade is '%s'\n",Gr[num]);
		coursenumber=coursenumber+1;
		GradePoint[num]=2.00;
		/*printf("The grade is 'D'\n");
		printf("The grade point is: %f \n",GradePoint[num]);*/
	}
	
	else if (*(mark+num)>=0 && *(mark+num)<40) {
		Gr[num*2]='F';
		Gr[num*2+1]='\0';
		/*Gr[num*3+2]='\0';
		printf("The grade is '%s'\n",Gr[num]);
		GradePoint[num]=0.00;
		/*printf("The grade is 'F'\n");
		printf("The grade point is: %f \n",GradePoint[num]);*/
	}
	
	return Gr;
}

int main(void){
	int numofstds, numofcourse, coursenumber=0, i, j;
	float GP=0, GPA;  /*variable initiliation*/

	printf("Enter number of students.\n");
	scanf("%d",&numofstds);

	printf("Enter number of courses.\n");
	scanf("%d",&numofcourse);   
	
	struct student{
		char name[80];
		float mark[numofcourse]; 
		char grd[2*numofcourse];
	};
	struct student stds[numofstds];
		
	FILE *fptr = fopen("C:/Arif/software/ACD See Collection/ruet/Course Materials/2023 series/ETE 1114/C codes/Lab 10/data/name.txt", "r");
    
    if(fptr==NULL) printf("Error opening file");
	
	/*while(fgets(stds[i].name, sizeof(stds[i].name), fptr)!=NULL){*/
	for (i=0; i<numofstds; i++){
		fgets(stds[i].name, sizeof(stds[i].name), fptr);
		/*printf("%s",stds[i].name);
		i++;*/
	}
	
	fclose(fptr);
	
	char str1[10]; 
	for (i=0; i<numofcourse; i++){
		char str2[200]="C:/Arif/software/ACD See Collection/ruet/Course Materials/2023 series/ETE 1114/C codes/Lab 10/data/course";
		sprintf(str1, "%d", i+1); 
		strcat(str1,".txt");
		strcat(str2,str1);
		puts(str2);
		fptr = fopen(str2, "r");
    
    if(fptr==NULL) printf("Error opening file");
    j=0;
	/*while (fscanf(fptr, "%f", &stds[j].mark[i]) == 1) {*/
	while (j<numofstds) {
		fscanf(fptr, "%f", &stds[j].mark[i]);
		printf("%f\t",stds[j].mark[i]);
        j++;
    }
	printf("\n");
	}	
    
    fclose(fptr);
    
	float a[numofcourse];
	for (i=0; i<numofstds; i++){
		for (j=0; j<numofcourse; j++){
			a[j]=stds[i].mark[j];
		
	}
	char* gr=grade(numofcourse, a);
	printf("\nStudent Name: %s",stds[i].name);
	printf("Course No.\t    Mark\tGrade\n");
	for(int num=0; num<numofcourse; num++){
		stds[i].grd[num*2]=gr[num*2];
		stds[i].grd[num*2+1]=gr[num*2+1];
	printf("Course %d\t %f\t %c%c\t\n",num+1,stds[i].mark[num],stds[i].grd[num*2],stds[i].grd[num*2+1]);

	}
	/*printf("\n");*/
	}
	
	FILE *file_ptr = fopen("C:/Arif/software/ACD See Collection/ruet/Course Materials/2023 series/ETE 1114/C codes/Lab 10/data/output.txt", "w");
    for (i=0; i<numofstds; i++){
    	fprintf(file_ptr, "Student Name: %s",stds[i].name);
    	fprintf(file_ptr, "Course No.\t     Mark\t              Grade\n");
    	for(int num=0; num<numofcourse; num++){
    		fprintf(file_ptr, "Course %d\t\t %f\t %c%c\t\n",num+1,stds[i].mark[num],stds[i].grd[num*2],stds[i].grd[num*2+1]);
		}
	fprintf(file_ptr, "\n");
	}
	
	fclose(file_ptr);
		
	return 0;
}