# -*- MakeFile -*-

cc := g++
objs := $(wildcard *.o)
cflags := -Wall -Wextra 
binary=bin


$(binary): main.o process.o sjf.o srtf.o utility.o fcfs.o rr.o analyis.o
	$(cc) $^ -o $@

main.o: main.cpp
	g++ -c main.cpp

process.o: process.cpp
	g++ -c process.cpp

utility.o: utility.cpp
	g++ -c utility.cpp

analyis.o: analyis.cpp
	g++ -c analyis.cpp

sjf.o: sjf.cpp
	g++ -c sjf.cpp

srtf.o: srtf.cpp
	g++ -c srtf.cpp

fcfs.o: fcfs.cpp
	g++ -c fcfs.cpp

rr.o: rr.cpp
	g++ -c rr.cpp

clean:
	rm -rf $(binary) $(objs) 


	
