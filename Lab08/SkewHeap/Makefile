lab8: main.o minSkew.o SHNode.o SHQueue.o SQNode.o
	g++ -g -std=c++11 -Wall main.o minSkew.o SHNode.o SHQueue.o SQNode.o -o lab8

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

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
