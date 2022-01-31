
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
int main()
{
     printf("\t\tMENU\n1.VIEWALL\n2.CHECKSTATUS\n3.VIEWASSIGNMENT\n4.CHECKDATES\n5.REQUESTACTIVATION\n");
    char choice[20];
     char a[20]="VIEWALL";
     char b[20]="CHECKSTATUS";
    char c[20]="VIEWASSIGNMENT";
    char d[20]="CHECKDATES";
    char e[20]="REQUESTACTIVATION";
    printf("ENTER CHOICE FROM MENU:");
    scanf("%s",choice);
    if(strcmp(a,choice)==0){
        printf("\n |ASSIGNMENT_ID\t|DATE\t|ATTEMPTED");
    }
    else if(strcmp(b,choice)==0){
        printf("\n |ASSIGNMENT_ID\t|ATTEMPTED\t|AVERAGE_SCORE\t|PERCENTAGE_MISSED\t|PERCENTAGE_ATTEMPTED");
    }
    else if(strcmp(c,choice)==0){
        printf("\n |ASSIGNMENT_ID\t|DURATION");
    }
    else if(strcmp(d,choice)==0){
        printf("\n |ASSIGNMENT_ID\t|VALID DATE");
    }
    else if(strcmp(e,choice)==0){
        printf("\n ACTIVATION REQUEST SENT TO TEACHER");
    }
    else{
            //INCASE OF INPUT THAT IS NOT ON THE MENU,IT RETURNS THE MENU
        main();
    }

    return 0;
}

