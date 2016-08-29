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
* FILE:		databasefunctions.c
*
* DESCRIPTION:	This file contains the functions that help with record
*               storage in a database. 
*                
*
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "record.h"
#include "databasefunctions.h"

/* Global variable declaration */
extern debugmode;

/*********************************************************
*
* Function name:    addRecord
*
* DESCRIPTION:	A function which adds a new record in 
*               the database
*               
* Parameters:	struct record ** pst, int uaccountno, char uname [], char uaddress [], int uyearofbirth
*
* Return Values:    int
*
*
***********************************************************/

int addRecord(struct record ** pst, int uaccountno, char uname [], char uaddress [], int uyearofbirth)
{
    struct record node;
    struct record * ptemp;
    struct record * ptemp2;
    
    node.accountno = uaccountno;
    strcpy(node.name, uname);
    strcpy(node.address, uaddress);
    node.yearofbirth = uyearofbirth;

    if(debugmode == 1)
    {
         printf("\n@@@ DEBUGMODE In function: addRecord, pst = %p, uaccountno = %d, uname = %s, ", pst, uaccountno, uname);
         printf("uaddress = %s, uyearofbirth = %d\n", uaddress, uyearofbirth);
    }

    /* Adds a record if the list is empty */
    if(*pst == NULL)
    {
        /* Allocate space on the heap and store its address in the house whose
        * address is in pst (start) */
        *pst = malloc(sizeof(struct record));

        /* Go to the house whose address is in pst then go to the house that it 
        * points to and put node in it*/
        **pst = node;
        (*pst)->next = NULL; 
    }
    else
    {
        ptemp2 = malloc(sizeof(struct record));
        *ptemp2 = node;
        ptemp = *pst;
        
        /* If accountno is < address in start */
        if( uaccountno < ((ptemp)->accountno) )
        {  
            ptemp2->next = ptemp;
            *pst = ptemp2;
            return 1;
        }

        while( uaccountno >= ((ptemp)->accountno) )
        {   
            if( ((ptemp)->next) == NULL )
            {
                (ptemp)->next = ptemp2;
                (ptemp2)->next = NULL;
                return 1;
            }
            else
            {
                ptemp = (ptemp)->next;
            }
        } /* End while */
        (ptemp2)->next = (ptemp)->next;
        (ptemp)->next = ptemp2;
        return 1;
    }
    return 0;
}

/*********************************************************
*
* Function name:    printRecord
*
* DESCRIPTION:	A function which prints a record using the accountno
*               as the key
*               
* Parameters:	struct record * st, int uaccountno
*
* Return Values:    int
*
*
***********************************************************/

int printRecord(struct record * st, int uaccountno)
{

    struct record * ptemp;

    if(debugmode == 1)
    {
         printf("\n@@@ DEBUGMODE In function: printRecord, st = %p, uaccountno = %d\n\n", st, uaccountno);
    }

    if(st == NULL)
    {
        printf("\nThe list is empty, there is/are no record(s) to print\n\n");
        return 0;
    }

    ptemp = st;
    while(ptemp != NULL)
    {
        if( uaccountno == ((ptemp)->accountno) )
        {
            printf("\n%d\n%s\n", (ptemp)->accountno, (ptemp)->name);
            printf("%d\n%s\n", (ptemp)->yearofbirth, (ptemp)->address);
        }
        ptemp = (ptemp)->next;
    }
    return 0;
}

/*********************************************************
*
* Function name:    modifyRecord
*
* DESCRIPTION:	A function which modifies a record in the database using the
*               accountno as the key
*               
* Parameters:	struct record * st, int uaccountno, char uaddress []
*
* Return Values:    int
*
*
***********************************************************/

int modifyRecord(struct record * st, int uaccountno, char uaddress [])
{

    struct record * ptemp;

    if(debugmode == 1)
    {
         printf("\n@@@ DEBUGMODE In function: modifyRecord, st = %p, uaccountno = %d, ", 
st, uaccountno);
         printf("uaddress = %s\n\n", uaddress);
    }
    
    if(st == NULL)
    {
        printf("\nThe list is empty, there is/are no record(s) to modify\n\n");
        return 0;
    }

    ptemp = st;
    while(ptemp != NULL)
    {
        if( uaccountno == ((ptemp)->accountno) )
        {
            strcpy((ptemp)->address, uaddress);
        }
        ptemp = (ptemp)->next;
    }

    return 0;

}

/*********************************************************
*
* Function name:    printAllRecords
*
* DESCRIPTION:	A function which prints all information in the database
*               
* Parameters:	struct record * st
*
* Return Values:    void
*
*
***********************************************************/

void printAllRecords(struct record * st)
{
    struct record * temp;

    if(debugmode == 1)
    {
         printf("\n@@@ DEBUGMODE In function: printAllRecords, st = %p\n\n", st);
    }

    if(st == NULL)
    {
        printf("\nThe list is empty, there are no records to print\n\n");
    }
    else
    {
        temp = st;
        while(temp != NULL)
        {   
            printf("\n%d\n%s\n", (temp)->accountno, (temp)->name);
            printf("%d\n%s\n", (temp)->yearofbirth, (temp)->address); 
            temp = (temp)->next;
        }
    }
}

/*********************************************************
*
* Function name:    deleteRecord
*
* DESCRIPTION:	A function which deletes a record in 
*               the database using the accountno as the key
*               
* Parameters:	struct record ** pst, int accNumber
*
* Return Values:    int
*
*
***********************************************************/

deleteRecord(struct record ** pst, int uaccountno)
{
    struct record * ptemp;
    struct record * pbehind;
    int success = 0;

    if(debugmode == 1)
    {
         printf("\n@@@ DEBUGMODE In function: deleteRecord, pst = %p, uaccountno = %d\n\n", pst, uaccountno);
    }

    if(*pst == NULL)
    {
        printf("\nThe list is empty, there is/are no record(s) to delete\n\n");
        return 0;
    }
    
    ptemp = *pst;
    while(ptemp != NULL)
    {
        if((*pst)->accountno == uaccountno)
        {
            if((*pst)->next == NULL)
            {
                   free(ptemp);
                   *pst = NULL;
                   return 1;
            }
            else
            {
                ptemp = (*pst)->next;
                free(*pst);
                *pst = ptemp;
            }
        }
        else
        {
            pbehind = ptemp;
            if((ptemp)->next != NULL)
            {
                ptemp = (ptemp)->next;
            }
            
            if(uaccountno == ((ptemp)->accountno))
            {
                (pbehind)->next = (ptemp)->next;
                free(ptemp);
                ptemp = (pbehind)->next; /* was (ptemp)->next */
             if(ptemp == NULL)
                return 1;
            }
        } 
        
        ptemp = (ptemp)->next;
    } /* End while */
    if(success == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*********************************************************
*
* Function name:    getfield
*
* DESCRIPTION:	A function which obtains the address information from
*               the user until the char '!' is found in the input
*               
* Parameters:	char address [], int end
*
* Return Values:    void
*
*
***********************************************************/

void getfield(char address [], int end)
{   
    int count = 0;
    int go = 1;

    if(debugmode == 1)
    {
         printf("\n@@@ DEBUGMODE In function: getfield, address = %s", address);
         printf(", end = %d\n\n", end);
    }

    while(go != 0)
    {   
        
        /* Breaks out of the loop when '!' is found in an address */
        if(end == '!')
        {
            go = 0;
            break;
        }
        /* Read from user 1 char at a time then copies to address[] and 
         * adds the null character directly after each copy */
	end = fgetc(stdin);
        address[count] = end;
        address[count + 1] = '\0';
        count++;
        
    }
    /* Replace '!' with '\0' */
    address[count - 1] = address[count];
}

/*********************************************************
*
* Function name:    readfile
*
* DESCRIPTION:	The function that reads from a file
*
* Parameters:	struct record ** pst, char filename [ ]
*
* Return Values:    int
*
*
***********************************************************/
int readfile(struct record ** pst, char filename [])
{   
    FILE * infile;
    int read = 0;
    int reader = 0;
    char junk [10];
    int index = 0;
    int count = 0;
    struct record node;
     
    /* Need to make dynamic array of records? with calloc? how to access each index of 
    *   dynamic array? (ptr + index?) */
            
    infile = fopen(filename, "r");
    
    if(infile == NULL)
    {
        printf("\nThe file does not exist, no records were read from file\n\n");
        return 1;
    }

    while( (reader = fgetc(infile)) != EOF)
    {
        /* Sets buffer back last char it just read */
        ungetc(reader, infile);        
   
        /* Reads account number and updates accountno field and clears buffer */
        fscanf(infile, "%d", &node.accountno); 
        fgets(junk, sizeof(junk), infile);

        /* Reads name and updates name field */
        fgets(node.name, sizeof(node.name), infile);

        /* Removes '\n' from fgets */  
        node.name[strcspn(node.name, "\n")] = 0;

        /* Reads address and updates the address field */
        count = 0;
        while(1)
        {   
            /* Breaks out of the loop when '!' is found in an address */
            if(read == '!')
            {
                read = '\0';
                break;
            }
            /* Read from user 1 char at a time then copies to address[] and 
            * adds the null character directly after each copy */
	    read = fgetc(infile);
            node.address[count] = read;
            node.address[count + 1] = '\0';
            count++;
        }
        /* Replace '!' with '\0' */
        node.address[count - 1] = node.address[count];

        /* Reads year of birth and updates yearofbirth field and clears buffer */
        fscanf(infile, "%d", &node.yearofbirth);
        fgets(junk, sizeof(junk), infile);

        /* Adds node to list */
        addRecord(pst, node.accountno, node.name, node.address, node.yearofbirth);
    }

    fclose(infile);
    return 0;
}

/*********************************************************
*
* Function name:    writefile
*
* DESCRIPTION:	The function that writes to a file
*
* Parameters:	struct record * st, char filename[ ]
*
* Return Values:    void
*
*
***********************************************************/

void writefile(struct record * st, char filename [])
{
    FILE * outfile;
    struct record * ptemp;    

    outfile = fopen(filename, "w");
    ptemp = st;

    while(ptemp != NULL)
    {
        fprintf(outfile, "%d\n", (ptemp)->accountno);
        fprintf(outfile, "%s\n", (ptemp)->name);
        fprintf(outfile, "%s!\n", (ptemp)->address);
        fprintf(outfile, "%d\n", (ptemp)->yearofbirth);
        
        ptemp = (ptemp)->next;
    }

    fclose(outfile);
}
