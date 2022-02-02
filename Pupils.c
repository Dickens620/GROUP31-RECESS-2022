#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>
#include <string.h>
MYSQL *getConnection();
void requestActivation(char *userId, MYSQL *conn);
char *commandPrompt();
void commandInterpreter(char *);
void main()
{
    // Mysql variables
    MYSQL *con;
    MYSQL_RES *result;
    MYSQL_ROW row;

    // user info variables for session tracking
    char userId[50];
    char firstName[50];
    char lastName[50];
    char userCode[20];
    char status[50];
    char phoneNumber[30];
    int loop = 1;
    while (loop)
    {
        //
        // Get user information
        printf("\t Welcome Back!\t\n");
        printf("\t Enter Phone Number: ");
        scanf("%s", phoneNumber);
        printf("\n\t Enter Usercode: ");
        scanf("%s", userCode);

        // Connect to the database
        con = mysql_init(NULL);
        con = getConnection();

        // Login logic
        char query[255];

        sprintf(query, "SELECT * FROM pupils WHERE user_code='%s' AND phone_no='%s' ", userCode, phoneNumber);

        // Run query and see, if it returns a non zero value, it means failure
        if (mysql_query(con, query) != 0)
        {
            printf("Query failed  with the following message:\n");
            printf("%s\n", mysql_error(con));
            exit(1);
        }

        // Query successful now check if the user exists
        result = mysql_store_result(con);

        int total = (int)mysql_num_rows(result);
        if (total == 0)
        {
            printf("Wrong Usernme or Posscode\n");
        }
        else
        {
            printf("You have Logged in successfully\n");

            while ((row = mysql_fetch_row(result)) != NULL)
            {
                strcpy(userId, (char *)row[0]);
                strcpy(firstName, (char *)row[1]);
                strcpy(lastName, (char *)row[2]);
                strcpy(status, (char *)row[7]);
            }
            system("clear");
            puts("Welcome Back, ");
            printf("\n\tFull Name: %s %s\t Status: %s\n", firstName, lastName, status);
            // requestActivation(userId, con);
            // printf("\n\n\n\n");
            char command[255];
        cmd:
            printf("Enter Command _> ");
            fflush(stdin);

            scanf("%s", command);
            // Process command
            if (strcmp("Viewall", command) == 0)
            {
            }
            else if (strcmp("Checkstatus", command) == 0)
            {
                printf("\nStatus: %s\n\n\n", status);
                goto cmd;
            }
            else if (strcmp("Viewassignment", command) == 0)
            {
            }
            else if (strcmp("Checkdates", command) == 0)
            {
            }
            else if (strcmp("RequestActivation", command) == 0)
            {
                printf("\nRequesting Activation...\n");
                requestActivation(userId, con);
                printf("\nActivation Request Sent!\n");
                goto cmd;
            }
            else if (strcmp("Logout", command) == 0)
            {
                printf("Logged out!\n\n");
                exit(0);
            }
            else
            {
                printf("\nSorry Command %s is unrecognized\n", command);
                goto cmd;
            }
        }
    }
    printf("Bye!!");
    // printf("%d",howMany);
}

void requestActivation(char *userId, MYSQL *conn)
{

    char query[255];
    sprintf(query, "INSERT INTO activation_requests SET pupil_id='%s'", userId);
    mysql_query(conn, query);
}
MYSQL *getConnection()
{
    MYSQL *con;
    con = mysql_init(NULL);

    if (mysql_real_connect(con, "127.0.0.1", "root", "", "kcpms", 3306, NULL, 0) == NULL)
    {
        printf("The authentication failed with the following message:\n");
        printf("%s\n", mysql_error(con));
        exit(1);
    }
    return con;
}

void commandInterpreter(char *command)
{

    if (strcmp("Viewall", command) == 0)
    {
    }
    else if (strcmp("Checkstatus", command) == 0)
    {
    }
    else if (strcmp("Viewassignment", command) == 0)
    {
    }
    else if (strcmp("Checkdates", command) == 0)
    {
    }
    else if (strcmp("RequestActivation", command) == 0)
    {
    }
    else
    {
    }
}

