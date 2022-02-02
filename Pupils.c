#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<mysql.h>
#include <unistd.h> 
//Handle database connection failure
float finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}
//Store characters in the application
// Number of lines for the alphabet's pattern
int height = 4;
// Number of character width in each line
int width = 7;
 
// Function to find the absolute value
// of a number D
int abs(int d)
{
    return d < 0 ? -1 * d : d;
}
//grade the pupil's character
float grade(int letter[4][7]){
int character[4][7];
float sum=0;
for(int i=0; i<4; i++){
for(int j=0; j<7; j++){
scanf("%d",&character[i][j]);

//compare the stored character with the one being drawn
if(letter[i][j]==character[i][j]){
sum+=3.5;
} else{
sum+=0;
}
}
}
printf("You have scored %.2f\n",sum);
return sum;
}
 
// Function to print the pattern of 'A'
float printA()
{
    int n = width / 2, i, j, letter[4][7];
    for (i = 0; i < height; i++) {
        for (j = 0; j <= width; j++) {
            if (j == n || j == (width - n)
                || (i == height / 2 && j > n
                    && j < (width - n))){
                printf("*");
                letter[i][j] = 1;
            }else{
            letter[i][j] = 0;
                printf(" ");
          
                }
        }
        printf("\n");
        n--;
    }
  return grade(letter);
}
 
// Function to print the pattern of 'B'
float printB()
{
    int i, j, half = (height / 2),letter[4][7];
    for (i = 0; i < height; i++) {
        printf("*");
        letter[i][j] = 1;
        for (j = 0; j < width; j++) {
            if ((i == 0 || i == height - 1 || i == half)
                && j < (width - 2)){
                printf("*");
                letter[i][j] = 1;
            }else if (j == (width - 2)
                    && !(i == 0 || i == height - 1
                        || i == half)){
                printf("*");
                letter[i][j] = 1;
            }else{
            letter[i][j] = 0;
                printf(" ");
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'C'
float printC()
{
    int i, j,letter[4][7];
    for (i = 0; i < height; i++) {
    letter[i][j] = 1;
        printf("*");
        for (j = 0; j < (height - 1); j++) {
            if (i == 0 || i == height - 1){
                printf("*");
                letter[i][j] = 1;
            }else{
                continue;
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'D'
float printD()
{
    int i, j,letter[4][7];
    for (i = 0; i < height; i++) {
        printf("*");
        letter[i][j] = 1;
        for (j = 0; j < height; j++) {
            if ((i == 0 || i == height - 1)
                && j < height - 1){
                printf("*");
                letter[i][j] = 1;
            }else if (j == height - 1 && i != 0
                    && i != height - 1){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'E'
float printE()
{
    int i, j,letter[4][7];
    for (i = 0; i < height; i++) {
        printf("*");
        letter[i][j] = 1;
        for (j = 0; j < height; j++) {
            if ((i == 0 || i == height - 1)
                || (i == height / 2
                    && j <= height / 2)){
                printf("*");
                letter[i][j] = 1;
            }else{
                continue;
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'F'
float printF()
{
    int i, j,letter[4][7];
    for (i = 0; i < height; i++) {
    letter[i][j] = 1;
        printf("*");
        for (j = 0; j < height; j++) {
            if ((i == 0) || (i == height / 2
                            && j <= height / 2)){
                            letter[i][j] = 1;
                printf("*");
            }else{
                continue;
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'G'
float printG()
{
    int i, j,letter[4][7];
    width--;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if ((i == 0 || i == height - 1)
                && (j == 0 || j == width - 1)){
                printf(" ");
                letter[i][j] = 0;
            }else if (j == 0){
                printf("*");
                letter[i][j] = 1;
            }else if (i == 0 && j <= height){
                printf("*");
                letter[i][j] = 1;
            }else if (i == height / 2
                    && j > height / 2){
                printf("*");
                letter[i][j] = 1;
            }else if (i > height / 2
                    && j == width - 1){
                printf("*");
                letter[i][j] = 1;
            }else if (i == height - 1
                    && j < width){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'H'
float printH()
{
    int i, j,letter[4][7];
    for (i = 0; i < height; i++) {
        printf("*");
        letter[i][j] = 1;
        for (j = 0; j < height; j++) {
            if ((j == height - 1)
                || (i == height / 2)){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'I'
float printI()
{
    int i, j,letter[4][7];
    for (i = 0; i < height; i++) {
        for (j = 0; j < height; j++) {
            if (i == 0 || i == height - 1){
                printf("*");
                letter[i][j] = 1;
            }else if (j == height / 2){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'J'
float printJ()
{
    int i, j,letter[4][7];
    for (i = 0; i < height; i++) {
        for (j = 0; j < height; j++) {
            if (i == height - 1 && (j > 0
                                    && j < height - 1)){
                printf("*");
                letter[i][j] = 1;
            }else if ((j == height - 1
                    && i != height - 1)
                    || (i > (height / 2) - 1
                        && j == 0 && i != height - 1)){
                        letter[i][j] = 1;
                printf("*");
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'K'
float printK()
{
    int i, j, half = height / 2, dummy = half,letter[4][7];
    for (i = 0; i < height; i++) {
        printf("*");
        letter[i][j] = 1;
        for (j = 0; j <= half; j++) {
            if (j == abs(dummy)){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
        dummy--;
    }
    return grade(letter);
}
 
// Function to print the pattern of 'L'
float printL()
{
    int i, j,letter[4][7];
    for (i = 0; i < height; i++) {
        printf("*");
        letter[i][j] = 1;
        for (j = 0; j <= height; j++) {
            if (i == height - 1){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'M'
float printM()
{
    int i, j, counter = 0,letter[4][7];
    for (i = 0; i < height; i++) {
        printf("*");
        letter[i][j] = 1;
        for (j = 0; j <= height; j++) {
            if (j == height){
                printf("*");
                letter[i][j] = 1;
            }else if (j == counter
                    || j == height - counter - 1){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        if (counter == height / 2) {
            counter = -99999;
        }
        else
            counter++;
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'N'
float printN()
{
    int i, j, counter = 0,letter[4][7];
    for (i = 0; i < height; i++) {
        printf("*");
        letter[i][j] = 1;
        for (j = 0; j <= height; j++) {
            if (j == height){
                printf("*");
                letter[i][j] = 1;
            }else if (j == counter){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        counter++;
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'O'
float printO()
{
    int i, j, space = (height / 3),letter[4][7];
    int width = height / 2 + height / 5 + space + space;
    for (i = 0; i < height; i++) {
        for (j = 0; j <= width; j++) {
            if (j == width - abs(space)
                || j == abs(space)){
                letter[i][j] = 1;
                printf("*");
            }else if ((i == 0
                    || i == height - 1)
                    && j > abs(space)
                    && j < width - abs(space)){
                    letter[i][j] = 1;
                printf("*");
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        if (space != 0
            && i < height / 2) {
            space--;
        }
        else if (i >= (height / 2 + height / 5))
            space--;
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'P'
float printP()
{
    int i, j,letter[4][7];
    for (i = 0; i < height; i++) {
        printf("*");
        letter[i][j] = 1;
        for (j = 0; j < height; j++) {
            if ((i == 0 || i == height / 2)
                && j < height - 1){
                printf("*");
                letter[i][j] = 1;
            }else if (i < height / 2
                    && j == height - 1 && i != 0){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'Q'
float printQ()
{
    printO();
    int i, j, d = height,letter[4][7];
    for (i = 0; i < height / 2; i++) {
        for (j = 0; j <= d; j++) {
            if (j == d){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
        d++;
    }
    return grade(letter);
}
 
// Function to print the pattern of 'R'
float printR()
{
    int i, j, half = (height / 2),letter[4][7];
    for (i = 0; i < height; i++) {
        printf("*");
        letter[i][j] = 1;
        for (j = 0; j < width; j++) {
            if ((i == 0 || i == half)
                && j < (width - 2)){
                printf("*");
                letter[i][j] = 1;
            }else if (j == (width - 2)
                    && !(i == 0 || i == half)){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'S'
float printS()
{
    int i, j,letter[4][7];
    for (i = 0; i < height; i++) {
        for (j = 0; j < height; j++) {
            if ((i == 0 || i == height / 2
                || i == height - 1)){
                printf("*");
                letter[i][j] = 1;
            }else if (i < height / 2
                    && j == 0){
                printf("*");
                letter[i][j] = 1;
            }else if (i > height / 2
                    && j == height - 1){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'T'
float printT()
{
    int i, j,letter[4][7];
    for (i = 0; i < height; i++) {
        for (j = 0; j < height; j++) {
            if (i == 0){
                printf("*");
                letter[i][j] = 1;
            }else if (j == height / 2){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'U'
float printU()
{
    int i, j,letter[4][7];
    for (i = 0; i < height; i++) {
        if (i != 0 && i != height - 1){
            printf("*");
            letter[i][j] = 1;
        }else{
            printf(" ");
            letter[i][j] = 0;
            }
        for (j = 0; j < height; j++) {
            if (((i == height - 1)
                && j >= 0
                && j < height - 1)){
                printf("*");
                letter[i][j] = 1;
            }else if (j == height - 1 && i != 0
                    && i != height - 1){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'V'
float printV()
{
    int i, j, counter = 0,letter[4][7];
    for (i = 0; i < height; i++) {
        for (j = 0; j <= width; j++) {
            if (j == counter
                || j == width - counter - 1){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        counter++;
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'W'
float printW()
{
    int i, j, counter = height / 2,letter[4][7];
    for (i = 0; i < height; i++) {
        printf("*");
        letter[i][j] = 1;
        for (j = 0; j <= height; j++) {
            if (j == height){
                printf("*");
                letter[i][j] = 1;
            }else if ((i >= height / 2)
                    && (j == counter
                        || j == height - counter - 1)){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        if (i >= height / 2) {
            counter++;
        }
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'X'
float printX()
{
    int i, j, counter = 0,letter[4][7];
    for (i = 0; i <= height; i++) {
        for (j = 0; j <= height; j++) {
            if (j == counter
                || j == height - counter){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        counter++;
        printf("\n");
    }
    return grade(letter);
}
 
// Function to print the pattern of 'Y'
float printY()
{
    int i, j, counter = 0,letter[4][7];
    for (i = 0; i < height; i++) {
        for (j = 0; j <= height; j++) {
            if (j == counter
                || j == height - counter
                    && i <= height / 2){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        printf("\n");
        if (i < height / 2)
            counter++;
    }
    return grade(letter);
}
 
// Function to print the pattern of 'Z'
float printZ()
{
    int i, j, counter = height - 1,letter[4][7];
    for (i = 0; i < height; i++) {
        for (j = 0; j < height; j++) {
            if (i == 0 || i == height - 1
                || j == counter){
                printf("*");
                letter[i][j] = 1;
            }else{
                printf(" ");
                letter[i][j] = 0;
                }
        }
        counter--;
        printf("\n");
    }
    return grade(letter);
}
//mark a given letter
float getMarked(char c){
switch (c) {
    case 'A':
   return printA();
        break;
    case 'B':
        return printB();
        break;
    case 'C':
        return printC();
        break;
    case 'D':
        return printD();
        break;
    case 'E':
        return printE();
        break;
    case 'F':
        return printF();
        break;
    case 'G':
        return printG();
        break;
    case 'H':
        return printH();
        break;
    case 'I':
        return printI();
        break;
    case 'J':
        return printJ();
        break;
    case 'K':
        return printK();
        break;
    case 'L':
        return printL();
        break;
    case 'M':
        return printM();
        break;
    case 'N':
        return printN();
        break;
    case 'O':
        return printO();
        break;
    case 'P':
        return printP();
        break;
    case 'Q':
        return printQ();
        break;
    case 'R':
        return printR();
        break;
    case 'S':
        return printS();
        break;
    case 'T':
        return printT();
        break;
    case 'U':
        return printU();
        break;
    case 'V':
        return printV();
        break;
    case 'W':
        return printW();
        break;
    case 'X':
        return printX();
        break;
    case 'Y':
        return printY();
        break;
    case 'Z':
        return printZ();
        break;
    }
}
//function to attempt an assignment
void attemptAssignment(char *user_code){
char assignment_id[2];
printf("Enter an assignment number to attempt:");
scanf("%s",assignment_id);
MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "127.0.0.1", "root", "",
          "kindercare", 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }
  char sql[300] = "SELECT (characters) FROM assignments WHERE id=";
strcat(sql,assignment_id);
  if (mysql_query(con, sql))
  {
      finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);
//returns one row containing number of fields
  MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)))
  {
      for(int i = 0; i < num_fields; i++)
      {
          printf("The characters are %s", row[i] ? row[i] : "NULL");
          int l=strlen(row[i]);
          float sum=0;
          for(int j=0; j<l; j++){
          printf("The mark is %.2f: ",(sum+=getMarked(row[i][j]))/l);
          }
         float score = sum/l;
           char sql[300] = "INSERT INTO scores(user_code,assignment_id,score) VALUES('";
strcat(sql,user_code);
strcat(sql,"',");
strcat(sql,"'");
strcat(sql,assignment_id);
strcat(sql,"','");
char sc[3];
gcvt(score,2,sc);
strcat(sql,sc);
strcat(sql,"')");
  if (mysql_query(con,sql)) {
      finish_with_error(con);
  }
     printf("Your scores have been submitted!!\n");    
      }

      printf("\n");
  }
  mysql_free_result(result);
  mysql_close(con);
}

//function to show all system commands
void allCommands(){
printf("list of application commands\n");
printf("***********************************************\n");
printf("viewall: Displays the assignment number and date showing attempted or not\n\n");
printf("checkstatus:Displays status report\n\n");
printf("viewassignment assignmentid:See details of specified assignment\n\n");
printf("checkdates datefrom dateto:Check if there is an assignment within a specified dates\n\n");
printf("RequestActivation:Ask to be activated by the teacher\n\n");
}


//Function to Fetch all un attempted assignments by the logged in user
void notAttempted(char *user_code){
MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "127.0.0.1", "root", "",
          "kindercare", 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }
char sql[300] = "SELECT * FROM assignments WHERE id NOT IN(SELECT assignment_id  FROM scores where user_code='";
strcat(sql,user_code);
strcat(sql,"')");
  if (mysql_query(con, sql))
  {
      finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;
  printf("Un Attempted Assignments\n");

  while ((row = mysql_fetch_row(result)))
  {
      for(int i = 0; i < num_fields; i++)
      {
          printf("%s ", row[i] ? row[i] : "NULL");
      }

      printf("\n");
  }

  mysql_free_result(result);
  mysql_close(con);
}
//Function to handle viewall command
void viewall(char *user_code){
MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "127.0.0.1", "root", "",
          "kindercare", 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }
char sql[300] = "SELECT assignments.assignment_title, assignments.start_date, assignments.end_date, scores.user_code FROM assignments LEFT JOIN scores ON assignments.id=scores.assignment_id WHERE scores.user_code='";
strcat(sql,user_code);
strcat(sql,"'");
  if (mysql_query(con, sql))
  {
      finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;
  printf("Attempted Assignments\n");

  while ((row = mysql_fetch_row(result)))
  {
      for(int i = 0; i < num_fields; i++)
      {
          printf("%s ", row[i] ? row[i] : "NULL");
      }

      printf("\n");
  }
  //print all un attempted assignments
  notAttempted(user_code);

  mysql_free_result(result);
  mysql_close(con);
}
//Function to count average score
float average(char *user_code){
MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "127.0.0.1", "root", "",
          "kindercare", 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }
  char sql[300] = "SELECT AVG(score) FROM scores WHERE user_code='";
strcat(sql,user_code);
strcat(sql,"'");

  if (mysql_query(con, sql))
  {
      finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);
//returns one row containing number of fields
  MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)))
  {
      for(int i = 0; i < num_fields; i++)
      {
          printf("The average score is %s", row[i] ? row[i] : "NULL");
      }

      printf("\n");
  }
  mysql_free_result(result);
  mysql_close(con);
}
//Function to handle checkstatus
void checkstatus(char *user_code){
MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "127.0.0.1", "root", "",
          "kindercare", 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }
  char sql[300] = "SELECT COUNT(*) FROM scores WHERE user_code='";
strcat(sql,user_code);
strcat(sql,"'");

  if (mysql_query(con, sql))
  {
      finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);
//returns one row containing number of fields
  MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)))
  {
      for(int i = 0; i < num_fields; i++)
      {
          printf("You attempted %s assignments", row[i] ? row[i] : "NULL");
      }

      printf("\n");
  }
  average(user_code);
  mysql_free_result(result);
  mysql_close(con);
}
//Check for a specific assignment details
void viewassignment(){
//ask for a command
printf("\n\nEnter a command:");
char command[20];
scanf("%s",command);
//ask for the assignment id
char assignment_id[10];
scanf("%s",assignment_id);
if((strcmp(command,"viewassignment")==0)){
MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "127.0.0.1", "root", "",
          "kindercare", 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }
  char sql[300] = "SELECT * FROM assignments WHERE id=";
  strcat(sql,assignment_id);
  if (mysql_query(con, sql))
  {
      finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      finish_with_error(con);
  }
printf("Assignment %s Details\n", assignment_id);
  int num_fields = mysql_num_fields(result);
//returns one row containing number of fields
  MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)))
  {
      for(int i = 0; i < num_fields; i++)
      {
          printf("%s", row[i] ? row[i] : "NULL");
      }

      printf("\n");
  }
  mysql_free_result(result);
  mysql_close(con);
  } else {
  printf("The command does not exists\n");
  }
  
}
//checkdates function
void checkdates(){
//ask for a command
printf("\n\nEnter a command:");
char command[20];
//ask for the date_from
char date_from[20];
//scanf("%s",date_from);
//ask for the date_to
char date_to[20];
//scanf("%s",date_to);
scanf("%s%s%s",command,date_from,date_to);

if(strcmp(command,"checkdates")==0){
MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "127.0.0.1", "root", "",
          "kindercare", 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }
  char sql[300] = "SELECT * FROM assignments WHERE start_date BETWEEN '";
  strcat(sql,date_from);
  strcat(sql,"' ");
  strcat(sql,"AND ");
  strcat(sql,"'");
  strcat(sql,date_to);
  strcat(sql,"'");
  if (mysql_query(con, sql))
  {
      finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      finish_with_error(con);
  }
printf("Assignment between %s and %s\n", date_from, date_to);
  int num_fields = mysql_num_fields(result);
//returns one row containing number of fields
  MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)))
  {
      for(int i = 0; i < num_fields; i++)
      {
          printf("%s", row[i] ? row[i] : "NULL");
      }

      printf("\n");
  }
  mysql_free_result(result);
  mysql_close(con);
  } else {
  printf("The command does not exists\n");
  }
  
}
//Request to be activated
float RequestActivation(char *user_code){
MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }

  if (mysql_real_connect(con, "127.0.0.1", "root", "",
          "kindercare", 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }
  char sql[300] = "INSERT INTO activations(user_code,request) VALUES('";
strcat(sql,user_code);
strcat(sql,"','I wanna be activated')");
  if (mysql_query(con,sql)) {
      finish_with_error(con);
  }
  printf("\n\nYou requested to be atcivated\n");
  mysql_close(con);
}
//to be called by the menu
void viewcheck(char *user_code){
//ask for a command
C:  printf("\n\nEnter a command:");
char command[20];
scanf("%s",command);
if(strcmp(command,"viewall")==0){
viewall(user_code);
} else if(strcmp(command,"checkstatus")==0){
checkstatus(user_code);
} else if(strcmp(command,"RequestActivation")==0){
RequestActivation(user_code);
} else {
printf("The command does not exist, try again:");
goto C;
}
}
void menu(char *user_code){
C: printf("MENU\n");
printf("1.View All assignements\n");
printf("2.Check status of assignments\n");
printf("3.Request Activation\n");
printf("4.View a specific assignment details\n");
printf("5.Check if there is an assignment in a given date range\n");
printf("6.Attempt an assignment\n");
printf("7.EXIT\n");
 int choice;
printf("Select your choice and enter the command:");
scanf("%d",&choice);
switch(choice){
case 1:
system("clear");
printf("View attempted and un attempted assignments\n");
printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
viewcheck(user_code);
sleep(5);
goto C;
break;
case 2:
system("clear");
printf("Check status of your assignments\n");
printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
viewcheck(user_code);
sleep(5);
goto C;
break;
case 3:
system("clear");
printf("Request for activation\n");
printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
viewcheck(user_code);
sleep(5);
goto C;
break;
case 4:
system("clear");
printf("Check for a specific assignment details\n");
printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
viewassignment();
sleep(5);
goto C;
break;
case 5:
system("clear");
printf("check if there is an assignment between given dates\n");
printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
checkdates();
sleep(5);
goto C;
break;
case 6:
system("clear");
printf("Trying to attempt an assignment\n");
printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
attemptAssignment(user_code);
sleep(5);
goto C;
break;
case 7:
system("clear");
printf("Exiting the application, good bye, see you!!!!!");
sleep(2);
break;
default:
printf("The command does not exist, please try again\n");
goto C;
break;
}

}
//check if the entered user code exists in the database
int login(char *user_code){
MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "127.0.0.1", "root", "",
          "kindercare", 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }
  char sql[300] = "SELECT (user_code) FROM pupils WHERE user_code='";
  strcat(sql,user_code);
  strcat(sql,"'");


  if (mysql_query(con, sql))
  {
      finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      finish_with_error(con);
  } 
  int num_fields = mysql_num_fields(result);
//returns one row containing number of fields
  MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)))
  {
      for(int i = 0; i < num_fields; i++)
      {
          if(strcmp(user_code, row[0])==0){
          return 1;
          } 
      }

      printf("\n");
  }
  
  mysql_free_result(result);
  mysql_close(con);
}
int main(){
system("clear");
//Application title
printf("KINDERCARE ASSIGNMENT SYSTEM\n");
printf("***********************************\n");
//ask the user to enter ther user codes
H: printf("Enter your code to login to the system:");
//input the user code
char user_code[10];
scanf("%s",user_code);
if(login(user_code)==1){
//Some messages
sleep(1);
printf("I am checking if your teacher regestered you\n");
sleep(2);
printf("Still looking for you\n");

printf("logged in\n");
//show commands and descriptions after login
allCommands();
//execute the command
sleep(5);
menu(user_code);
} else{
printf("User code not found\n");
goto H;
}
return 0;
}

