lab5: main.o Node.o BST.o Queue.o OGNode.o
	g++ -g -std=c++11 -Wall main.o Node.o BST.o Queue.o OGNode.o -o lab5

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

Node.o: Node.cpp Node.h
	g++ -g -std=c++11 -Wall -c Node.cpp

BST.o: BST.cpp BST.h
	g++ -g -std=c++11 -Wall -c BST.cpp

Queue.o: Queue.cpp Queue.h
	g++ -g -std=c++11 -Wall -c Queue.cpp

OGNode.o: OGNode.cpp OGNode.h
	g++ -g -std=c++11 -Wall -c OGNode.cpp

clean:
	rm *.o lab5
