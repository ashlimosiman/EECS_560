lab8: main.o minLeftist.o LHNode.o LHQueue.o LQNode.o minSkew.o SHNode.o SHQueue.o SQNode.o
	g++ -g -std=c++11 -Wall main.o minLeftist.o LHNode.o LHQueue.o LQNode.o minSkew.o SHNode.o SHQueue.o SQNode.o -o lab8

main.o: main.cpp Timer.h
	g++ -g -std=c++11 -Wall -c main.cpp

minLeftist.o: minLeftist.cpp minLeftist.h
	g++ -g -std=c++11 -Wall -c minLeftist.cpp

LHNode.o: LHNode.cpp LHNode.h
	g++ -g -std=c++11 -Wall -c LHNode.cpp

LHQueue.o: LHQueue.cpp LHQueue.h
	g++ -g -std=c++11 -Wall -c LHQueue.cpp

LQNode.o: LQNode.cpp LQNode.h
	g++ -g -std=c++11 -Wall -c LQNode.cpp

minSkew.o: minSkew.cpp minSkew.h
	g++ -g -std=c++11 -Wall -c minSkew.cpp

SHNode.o: SHNode.cpp SHNode.h
	g++ -g -std=c++11 -Wall -c SHNode.cpp

SHQueue.o: SHQueue.cpp SHQueue.h
	g++ -g -std=c++11 -Wall -c SHQueue.cpp

SQNode.o: SQNode.cpp SQNode.h
	g++ -g -std=c++11 -Wall -c SQNode.cpp

clean:
	rm *.o lab8
