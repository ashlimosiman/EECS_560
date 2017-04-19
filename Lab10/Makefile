lab10: main.o Node.o spanTree.o
	g++ -g -std=c++11 -Wall main.o Node.o spanTree.o -o lab10

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

Node.o: Node.cpp Node.h
	g++ -g -std=c++11 -Wall -c Node.cpp

spanTree.o: spanTree.cpp spanTree.h
	g++ -g -std=c++11 -Wall -c spanTree.cpp

clean:
	rm *.o lab10
