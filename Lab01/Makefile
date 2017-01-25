lab01: main.o doubleLinkedList.o Node.o
	g++ -g -std=c++11 -Wall main.o doubleLinkedList.o Node.o -o lab01

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

doubleLinkedList.o: doubleLinkedList.cpp doubleLinkedList.h
	g++ -g -std=c++11 -Wall -c doubleLinkedList.cpp

Node.o: Node.cpp Node.h
	g++ -g -std=c++11 -Wall -c Node.cpp

clean:
	rm *.o lab01
