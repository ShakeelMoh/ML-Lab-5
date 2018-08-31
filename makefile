#My own makefile for ML lab 5

#Declare variables
CC=g++
LIBS=-lm

#First create ".exe" called finds
feedforward: feedforward.o
	$(CC) feedforward.o -o feedforward $(LIBS)

#Need to make Audio.o file though
feedforward.o: feedforward.cpp
	$(CC) -c feedforward.cpp


#Other rules

#Clean .o and exe
clean:
	@rm -f *.o
	@rm -f feedforward

#To run program
run:
	./feedforward
