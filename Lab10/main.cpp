#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "spanTree.h"

int main(int argc, char *argv[])
{
     std::cout<<"Minimum Spanning Tree: \n";

     spanTree tree;
     tree.readFile();
     return(0);
}
