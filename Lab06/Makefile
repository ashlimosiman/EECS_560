lab6: main.o minThree.o
	g++ -g -std=c++11 -Wall main.o minThree.o -o lab6

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

minThree.o: minThree.cpp minThree.h
	g++ -g -std=c++11 -Wall -c minThree.cpp

clean:
	rm *.o lab6
