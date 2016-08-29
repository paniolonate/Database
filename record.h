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
* FILE:		record.h
*
* DESCRIPTION:	This file contains the struct definition for record 
*                
*
***********************************************************/

struct record
{
    int                accountno;         
    char               name[25];
    char               address[80];
    int                yearofbirth;
    struct record*     next;
};
