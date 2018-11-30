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
	 
	 printf("\nFemales: \n");
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
	 
	 printf("\nYounger than 18: \n");
	 //<18
	for(j=0; j<=i; j++)
	 {
	 	if(students[j].dob.y == 2000 && students[j].dob.d >= 26 && students[j].dob.m >= 11)
		 {
		 	printf("%s %s ", students[j].fname, students[j].lname);
        	printf("%d.%d.%d ", students[j].dob.d, students[j].dob.m, students[j].dob.y);
        	printf("%c\n", students[j].gender);
		 }
	 	else if(students[j].dob.y > 2000)
		 {
		 	printf("%s %s ", students[j].fname, students[j].lname);
        	printf("%d.%d.%d ", students[j].dob.d, students[j].dob.m, students[j].dob.y);
        	printf("%c\n", students[j].gender);
		 }
	 }
	 
    printf("\nBorn in december 5: \n");
	 //December 5
	 for(j=0; j<=i; j++)
	 {
	 	if(students[j].dob.d == 5 && students[j].dob.m == 12  )
		 {
		 	printf("%s %s ", students[j].fname, students[j].lname);
        	printf("%d.%d.%d ", students[j].dob.d, students[j].dob.m, students[j].dob.y);
        	printf("%c\n", students[j].gender);
		 }
	 }
	 
	  printf("\nFrom youngest to the oldest \n");
	 //young to old
	 int c;
	 for(j=0; j<=i-1; j++)
	 {
		for (c=0; c<i-1-j; c++)       
		{
			if (students[c].dob.y < students[c+1].dob.y)
			{
				int tmp;
				tmp = students[c].dob.y;
				students[c].dob.y = students[c+1].dob.y;
                students[c+1].dob.y = tmp;
			}  
		}
	 }
	 for(j=0; j<=i-1; j++)
	 {
	 	printf("%s %s ", students[j].fname, students[j].lname);
        printf("%d.%d.%d ", students[j].dob.d, students[j].dob.m, students[j].dob.y);
      	printf("%c\n", students[j].gender);
	 }
	 //Panna
    printf("\nPanna \n");
	for (j=0; j<i; j++)
	{
		if ((students[j].dob.d > 24 && students[j].dob.m == 8) || (students[j].dob.d < 23 && students[j].dob.m == 9))
		{
			printf("%s %s ", students[j].fname, students[j].lname);
            printf("%d.%d.%d ", students[j].dob.d, students[j].dob.m, students[j].dob.y);
         	printf("%c\n", students[j].gender);
		}
    }
}

