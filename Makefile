#trains and buses makefile

CC = g++
#-g compile with debug info
#-Wall compiler warnings
CFLAGS = -g -Wall

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.cpp Train.h Bus.h Transporter_Interface.h Person.h Cargo.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	del -f main main.o main.exe