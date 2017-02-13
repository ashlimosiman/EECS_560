lab3: main.o
	g++ -g -std=c++11 -Wall main.o -o lab3

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

doubleHash.o: doubleHash.cpp doubleHash.h
	g++ -g -std=c++11 -Wall -c doubleHash.cpp

quadHash.o: quadHash.cpp quadHash.h
	g++ -g -std=c++11 -Wall -c quadHash.cpp

clean:
	rm *.o lab3
