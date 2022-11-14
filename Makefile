# -*- MakeFile -*-
#Below is a MakeFile, you can use it to compile my Project if you are not using an IDE, and prefer to use a terminal like myself. 
cc := g++
objs := $(wildcard *.o)
cflags := -Wall -Wextra 

binary=bin #If you are NOT using UNIX, might have to add .exe to end of bin


$(binary): main.o process.o sjf.o utility.o fcfs.o rr.o analysis.o 
	$(cc) $^ -o $@

main.o: main.cpp
	g++ -c main.cpp

process.o: process.cpp
	g++ -c process.cpp

utility.o: utility.cpp
	g++ -c utility.cpp

analysis.o: analysis.cpp
	g++ -c analysis.cpp

sjf.o: sjf.cpp
	g++ -c sjf.cpp

fcfs.o: fcfs.cpp
	g++ -c fcfs.cpp

rr.o: rr.cpp
	g++ -c rr.cpp

clean:
	rm -rf $(binary) $(objs) 


	
