#include "spanTree.h"

spanTree::spanTree()
{
     fullTree = nullptr;//all edges
     primGraph = nullptr;//prim algorithm list
     kruskalGraph = nullptr;//kruskal algorithm list
     size = 0;//number of edges in tree
     vertices = 0;//number of vertices in graph
}

spanTree::~spanTree()
{
     destroy();
}

void spanTree::readFile()
{
     printTextFile();
     int* testListRow = nullptr;
     int tests = 0;//num of graphs
     int val = 0;//equivalent to n, referring to n x n Matrix (or graph)
     std::ifstream file;

     file.open("data.txt");
     file>>tests;//getting number of graphs

     std::cout<<"Output: \n";

     for(int x = 0; x < tests; x++)//num tests
     {
          file>>val;//size of one side of current matrix
          vertices = val;

          testListRow = new int[val];//make new array for each row

          for(int y = 0; y < val; y++)//row
          {
               for(int z = 0; z < val; z++)//column
               {
                    file>>testListRow[z];//filling array with elements in row
               }//end z for loop

               makeNodes(testListRow, val, y);//will make edge nodes for upper triangle values
          }//end y for loop

          print(x+1);
          destroy();
     }//end x for loop

     file.close();//close stream
}

void spanTree::makeNodes(int* lengths, int width, int diagonal)
{
     //SHOULD ONLY ADD TO fullTree
     int first = diagonal;
     Node* adding = nullptr;

     for(int x = (diagonal + 1); x < width; x++)
     {
          if(lengths[x] > 0)//edge exists
          {
               //make new node`
               adding = new Node();
               adding->setFirst(first);//first vertex
               adding->setSecond(x);//second vertex
               adding->setLength(lengths[x]);//value of edge
               adding->setNext(nullptr);//looking at nullptr
               //node creation complete

               addEdge(adding);//add to fullTree
               size++;//increase number of edges
          }
     }//end for loop
}

void spanTree::addEdge(Node* node)
{
     //ONLY FOR fullTree
     //end result should be edges organized from smallest cost to largest
     if(fullTree == nullptr)//empty list
     {
          fullTree = node;
     }
     else
     {
          if(fullTree->getLength() > node->getLength())//belongs at the front
          {
               node->setNext(fullTree);
               fullTree = node;
          }
          else//somewhere within the list
          {
               Node* traverse = fullTree;//looks at beginning of tree
               Node* prev = nullptr;

               while((traverse != nullptr) && (traverse->getLength() < node->getLength()))//not nullptr and bigger than current node
               {
                    prev = traverse;//keep scope on previous node
                    traverse = traverse->getNext();//move to the next node
               }

               //add node in correct spot
               prev->setNext(node);
               node->setNext(traverse);
          }
     }
}

void spanTree::makeKruskal()
{
     int numEdges = vertices - 1;//number of edges needed
     int kruskalSize = 0;
     Node* temp = fullTree;
     bool* allowedVertices = new bool[vertices];

     for(int x = 0; x < vertices; x++)
     {
          allowedVertices[x] = false;
     }

     while((kruskalSize < numEdges) && (temp != nullptr))//continue adding edges until all vertices connected without cycles
     {
          if(kruskalEdge(temp, allowedVertices))//will not create a cycle
          {
               //create a new node
               Node* adding = new Node();
               adding->setFirst(temp->getFirst());
               adding->setSecond(temp->getSecond());
               adding->setLength(temp->getLength());
               adding->setNext(nullptr);
               //new node creation complete

               if(kruskalGraph == nullptr)//empty list
               {
                    kruskalGraph = adding;
               }
               else//populated
               {
                    Node* goToEnd = kruskalGraph;
                    while(goToEnd->getNext() != nullptr)//go to last node
                    {
                         goToEnd = goToEnd->getNext();
                    }

                    goToEnd->setNext(adding);
               }

               kruskalSize++;//increase number of edges in list
               allowedVertices[adding->getFirst()] = true;
               allowedVertices[adding->getSecond()] = true;
          }

          temp = temp->getNext();//move to next node
     }//end while
}

bool spanTree::kruskalEdge(Node* node, bool* edges)
{
     if(kruskalGraph == nullptr)//list is empty
     {
          return(true);
     }
     else//populated
     {
          Node* temp1 = kruskalGraph;
          Node* temp2 = kruskalGraph;

          while(temp1->getNext() != nullptr)//reach end of list
          {
               if((node->getFirst() == temp1->getFirst()) || (node->getFirst() == temp1->getSecond()))//vertex shared between edges
               {
                    while(temp2->getNext() != nullptr)//reach end of list
                    {
                         if((node->getSecond() == temp2->getFirst()) || (node->getSecond() == temp2->getSecond()))//vertex shared between edges and creates cycle
                         {
                              return(false);
                         }
                         temp2 = temp2->getNext();
                    }//end temp2 while
               }
               temp1 = temp1->getNext();//next node
          }//end temp1 while

          temp1 = nullptr;
          temp2 = nullptr;
     }
     return(true);//will not create a cycle
}

void spanTree::makePrim()
{
     //start at vertex 0

     int numEdges = vertices - 1;
     int primSize = 0;
     Node* temp = fullTree;
     //Node* min = nullptr;
     bool* allowedVertices = new bool[vertices];

     allowedVertices[0] = true;//initial vertex
     for(int x = 1; x < vertices; x++)
     {
          allowedVertices[x] = false;
     }
     while((primSize < numEdges) && (temp != nullptr))
     {
          if((allowedVertices[temp->getFirst()]) || (allowedVertices[temp->getSecond()]))
          {
               if(primEdge(temp))//will not create cycle
               {
                    Node* adding = new Node;
                    adding->setFirst(temp->getFirst());
                    adding->setSecond(temp->getSecond());
                    adding->setLength(temp->getLength());
                    adding->setNext(nullptr);

                    if(primGraph == nullptr)
                    {
                         primGraph = adding;
                    }
                    else
                    {
                         Node* goToEnd = primGraph;
                         while(goToEnd->getNext() != nullptr)//go to last node
                         {
                              goToEnd = goToEnd->getNext();
                         }

                         goToEnd->setNext(adding);
                    }

                    primSize++;
                    allowedVertices[adding->getFirst()] = true;
                    allowedVertices[adding->getSecond()] = true;
               }
          }

          temp = temp->getNext();
          //std::cout<<"TEST  ";
     }//end while
     //std::cout<<"LEFT\n";
}

bool spanTree::primEdge(Node* node)
{
     if(primGraph == nullptr)//list is empty
     {
          return(true);
     }
     else//populated
     {
          Node* temp1 = primGraph;
          Node* temp2 = primGraph;
          while(temp1 != nullptr)//reach end of list
          {
               if((node->getFirst() == temp1->getFirst()) || (node->getFirst() == temp1->getSecond()))//vertex shared between edges
               {
                    while(temp2 != nullptr)//reach end of list
                    {
                         if((node->getSecond() == temp2->getFirst()) || (node->getSecond() == temp2->getSecond()))//vertex shared between edges and creates cycle
                         {
                              return(false);
                         }
                         temp2 = temp2->getNext();
                    }//end temp2 while
               }
               temp1 = temp1->getNext();//next node
          }//end temp1 while

          temp1 = nullptr;
          temp2 = nullptr;
     }

     return(true);//will not create a cycle
}

bool spanTree::inPrim(Node* node)
{
     Node* temp = primGraph;
     while(temp != nullptr)
     {
          if(node->getFirst() == temp->getFirst())
          {
               if(node->getSecond() == temp->getSecond())
               {
                    return(true);
               }
          }

          temp = temp->getNext();
     }

     return(false);
}

void spanTree::destroy()
{
     Node* temp = nullptr;//temp node to delete front node

     while(fullTree != nullptr)//continue deleting until fullTree list is empty
     {
          temp = fullTree;//get front node
          fullTree = fullTree->getNext();//look at next node
          delete temp;//delete front node
          temp = nullptr;//set temp to nullptr
     }

     fullTree = nullptr;

     while(kruskalGraph != nullptr)//continue deleting until kruskalGraph list is empty
     {
          temp = kruskalGraph;//get front node
          kruskalGraph = kruskalGraph->getNext();//look at next node
          delete temp;//delete front node
          temp = nullptr;//set temp to nullptr
     }

     kruskalGraph = nullptr;

     while(primGraph != nullptr)//continue deleting until primGraph list is empty
     {
          temp = primGraph;//get front node
          primGraph = primGraph->getNext();//look at next node
          delete temp;//delete front node
          temp = nullptr;//set temp to nullptr
     }

     primGraph = nullptr;
}

void spanTree::print(int graph)
{
     Node* temp = nullptr;

     std::cout<<"Graph"<<graph<<": \n";

     std::cout<<"\tKruskal: ";
     makeKruskal();
     temp = kruskalGraph;
     while(temp != nullptr)
     {
          printNode(temp);//print it
          temp = temp->getNext();//go to the next
          std::cout<<' ';
     }
     std::cout<<'\n';

     std::cout<<"\tPrim: ";
     makePrim();
     temp = primGraph;
     while(temp != nullptr)
     {
          printNode(temp);//print it
          temp = temp->getNext();//go to the next
          std::cout<<' ';
     }
     std::cout<<"\n\n";
}

void spanTree::printNode(Node* node)
{
     if(node != nullptr)
     {
          int first = node->getFirst();
          int second = node->getSecond();
          std::cout<<'('<<first<<", "<<second<<')';
     }
}

void spanTree::printTextFile()
{
     std::cout<<"data.txt elements: \n";

     int* testListRow = nullptr;
     int tests = 0;//num of graphs
     int val = 0;//equivalent to n, referring to n x n Matrix (or graph)
     std::ifstream file;

     file.open("data.txt");
     file>>tests;//getting number of graphs
     std::cout<<tests<<'\n';

     for(int x = 0; x < tests; x++)//num tests
     {
          file>>val;//size of one side of current matrix
          std::cout<<val<<'\n';

          testListRow = new int[val];//make new array for each row

          for(int y = 0; y < val; y++)//row
          {
               for(int z = 0; z < val; z++)//column
               {
                    file>>testListRow[z];//filling array with elements in row
                    std::cout<<testListRow[z]<<' ';
               }//end z for loop

               std::cout<<'\n';
          }//end y for loop

          std::cout<<'\n';
     }//end x for loop

     file.close();//close stream
     std::cout<<"..........................................................\n\n";

}
/*
void spanTree::testPrint()
{
     Node* temp = fullTree;
     while(temp != nullptr)
     {
          printNode(temp);//print it
          temp = temp->getNext();//go to the next
          std::cout<<' ';
     }
     std::cout<<'\n';
}
*/
