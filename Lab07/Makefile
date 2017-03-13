lab7: main.o minMaxHeap.o
	g++ -g -std=c++11 -Wall main.o minMaxHeap.o -o lab7

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

minMaxHeap.o: minMaxHeap.cpp minMaxHeap.h
	g++ -g -std=c++11 -Wall -c minMaxHeap.cpp

clean:
	rm *.o lab7
