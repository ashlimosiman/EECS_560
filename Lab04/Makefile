lab4: main.o Node.o LinkedList.o OpenHash.o doubleHash.o quadHash.o Executive.o
	g++ -g -std=c++11 -Wall main.o Node.o LinkedList.o OpenHash.o doubleHash.o quadHash.o Executive.o -o lab4

main.o: main.cpp Timer.h
	g++ -g -std=c++11 -Wall -c main.cpp

Node.o: Node.cpp Node.h
	g++ -g -std=c++11 -Wall -c Node.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -g -std=c++11 -Wall -c LinkedList.cpp

OpenHash.o: OpenHash.cpp OpenHash.h
	g++ -g -std=c++11 -Wall -c OpenHash.cpp

doubleHash.o: doubleHash.cpp doubleHash.h
	g++ -g -std=c++11 -Wall -c doubleHash.cpp

quadHash.o: quadHash.cpp quadHash.h
	g++ -g -std=c++11 -Wall -c quadHash.cpp

Executive.o: Executive.cpp Executive.h
	g++ -g -std=c++11 -Wall -c Executive.cpp

clean:
	rm *.o lab4
