#all:
#	g++ src/*.cpp -o out
#

# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g

ALL_O = main.o file.o
MAIN_CPP = src/main.cpp

# ****************************************************
 
# Targets needed to bring the executable up to date 
main: $(ALL_O)
	$(CC) $(CFLAGS) -o main $(ALL_O)


#****************************************************

main.o: include/classes.hpp
file.o: include/file.hpp















