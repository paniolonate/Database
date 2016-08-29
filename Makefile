hw1 : hw1.o
	gcc -o hw1 hw1.o

hw1.o : hw1.c
	gcc -c hw1.c

hw2 : hw2.o halfstring.o
	gcc -o hw2 hw2.o halfstring.o

hw2.o : hw2.c
	gcc -c hw2.c

halfstring.o : halfstring.c
	gcc -c halfstring.c

hw2two : hw2two.o
	gcc -o hw2two hw2two.o

hw2two.o : hw2two.c
	gcc -c hw2two.c

hw3a : hw3a.o
	gcc -o hw3a hw3a.o

hw3a.o : hw3a.c
	gcc -c hw3a.c

hw3b : hw3b.o database.o
	gcc -o hw3b hw3b.o database.o

hw3b.o: hw3b.c
	gcc -c hw3b.c

database.o: database.c
	gcc -c database.c

hw5 : main.o iofunctions.o
	gcc -o hw5 main.o iofunctions.o

main.o : main.c
	gcc -c main.c

iofunctions.o : iofunctions.c
	gcc -c iofunctions.c

project1: project1.o databasefunctions.o
	gcc -o project1 project1.o databasefunctions.o

project1.o : project1.c
	gcc -c project1.c

databasefunctions.o : databasefunctions.c
	gcc -c databasefunctions.c

clean : 
	rm hw1 hw1.o hw2 hw2.o halfstring.o hw2two hw2two.o hw3b hw3b.o database.o main.o iofunctions.o project1 project1.o

