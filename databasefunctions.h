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
* FILE:		databasefunctions.h
*
* DESCRIPTION:	This file contains the database function prototypes 
*
***********************************************************/

int addRecord(struct record **, int, char [], char [], int);
int printRecord(struct record *, int);
int modifyRecord(struct record *, int, char []);
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);
void getfield (char [], int);
int readfile( struct record **, char [ ] );
void writefile( struct record *, char [ ] );
