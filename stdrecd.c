#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
typedef struct student{
 char name[30];
 char rollno[20];
 char semester[20];
 char branch[20];
}stud;
 FILE *fp;
 char iname[20];
 char irollno[20];
 char isemester[20];
 char ibranch[20];
 stud studs[61];
//Function Declarations
void base(void);
void create(void);
void insert(void);
void disp(void);
void search(void);
void deleterecd(void);
void update(void);
void report(void);
int empty(void);
// MAIN PROGRAM
void main()
{
 base();
}
//BASE OR MAINSCREEN FUNCTION
void base(){
int c, emp;
 do
 {
      printf("\n\t-----------------------Select your choice-----------------------\n");
      printf("\n\t1. CREATE THE RECORDS\n\t2. INPUT A RECORD\n\t3. DISPLAY\n\t4. SEARCH\n\t");
      printf("5. DELETE A RECORD \n\t6. UPDATE A RECORD\n\t7. REPORT GENERATION\n");

      printf("\t8. EXIT\n");
      printf("\n\t----------------------------------------------------------------\n");
      printf("\nEnter your choice:");
      scanf("%d", &c);
      printf("\n");
        switch (c)
        {
          case 1:
              create();
              break;
          case 2:
              insert();
              break;
          case 3:
              emp = empty();
              if (emp == 0)
                printf("\nThe file is EMPTY\n");
              else
                disp();
             break;
          case 4:
              search();
              break;
          case 5:
              deleterecd();
              break;
          case 6:
              update();
              break;
          case 7:
              report();
              break;
          case 8:
              exit(1);
              break;
          default:
            printf("\nYour choice is wrong\nPlease try again...\n");
            break;
       } 
    }
 while (c != 11);
}
 //TO CREATE RECORDS
void create(){
    int i=0,s;
    fp=fopen("recordFile","ab");
    if(fp==NULL){
        printf("Cannot open file\n");
        getch();
    }
    else{
        do{
            fflush(stdin);
            printf("Enter new name : \n");
            gets(iname);
            strcpy(studs[i].name,iname);
            printf("\nEnter RollNo. : ");
            gets(irollno);
            strcpy(studs[i].rollno,irollno);
            printf("\nEnter Semester : ");
            gets(isemester);
            strcpy(studs[i].semester,isemester);
            printf("\nEnter Branch : ");
            gets(ibranch);
            strcpy(studs[i].branch,ibranch);
            printf("\nAdd more records?(y/n) : \n");
            i++;
        }while(tolower(getche())=='y');
        printf("\nDo you want to save the data :\n Enter 1 for yes and 2 for no :");
			fflush(stdin);
			scanf("%d",&s);
			if(s==1 && fp!=NULL)
                {
                    fwrite(studs,sizeof(studs),1,fp);
					printf("Data saved\n\n");
                }
			else
				printf("File not saved\n");
        fclose(fp);
        getch();
    }
}
//TO INSERT/INPUT RECORDS TO THE FILE
void insert()
{
 FILE *fp;
 fp = fopen("recordFile", "a");
 fflush(stdin);
 printf("Enter the Roll no   :");
 gets(studs->rollno);
 printf("Enter the Name      :");
 gets(studs->name);
 printf("Enter the semester   :");
 gets(studs->semester);
 printf("Enter the branch      :");
 gets(studs->branch);
 fwrite(&studs, sizeof(studs),1, fp);
 fclose(fp);
}
// TO DISPLAY RECORDS
void disp()
{
 FILE *fp1;
 fp1 = fopen("recordFile", "r");
 printf("\nRoll Number\tName\tSemester\tBranch\n\n");
 while (fread(&studs, sizeof(studs), 1, fp1)){
 printf("%s\t\t%s\t%s\t%s\n", studs->rollno, studs->name, studs->semester, studs->branch);
 }
 fclose(fp1);
}
//TO SEARCH THE GIVEN RECORD BASED ON RNO
void search()
{
   int x;
   FILE *fp2;
    char r[20];
   printf("\nSearch\n press\n 1. for RollNo.\n2. for name\n3. for semester\n4. for branch:\n");
   scanf("%d",&x);
   switch(x){
   case 1:
         fflush(stdin);
         printf("\nEnter the Roll no you want to search  :");
        gets(r);
        fflush(stdin);
          fp2 = fopen("recordFile", "r");
          while (fread(&studs, sizeof(studs), 1, fp2))
          {
           if (strcmp(studs->rollno,r)==0)
           {

            printf("\nRoll no = %s", studs->rollno);
            printf("\nName    = %s", studs->name);
            printf("\nBranch = %s", studs->branch);
            printf("\nSemester = %s", studs->semester);
           }
          }
          fclose(fp2);
    break;
   case 2:
         fflush(stdin);
         printf("\nEnter the name you want to search  :");
        gets(r);
        fflush(stdin);
          fp2 = fopen("recordFile", "r");
          while (fread(&studs, sizeof(studs), 1, fp2))
          {
           if (strcmp(studs->name,r)==0)
           {
            printf("\nRoll no = %s", studs->rollno);
            printf("\nName    = %s", studs->name);
            printf("\nBranch = %s", studs->branch);
            printf("\nSemester = %s", studs->semester);
           }
          }
          fclose(fp2);
    break;
   case 3:
         fflush(stdin);
         printf("\nEnter the semester you want to search  :");
        gets(r);
        fflush(stdin);
          fp2 = fopen("recordFile", "r");
          while (fread(&studs, sizeof(studs), 1, fp2))
          {
           if (strcmp(studs->semester,r)==0)
           {
            printf("\nRoll no = %s", studs->rollno);
            printf("\nName    = %s", studs->name);
            printf("\nBranch = %s", studs->branch);
            printf("\nSemester = %s", studs->semester);
           }
          }
          fclose(fp2);
    break;
   case 4:
           fflush(stdin);
           printf("\nEnter the branch you want to search  :");
          gets(r);
          fflush(stdin);
            fp2 = fopen("recordFile", "r");
            while (fread(&studs, sizeof(studs), 1, fp2))
            {
             if (strcmp(studs->branch,r)==0)
             {
              printf("\nRoll no = %s", studs->rollno);
              printf("\nName    = %s", studs->name);
              printf("\nBranch = %s", studs->branch);
              printf("\nSemester = %s", studs->semester);
             }
            }
            fclose(fp2);
    break;
   }
}
//TO DELETE A RECORD<can also be implemented using in built del function from cmd> 
void deleterecd()
{
 FILE *fpo;
 FILE *fpt;
 char r[20];
 fflush(stdin);
 printf("Enter the Roll no you want to delete :");
 gets(r);
  fpo = fopen("recordFile", "r");
  fpt = fopen("TempFile1", "w");
  while (fread(&studs, sizeof(studs), 1, fpo))
  {
   if (strcmp(studs->rollno,r)!=0)
    fwrite(&studs, sizeof(studs),1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("recordFile", "w");
  fpt = fopen("TempFile1", "r");
  while (fread(&studs, sizeof(studs), 1, fpt))
   fwrite(&studs, sizeof(studs), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
}
//TO UPDATE THE RECORD 
void update()
{
 FILE *fpt;
 FILE *fpo;
 char r[20], ch;
 fflush(stdin);
 printf("Enter roll number to update:");
 gets(r);
  fpo = fopen("recordFile", "r");
  fpt = fopen("TempFile1", "w");
  while (fread(&studs, sizeof(studs), 1, fpo))
  {
   if (strcmp(studs->rollno,r) != 0){
    fwrite(&studs, sizeof(studs), 1, fpt);
    }
   else
   {
    printf("\n\t1. Update Name of Roll Number %s", r);
    printf("\n\t2. Update Roll No. of Roll Number %s", r);
    printf("\n\t3. Update Branch of Roll Number %s", r);
    printf("\n\t4. Update Semester of Roll Number %s", r);
    printf("\n\t5. Update all record Roll Number %s", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter Name:");
     scanf("%s", &studs->name);
     break;
    case 2:
     printf("Enter Roll : ");
     scanf("%s", &studs->rollno);
     break;
    case 3:
     printf("Enter Branch : ");
     scanf("%s", &studs->branch);
     break;
    case 4:
     printf("Enter Semester : ");
     scanf("%s", &studs->semester);
     break;
    case 5:
     printf("Enter Name: ");
     scanf("%s", &studs->name);
     printf("Enter Roll No.: ");
     scanf("%s", &studs->rollno);
      printf("Enter Semester: ");
     scanf("%s", &studs->semester);
     printf("Enter Branch: ");
     scanf("%s", &studs->branch);
     break;

    default:
     printf("Invalid Selection");
     break;
    }
    fwrite(&studs, sizeof(studs), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("recordFile", "w");
  fpt = fopen("TempFile1", "r");
  while (fread(&studs, sizeof(studs), 1, fpt))
  {
   fwrite(&studs, sizeof(studs), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
}
void report()
{

    FILE *fp2;
    char r[20];
    int count=0,opt;
    printf("\n1. Based on semester\n2. Based on branch\n");
	scanf("%d",&opt);
	switch(opt)
	{
      case 1:
            fflush(stdin);
            printf("\nEnter the semester you want to search  :");
            gets(r);
            fflush(stdin);
            fp2 = fopen("recordFile", "r");
                while (fread(&studs, sizeof(studs), 1, fp2))
                {
                if (strcmp(studs->semester,r)==0)
                    {
                    count++;
                    printf("\nRoll no = %s", studs->rollno);
                    printf("\nName    = %s", studs->name);
                    printf("\nBranch = %s", studs->branch);
                    printf("\nSemester = %s", studs->semester);
                    }
                }
            fclose(fp2);
            printf("\nTotal number of students in %s semester are %d\n\n",r,count);
		break;

		case 2:
            fflush(stdin);
            printf("\nEnter the branch you want to search  :");
            gets(r);
            fflush(stdin);
            fp2 = fopen("recordFile", "r");
               while (fread(&studs, sizeof(studs), 1, fp2))
                  {
                    if (strcmp(studs->branch,r)==0)
                        {
                        count++;
                        printf("\nRoll no = %s", studs->rollno);
                        printf("\nName    = %s", studs->name);
                        printf("\nBranch = %s", studs->branch);
                        printf("\nSemester = %s", studs->semester);
                        }
                    }
                fclose(fp2);
        printf("\nTotal number of students in %s branch are %d\n\n",r,count);
		break;
		default:
			break;
	}
}
//TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("recordFile", "r");
 while (fread(&studs, sizeof(studs), 1, fp)){
  c = 1;
 }
 fclose(fp);
 return c;
}
