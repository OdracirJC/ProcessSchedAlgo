# -*- MakeFile -*-

cc := g++
objs := $(wildcard *.o)
cflags := -Wall -Wextra 
binary=bin


$(binary): main.o process.o
	$(cc) $^ -o $@

main.o: main.cpp
	g++ -c main.cpp

process.o: process.cpp
	g++ -c process.cpp

clean:
	rm -rf $(binary) $(objs) 


	
