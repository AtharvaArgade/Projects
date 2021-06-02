#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<fcntl.h>

struct Student 
{
	int rollno;
	char name[30];
	int marks;
	struct Student * next;
};

typedef struct Student STUD;
typedef struct Student * PSTUD;
typedef struct Student ** PPSTUD;

bool InsertStudent(PPSTUD Head,int iNo, char *cName, int iMarks, int iSize)
{
	PSTUD newn = NULL;
	PSTUD temp = *Head;
	int i=0, iFlag = 0;

	newn = (PSTUD)malloc(sizeof(STUD));
	newn->rollno = iNo;
	for(i = 0;i<iSize;i++)
	{
		newn->name[i] = *cName;
		cName++;
	}
	newn->name[i] = '\0';
	newn->marks = iMarks;
	newn->next = NULL;

	if(*Head == NULL)
	{
		*Head = newn;
		iFlag = 1;
	}
	else
	{
		while(temp != NULL)
		{
			if(temp->rollno == iNo)
			{
				iFlag = 2;
				break;
			}
			temp = temp->next;
		}

		if(iFlag == 2)
		{
			return false;
		}
		else
		{
			temp = *Head;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;
			iFlag = 1;
		}
	}
	
	if(iFlag == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Display(PSTUD Head)
{
	printf("Rollno\t Name\t\t\t Marks\n");
	while(Head != NULL)
	{
		printf("%d\t%s\t\t%d\n",Head->rollno,Head->name,Head->marks);
		Head = Head->next;
	}
	printf("\n");
}

int Count(PSTUD Head)
{
	int iCnt = 0;
	while(Head != NULL)
	{
		iCnt++;
		Head = Head->next;
	}
	return iCnt;
}

bool DeleteStudent(PPSTUD Head, int iNo)
{
	int i = 0, iCnt = 1, iSize = 0;
	PSTUD temp = *Head;
	PSTUD target = NULL;

	iSize = Count(*Head);

	if(*Head == NULL) 
	{
		return false;
	}
	else if(temp->rollno == iNo)
	{
		*Head = temp->next;
		free(temp);
	}
	else
	{
		while(temp != NULL)
		{
			if(temp->rollno == iNo)
			{
				break;
			}
			temp = temp->next;
			iCnt++;
		}
		if(iCnt > iSize)
		{
			return false;
		}
		
		temp = *Head;


		if(iSize == iCnt)
		{
			while(temp->next->next != NULL)
			{
				temp = temp->next;
			}
			free(temp->next);
			temp->next = NULL;
		}
		else
		{
			for(i =1;i<iCnt-1;i++)
			{
				temp = temp->next;
			}
			target = temp->next;
			temp->next = target->next;
			free(target);
		}
	}
	return true;
}

STUD DisplayInfoMaximum(PSTUD Head)
{
	STUD iMax;
	int i = 0;

	if(Head == NULL)
	{
		iMax.marks = -1;
	}
	else
	{
		iMax.rollno = Head->rollno;
		for(i =0 ;i<strlen(Head->name);i++)
		{
			iMax.name[i] = Head->name[i];
		}
		iMax.name[i] = '\0';
		iMax.marks = Head->marks;

		while( Head != NULL)
		{
			if(Head->marks > iMax.marks)
			{
				iMax.rollno = Head->rollno;
				for(i =0 ;i<strlen(Head->name);i++)
				{
					iMax.name[i] = Head->name[i];
				}
				iMax.name[i] = '\0';			
				iMax.marks = Head->marks;
			}
			Head = Head->next;
		}
	}
	return iMax;	
}

STUD DisplayInfoMinimum(PSTUD Head)
{
	STUD iMin;
	int i = 0;

	if(Head == NULL)
	{
		iMin.marks = -1;
	}
	else
	{
		iMin.rollno = Head->rollno;
		for(i =0 ;i<strlen(Head->name);i++)
		{
			iMin.name[i] = Head->name[i];
		}
		iMin.name[i] = '\0';
		iMin.marks = Head->marks;

		while( Head != NULL)
		{
			if(Head->marks < iMin.marks)
			{
				iMin.rollno = Head->rollno;
				for(i =0 ;i<strlen(Head->name);i++)
				{
					iMin.name[i] = Head->name[i];
				}
				iMin.name[i] = '\0';			
				iMin.marks = Head->marks;
			}
			Head = Head->next;
		}
	}
	return iMin;	
}

STUD SearchStudent(PSTUD Head,int iNo)
{
	int iFlag = 0, i = 0;
	STUD sobj;
	PSTUD temp = Head;

	while(temp != NULL)
	{
		if(temp->rollno == iNo)
		{
			sobj.rollno = temp->rollno;
			for(i = 0;i<strlen(temp->name);i++)
			{
				sobj.name[i] = temp->name[i];
			}
			sobj.name[i] = '\0';
			sobj.marks = temp->marks;
			iFlag = 1;
			break;
		}
		temp = temp->next;
	}
	if(iFlag == 1)
	{
		return sobj;
	}
	else
	{
		sobj.rollno = 0;
		return sobj;
	}
}

bool UpdateInfo(PPSTUD Head, int iNo, char *cName, int iMarks, int iSize)
{
	int iFlag = 0, i = 0;
	PSTUD temp = *Head;

	while(temp != NULL)
	{
		if(temp->rollno == iNo)
		{
			for(i = 0;i<iSize;i++)
			{
				temp->name[i] = *cName;
				cName++; 
			}
			temp->name[i] = '\0';
			temp->marks = iMarks;
			iFlag = 1;
		}
		temp = temp->next;
	}
	if(iFlag == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float AverageMarks(PSTUD Head)
{
	int sum = 0, iCnt = 0;
	float avg = 0.0;
	if(Head == NULL)
	{
		return 0.0;
	}
	else
	{
		while(Head != NULL)
		{
			sum = sum+Head->marks;
			iCnt++;
			Head = Head->next;
		}
	}
	avg = sum/iCnt;
	return avg;
}

int MaximumMarks(PSTUD Head)
{
	int iMax = 0;
	if(Head == NULL)
	{
		return -1;
	}
	else
	{
		iMax = Head->marks;
		while(Head != NULL)
		{
			if(iMax < Head->marks)
			{
				iMax = Head->marks;  
			}
			Head = Head->next;
		}
	}
	return iMax;
}

int MinimumMarks(PSTUD Head)
{
	int iMin = 0;
	if(Head == NULL)
	{
		return -1;
	}
	else
	{
		iMin = Head->marks;
		while(Head != NULL)
		{
			if(iMin > Head->marks)
			{
				iMin = Head->marks;  
			}
			Head = Head->next;
		}
	}
	return iMin;
}

void WriteToFile(PSTUD Head)
{
	int fd = 0, i = 0;
	STUD sobj;
	PSTUD temp = Head;

	remove("StudentInfo.txt");

	fd = creat("StudentInfo.txt",0777);
	if(fd == -1)
	{
		printf("Unable to create file\n");
		return;
	}

	fd = open("StudentInfo.txt",O_WRONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return;
	}

	while(temp != NULL)
	{
		sobj.rollno = temp->rollno;
		for(i =0 ;i<strlen(temp->name);i++)
		{
			sobj.name[i] = temp->name[i];
		}
		sobj.name[i] = '\0';
		sobj.marks = temp->marks;
		sobj.next = NULL;

		write(fd,&sobj,sizeof(STUD));
		temp = temp->next;
	}
	close(fd);
}

void ReadFromFile(PPSTUD Head)
{
	int fd = 0, i = 0, iRet = 0;
	STUD sobj;

	fd = open("StudentInfo.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
	}
	while((iRet = read(fd,&sobj,sizeof(STUD))) != 0)
	{
		InsertStudent(Head,sobj.rollno,sobj.name,sobj.marks,strlen(sobj.name));
	}
	close(fd);	
}

int main()
{
	STUD obj;
	PSTUD First = NULL;
	bool bRet = false;
	int iChoice = 1, rollno = 0, marks = 0, iRet = 0;
	char name[30] = {'\0'};
	float fRet = 0.0;

	ReadFromFile(&First);

	while(iChoice != 0)
	{
		printf("***************************************************\n");
		printf("Enter your choice\n");
		printf("1 : Enter student information\n");
		printf("2 : Delete student information\n");
		printf("3 : Display student information\n");
		printf("4 : Update student information\n");
		printf("5 : Search the student\n");
		printf("6 : Count number of students\n");
		printf("7 : Student information having maximum marks\n");
		printf("8 : Student information having minimum marks\n");
		printf("9 : Average marks of students\n");
		printf("10: Maximum marks scored by student\n");
		printf("11: Minimum marks scored by student\n");
		printf("0 : Exit the application\n");
		scanf("%d",&iChoice);
		printf("***************************************************\n");

		switch(iChoice)
		{
			case 1:
				printf("Enter the rollno of student\n");
				scanf("%d",&rollno);
				printf("Enter the name of the student\n");
				scanf(" %[^'\n']s",&name);
				printf("Enter marks of the student\n");
				scanf("%d",&marks);
				bRet = InsertStudent(&First, rollno, name, marks, strlen(name));
				printf("-----------------------------------------------------------\n");
				if(bRet == true)
				{
					printf("Student information inserted successfully\n",rollno);
				}
				else 
				{
					printf("Student with rollno %d is already present\n",rollno);
				}
				break;
			case 2:
				printf("Enter the rollno of the student to delete\n");
				scanf("%d",&rollno);
				bRet = DeleteStudent(&First,rollno);
				printf("-----------------------------------------------------------\n");
				if(bRet == true)
				{
					printf("Rollno %d Student inforamtion deleted successfully\n",rollno);
				}
				else 
				{
					printf("Student with rollno %d not present\n",rollno);
				}
				break;
			case 3:
				Display(First);
				break;
			case 4:
				printf("Enter the rollno of student whose data should be updated\n");
				scanf("%d",&rollno);
				printf("Enter updated name\n");
				scanf(" %[^'\n']s",&name);
				printf("Enter updated marks\n");
				scanf("%d",&marks);
				bRet = UpdateInfo(&First,rollno,name,marks,strlen(name));
				printf("-----------------------------------------------------------\n");
				if(bRet == true)
				{
					printf("Information of the student with rollno %d updated successfully\n",rollno);
				}
				else
				{
					printf("Student with rollno %d not found\n",rollno);
				}
				break;
			case 5:
				printf("Enter the rollno of the student to search the information of student\n");
				scanf("%d",&rollno);
				obj = SearchStudent(First,rollno);
				printf("-----------------------------------------------------------\n");
				if(obj.rollno == 0)
				{
					printf("Student Information having rollno %d not present\n",rollno);
				}
				else
				{
					printf("Rollno : %d\t Name : %s \t Marks : %d\n",obj.rollno,obj.name,obj.marks);
				}
				break;
			case 6:
				iRet = Count(First);
				printf("Total number of students are : %d\n",iRet);
				break;
			case 7:
				obj = DisplayInfoMaximum(First);
				if(obj.marks == -1)
				{
					printf("Students information not present\n");
				}
				else
				{
					printf("Student having maximum marks :\n");
					printf("Rollno : %d\t Name : %s \t Marks : %d\n",obj.rollno,obj.name,obj.marks);
				}
				break;
			case 8:
				obj = DisplayInfoMinimum(First);
				if(obj.marks == -1)
				{
					printf("Students information not present\n");
				}
				else
				{
					printf("Student having minimum marks :\n");
					printf("Rollno : %d\t Name : %s \t Marks : %d\n",obj.rollno,obj.name,obj.marks);
				}
				break;
			case 9:
				fRet = AverageMarks(First);
				if(fRet == 0.0)
				{
					printf("Students information is not present\n");
				}
				else
				{
					printf("Average marks scored by students are : %f\n",fRet);
				}
				break;
			case 10:
				iRet = MaximumMarks(First);
				if(iRet == -1)
				{
					printf("Students information is not present\n");
				}
				else
				{
					printf("Maximum marks scored : %d\n",iRet);
				}
				break;
			case 11:
				iRet = MinimumMarks(First);
				if(iRet == -1)
				{
					printf("Students information is not present\n");
				}
				else
				{
					printf("Minimum marks scored : %d\n",iRet);
				}
				break;
			case 0 :
				WriteToFile(First);
				printf("Thankyou for using the application !!!\n");
				break;
			default :
				printf("Please select the proper option\n");
				break;
		}
	}

	return 0;
}