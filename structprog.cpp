#include <stdio.h>
#include <ctype.h>
#include <string.h>


typedef struct date
{
	int d;
	int m;
	int y;
}date;

typedef struct student
{
	char fname[20];
	char lname[25];
	char gender;
	struct date dob;
}student;

int main()
{
     FILE *file;
     struct student students[15];
     int i=0;
     file=fopen("students.txt","r");
     while(fscanf(file,"%s", &students[i].fname)!=EOF)
	 {
	 	fscanf(file,"%s", &students[i].lname);
	 	fscanf(file,"%d", &students[i].dob.d);
	 	fscanf(file,"%d", &students[i].dob.m);
	 	fscanf(file,"%d", &students[i].dob.y);
	 	fscanf(file,"%s", &students[i].gender);
	 	
	 	printf("%s %s ", students[i].fname, students[i].lname);
       	printf("%d.%d.%d ", students[i].dob.d, students[i].dob.m, students[i].dob.y);
     	printf("%c\n", students[i].gender);
	 	i++;
	 }
	 fclose(file);
	 
	 //List Females
	 int j;
	 for(j=0; j<=i; j++)
	 {
	 	if(students[j].gender == 'F')
		 {
		 	printf("%s %s ", students[j].fname, students[j].lname);
        	printf("%d.%d.%d ", students[j].dob.d, students[j].dob.m, students[j].dob.y);
        	printf("%c\n", students[j].gender);
		 }
	 }
	 
}

