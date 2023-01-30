#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 100

char name[20]; 

int totaltime(long int start,long int end)
{
   long int sec,diff,min;
   diff = end - start;
   return diff;
} 

void filewrite(long int acpm,long int awpm)
{
   FILE *fptr3 = fopen("results.txt","a");
   fprintf(fptr3,"\nName:%s\t\t\tCPM:%ld\t\t\t\tWPM:%ld",name,acpm,awpm);
   fclose(fptr3);
}

void displayresults(int cchar,int ichar,long int timetaken)
{
       long int sec,min;
       int n=(cchar/6);
       long int acpm = ((cchar*60)/(timetaken));
       long int awpm = ((n*60)/(timetaken));       
       min = timetaken/60;
       sec = timetaken%60;
       if(cchar<6 && cchar>0)
       {
          n = 1;
       }
       printf("------------------------------------------------------------------------------------------\n");
       printf("                        RESULTS                               \n");
       printf("THE TOTAL NUMBER OF CORRECT CHARACTERS TYPED ARE        -  %d\n",cchar);
       printf("THE TOTAL NUMBER OF INCORRECT CHARACTERS TYPED ARE      -  %d\n",ichar);
       printf("THE TOTAL NUMBER OF CORRECT WORDS  TYPED ARE            -  %d\n",n);
       printf("THE TOTAL TIME TAKEN TO TYPE IN MIN:SEC IS              -  %d:%d\n",min,sec);
       printf("THE AVERAGE NUMBER OF CHARACTERS PER MINUTE TYPED ARE   -  %d\n",acpm);
       printf("THE AVERAGE NUMBER OF WORDS PER MINUTE TYPED ARE        -  %d\n",awpm);
       printf("------------------------------------------------------------------------------------------\n");
       filewrite(acpm,awpm);
}

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void comparefile(int rno,long int timetaken)
{
       FILE *fptr1;
       int cchar=4,ichar=-2;
       char ch1,ch2;
       switch(rno)
       {
              case 0:fptr1 = fopen("0.txt","r");
                 break;
              case 1:fptr1 = fopen("1.txt","r");
                 break;
              case 2:fptr1 = fopen("2.txt","r");
                 break;
              case 3:fptr1 = fopen("3.txt","r");
                 break;
              case 4:fptr1 = fopen("4.txt","r");
                 break;
              case 5:fptr1 = fopen("5.txt","r");
                 break;
              case 6:fptr1 = fopen("6.txt","r");
                 break;
              case 7:fptr1 = fopen("7.txt","r");
                 break;
              case 8:fptr1 = fopen("8.txt","r");
                 break;
              case 9:fptr1 = fopen("9.txt","r");
                 break; 
       }
       FILE *fptr2 = fopen("typetest.txt","r");
       do
       {
          ch1 = fgetc(fptr1);
          ch2 = fgetc(fptr2);
          if(ch1 == ch2)
              cchar++;
          else 
              ichar++;
        }while(ch1!=EOF && ch2!=EOF);
    fclose(fptr1);
    fclose(fptr2);
    displayresults(cchar,ichar,timetaken);     
}

void display_para(int rno)
{
    char ch,ab;
    char data[100];
    FILE *fptr1,*fptr2;
    long int timetaken;
    bool keep_going = true;
    char buffer[BUFFER_SIZE];
    switch(rno)
    {
        case 0:fptr1 = fopen("0.txt","r");
               break;
        case 1:fptr1 = fopen("1.txt","r");
               break;
        case 2:fptr1 = fopen("2.txt","r");
               break;
        case 3:fptr1 = fopen("3.txt","r");
               break;
        case 4:fptr1 = fopen("4.txt","r");
               break;
        case 5:fptr1 = fopen("5.txt","r");
               break;
        case 6:fptr1 = fopen("6.txt","r");
               break;
        case 7:fptr1 = fopen("7.txt","r");
               break;
        case 8:fptr1 = fopen("8.txt","r");
               break;
        case 9:fptr1 = fopen("9.txt","r");
               break; 
    }
    if(fptr1 == NULL)
    {
        printf("ERROR - Unable To Display The Contents Of The File\n");
        exit(EXIT_FAILURE);
    }
    do
    {
        ch = fgetc(fptr1);
        putchar(ch);
    }while(ch!=EOF);
    printf("\n\nLET'S BEGIN TYPING!\n");
    delay(1);
    printf("YOUR TIMER BEGINS!\n");
    sleep(1);
    time_t start = time(NULL);
    fptr2 = fopen("typetest.txt", "w");
    if (fptr2 == NULL)
    {
       printf("Error opening file.\n");
       exit(EXIT_FAILURE);
    }
    while (keep_going)
    {
       fgets(buffer, BUFFER_SIZE, stdin);
       if (strcmp(buffer,"quit\n") == 0)
          keep_going = false;
       else 
          fputs(buffer,fptr2);
     } 
     time_t end = time(NULL); 
     fclose(fptr1);
     fclose(fptr2);
     timetaken = totaltime(start,end);
     comparefile(rno,timetaken);
}

int main()
{   
    int choice,rno;
    FILE *fptr;
    char ch;
    printf("----------------------------------------------------------TYPING SPEED ANALYSER-----------------------------------------------------------------------------");
    printf("\n\n\n");
    for( ; ; )
    {
        printf("\nENTER YOUR CHOICE:\n1.Take a Typing Test\n2.See High Scores\n3.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter your first name:\n");
                    scanf("%s",&name);
                    printf("\n");
                    delay(1);
                    printf("---------------------------------------------INSTRUCTIONS TO BE FOLLOWED---------------------------------------------------------------\n");
                    delay(3);
                    printf("1. A paragraph of about 100-150 words will be displayed and the 'TIMER WILL BEGIN IMMEDIATELY'.\n");
                    delay(3);
                    printf("2. The user is requested to type the contents on the console.\n");
                    delay(3);
                    printf("3. Please follow the case of the letters,punctuations and blankspaces.\n");
                    delay(3);
                    printf("4. Please do not skip any words or blankspaces in between.\n");
                    delay(3);
                    printf("5. Once you complete typing or if you want to submit inbetween then move to the next line and type - 'quit' and press the enter key\n");
                    delay(5);
                    printf("6. Your results will be displayed as soon as you sumbit.\n");
                    delay(3);
                    printf("\n\n");
                    printf("All the very best!!\n");
                    printf("Happy Typing!!");                 
                    printf("\n");
                    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n"); 
                    delay(4); 
                    printf("\nYOUR PARAGRAPH IS:\n");
                    rno = rand()%10;
                    display_para(rno);
                    break;

           case 2: fptr = fopen("results.txt","r");
                   if(fptr == NULL)
                   {
                          printf("ERROR - Unable To Open The File\n");
                          exit(EXIT_FAILURE);
                   }
                   do
                   {
                          ch = fgetc(fptr);
                          putchar(ch);
                   }while(ch!=EOF);
                   fclose(fptr);
                   printf("\n");
                   break;

           case 3:exit(0);
           
           default:printf("Please Enter A Valid Choice\n");           
        }
    }
    return 0;
}