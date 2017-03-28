lab8: main.o minLeftist.o LHNode.o LHQueue.o LQNode.o
	g++ -g -std=c++11 -Wall main.o minLeftist.o LHNode.o LHQueue.o LQNode.o -o lab8

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

minLeftist.o: minLeftist.cpp minLeftist.h
	g++ -g -std=c++11 -Wall -c minLeftist.cpp

LHNode.o: LHNode.cpp LHNode.h
	g++ -g -std=c++11 -Wall -c LHNode.cpp

LHQueue.o: LHQueue.cpp LHQueue.h
	g++ -g -std=c++11 -Wall -c LHQueue.cpp

LQNode.o: LQNode.cpp LQNode.h
	g++ -g -std=c++11 -Wall -c LQNode.cpp

clean:
	rm *.o lab8
