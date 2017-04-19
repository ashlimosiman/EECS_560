#ifndef SPAN_TREE_H
#define SPAN_TREE_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Node.h"

//MIGHT ADD ORGANIZE METHOD

class spanTree
{
     private:
          Node* fullTree;
          Node* kruskalGraph;
          Node* primGraph;
          int size;
          int vertices;

     public:
          spanTree();
          ~spanTree();
          void readFile();
          void makeNodes(int* lengths, int width, int diagonal);
          void addEdge(Node* node);
          void makeKruskal();
          bool kruskalEdge(Node* node, bool* vertex);
          void makePrim();
          bool primEdge(Node* node);
          bool inPrim(Node* node);
          void destroy();
          void print(int graph);
          void printNode(Node* node);
          void printTextFile();
          //void testPrint();
};

#endif
