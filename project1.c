/*********************************************************
*
* NAME:		Nathan Nahina
*
* HOMEWORK:	Project 1
*
* CLASS:	ICS 212
*
* Instructor:	Ravi Narayan
*
* DATE:		July 3, 2016
*
* FILE:		project1.c
*
* DESCRIPTION:	This file contains the driver for Project 1,
*               the fully functionable database program 
*
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "record.h"
#include "databasefunctions.h"

/* Global variable definition */
int debugmode = 0;

/*********************************************************
*
* Function name:    main
*
* DESCRIPTION:	The driver for my project1 user interface
*               for a functionable database
*
* Parameters:	int argc, char *argv []
*
* Return Values:    int
*
*
***********************************************************/

int main(int argc, char *argv [])
{   

    struct record * start = NULL;
    struct record ** pstart = &start;
    int accountnumber;
    char name [40];
    int yearofbirth;
    char address [100];
    char junk [10];    
    int choice = 0;
    int stop = 0;
    
    /* Read from file and put contents into list of records */
    readfile(pstart, "inputfile2.txt");

    /* Usage of global variable for debugging using command line args */
    if(argc == 1)
    {
        printf("\nRunning in Normal Mode\n\n");
    }
    else if(strcmp(argv[1], "debug") == 0)
    {
        printf("\n@@@@@ Running in Debug Mode @@@@@\n");
        debugmode = 1;
    }
    else
    {
        printf("\nHW3b: Insufficient arguments (%d)\n", argc);
        printf("Usage: HW3b ....\n\n");
        return 0;
    }    
        
    while(choice != 6)
    {  
        printf("\n");
        printf("Database Menu Instructions\n\n");
    
        printf("To add a new record in the database: ");
        printf("Enter \"1\"\n");
        printf("\n");

        printf("To modify a record in the database: ");
        printf("Press \"2\"\n");
        printf("\n");

        printf("To print information about a record: ");
        printf("Press \"3\"\n");
        printf("\n");
    
        printf("To print all information in the database: ");
        printf("Press \"4\"\n");
        printf("\n");

        printf("To delete an existing record in the database: ");
        printf("Press \"5\"\n");
        printf("\n");

        printf("To quit the program: ");
        printf("Press \"6\"\n");
        printf("\n");
        printf("Please enter a number that corresponds to the option of your choice: \n");
        printf("NOTE: Entering anything besides a menu number will exit that program: \n");
        printf("\n"); 
        scanf("%d", &choice);
        fgets(junk, sizeof(junk), stdin);
        if(choice <= 0 || choice > 6)
        {
            printf("Exiting program\n\n");
            break;
        }
        printf("You have entered: %d\n", choice);
                          
        if(choice ==1)
        {
            printf("Please enter your account number: \n");
            printf("\n");
            if(scanf("%d", &accountnumber) == 0)
            {
                printf("Please enter a positive integer as an account number\n");
                break;
            }
            fgets(junk, sizeof(junk), stdin);
            printf("Your account number is: %d\n", accountnumber);
            
            printf("Please enter your name: \n");
            printf("\n");
            fgets(name, sizeof(name), stdin);
            
            /* Removes '\n' from fgets */
            name[strcspn(name, "\n")] = 0;            

            printf("Your name is: %s\n", name);
 
            printf("Please enter your address and type an exclamation point ");
            printf("(!) to mark the end of your address: ");
            getfield(address, stop);

            printf("Please enter your year of birth: \n");
            printf("\n");
            if(scanf("%d", &yearofbirth) == 0)
            {
                printf("Please enter a positive integer as a year of birth\n");
                break;
            }
            fgets(junk, sizeof(junk), stdin);
            printf("Your year of birth is: %d\n", yearofbirth);

            addRecord(pstart, accountnumber, name, address, yearofbirth);                            
        }
        
        if(choice == 2)
        {    
            printf("Please enter your account number: \n");
            printf("\n");
            if(scanf("%d", &accountnumber) == 0)
            {
                printf("Please enter a positive integer as an account number\n");
                break;
            }
            fgets(junk, sizeof(junk), stdin);
            printf("Your account number is: %d\n", accountnumber);
            printf("\n");

            printf("Please enter a new address and type an exclamation point ");
            printf("(!) to mark the end of your address: ");

            getfield(address, stop);
            modifyRecord(start, accountnumber, address);
        }

        if(choice == 3)
        {    
            printf("\n");
            printf("Please enter the account number of the record you would like to print: \n");
            if(scanf("%d", &accountnumber) == 0)
            {
                printf("Please enter a positive integer as an account number\n");
                break;
            }
            fgets(junk, sizeof(junk), stdin);
            printf("Your account number is: %d\n", accountnumber);
            printf("\n");

            printRecord(start, accountnumber);
        }

        if(choice == 4)
        {
            printf("\n");
            printf("Printing all records: \n");
            printAllRecords(start);
        }

        if(choice == 5)
        {
            printf("\n");
            printf("Please enter the account number of the record you want to delete: \n");
            if(scanf("%d", &accountnumber) == 0)
            {
                 printf("Please enter a positive integer as an account number\n");
                 break;
             }
             fgets(junk, sizeof(junk), stdin);
             printf("The account number you want to delete is: %d\n", accountnumber);
             deleteRecord(pstart, accountnumber);
        }

    } /* End while*/

    /* Write to file to save records */
    writefile(start, "inputfile2.txt");

    printf("\nPROGRAM END@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
    return 1;
}
