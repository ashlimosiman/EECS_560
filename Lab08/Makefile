lab8: Lmain.o minLeftist.o LHNode.o LHQueue.o LQNode.o Smain.o minSkew.o SHNode.o SHQueue.o SQNode.o
	g++ -g -std=c++11 -Wall main.o minLeftist.o LHNode.o LHQueue.o LQNode.o Smain.o minSkew.o SHNode.o SHQueue.o SQNode.o -o lab8

Lmain.o: ./LeftistHeap/LeftMain.cpp
	g++ -g -std=c++11 -Wall -c ./LeftistHeap/LeftMain.cpp

minLeftist.o: ./LeftistHeap/minLeftist.cpp ./LeftistHeap/minLeftist.h
	g++ -g -std=c++11 -Wall -c ./LeftistHeap/minLeftist.cpp

LHNode.o: ./LeftistHeap/LHNode.cpp ./LeftistHeap/LHNode.h
	g++ -g -std=c++11 -Wall -c ./LeftistHeap/LHNode.cpp

LHQueue.o: ./LeftistHeap/LHQueue.cpp ./LeftistHeap/LHQueue.h
	g++ -g -std=c++11 -Wall -c ./LeftistHeap/LHQueue.cpp

LQNode.o: ./LeftistHeap/LQNode.cpp ./LeftistHeap/LQNode.h
	g++ -g -std=c++11 -Wall -c ./LeftistHeap/LQNode.cpp

Smain.o: ./SkewHeap/SkewMain.cpp
	g++ -g -std=c++11 -Wall -c ./SkewHeap/SkewMain.cpp

minSkew.o: ./SkewHeap/minSkew.cpp ./SkewHeap/minSkew.h
	g++ -g -std=c++11 -Wall -c ./SkewHeap/minSkew.cpp

SHNode.o: ./SkewHeap/SHNode.cpp ./SkewHeap/SHNode.h
	g++ -g -std=c++11 -Wall -c ./SkewHeap/SHNode.cpp

SHQueue.o: ./SkewHeap/SHQueue.cpp ./SkewHeap/SHQueue.h
	g++ -g -std=c++11 -Wall -c ./SkewHeap/SHQueue.cpp

SQNode.o: ./SkewHeap/SQNode.cpp ./SkewHeap/SQNode.h
	g++ -g -std=c++11 -Wall -c ./SkewHeap/SQNode.cpp

clean:
	rm *.o lab8
