lab7: main.o minLeftist.o minSkew.o
	g++ -g -std=c++11 -Wall main.o minLeftist.o minSkew.o -o lab7

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

minLeftist.o: minLeftist.cpp minLeftist.h
	g++ -g -std=c++11 -Wall -c minLeftist.cpp

minSkew.o: minSkew.cpp minSkew.h
	g++ -g -std=c++11 -Wall -c minSkew.cpp

clean:
	rm *.o lab7
