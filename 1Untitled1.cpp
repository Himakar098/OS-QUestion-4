#include<stdio.h>
struct Student
{
	bool pen;
	bool paper;
	bool question_paper;
	bool all_resources;
}s1,s2,s3;					//objectsfor accessing of boolean variables
void student_one()
{
	s1.all_resources=1;		//If all resources are allocated by the teacher
	s1.paper=1;				//to student then student process execute using its resources
	s1.question_paper=1;
	printf("First Student Process has Completed\n\n");
}	
void student_two()
{
	s2.all_resources=1;
	s2.pen=1;
	s2.question_paper=1;
	printf("Second Student Process has Completed\n\n");
}
void student_three()
{
	s3.all_resources=1;
	s3.pen=1;
	s3.paper=1;
	printf("Third Student Process has Completed\n\n");
}
int main()
{
	s1.all_resources=0;s1.paper=0;s1.pen=0;s1.question_paper=0;	
	s2.all_resources=0;s2.paper=0;s2.pen=0;s2.question_paper=0;
	s3.all_resources=0;s3.paper=0;s3.pen=0;s3.question_paper=0;			
	do
	{
		int a,b;
		printf("1.Pen\n");				//Resource allocation by the user
		printf("2.Paper\n");
		printf("3.Question Paper\n");
		printf("Select any two items to be placed on the shared table:\n");
		scanf("%d %d",&a,&b);		//comparision of allocated resources
		if((a==1 && b==2) || (a==2 && b==1) && s3.all_resources==0) student_three();	
		if((a==2 && b==3) || (a==3 && b==2) && s1.all_resources==0) student_one();
		if((a==1 && b==3) || (a==3 && b==1) && s2.all_resources==0) student_two();
	}while(s1.all_resources==0||s2.all_resources==0||s3.all_resources==0);
	printf("All Student Processes have Completed");
}

