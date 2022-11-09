# -*- MakeFile -*-

cc := g++
objs := $(wildcard *.o)
cflags := -Wall -Wextra 
binary=bin


$(binary): main.o process.o sjf.o srtf.o utility.o
	$(cc) $^ -o $@

main.o: main.cpp
	g++ -c main.cpp

process.o: process.cpp
	g++ -c process.cpp

sjf.o: sjf.cpp
	g++ -c sjf.cpp

srtf.o: srtf.cpp
	g++ -c srtf.cpp

utility.o: utility.cpp
	g++ -c utility.cpp


clean:
	rm -rf $(binary) $(objs) 


	
