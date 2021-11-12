#all:
#	g++ src/*.cpp -o out
#

# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g

ALL_O = main.o file.o
MAIN_CPP = src/main.cpp
ALL_H = include/classes.hpp include/file.hpp
ALL_C = src/main.cpp src/file.cpp

# ****************************************************
 
# Targets needed to bring the executable up to date 
main: $(ALL_C) $(ALL_H)
	$(CC) $(CFLAGS) -o main $(ALL_C)


#****************************************************














