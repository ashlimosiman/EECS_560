lab9: main.o Node.o
	g++ -g -std=c++11 -Wall main.o Node.o -o lab9

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

Node.o: Node.cpp Node.h
	g++ -g -std=c++11 -Wall -c Node.cpp
	
clean:
	rm *.o lab9
