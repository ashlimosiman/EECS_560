#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "minSkew.h"

void printMenu();

int main(int argc, char *argv[])
{
     std::cout<<"Skew Heap: \n";
     int choice = 0;
     minSkew theHeap;

     /*ADDING VALUES FROM FILE*/
     int adding = 0;
     std::ifstream file;

     std::cout<<"data.txt elements: ";
     file.open("data.txt");
     while(file>>adding)
     {
          theHeap.insert(adding);//inserting value into heap
          std::cout<<adding<<" ";
     }
     std::cout<<"\n";
     file.close();
     /*DONE ADDING*/

     while(choice != 6)
     {
          printMenu();
          std::cin>>choice;

          if(choice == 1)//insert
          {
               int rookie = 0;
               std::cout<<"Please insert the number that you want to be inserted in the heap: ";
               std::cin>>rookie;

               theHeap.insert(rookie);
          }
          else if(choice == 2)//deletemin
          {
               theHeap.deletemin();
          }
          else if(choice == 3)//preorder
          {
               theHeap.preorder();
          }
          else if(choice == 4)//inorder
          {
               theHeap.inorder();
          }
          else if(choice == 5)//levelorder
          {
               theHeap.levelorder();
          }
          else if(choice < 1 || choice > 6) // not an option
          {
               std::cout<<"Invalid input\n";
          }
     }

     if(choice == 6)
     {
          std::cout<<"Exiting...\n\n";
     }

     return(0);
}

void printMenu()
{
     std::cout<<"\nPlease choose one of the following commands: \n"
               <<"1-insert\n"
               <<"2-deletemin\n"
               <<"3-preorder\n"
               <<"4-inorder\n"
               <<"5-levelorder\n"
               <<"6-Exit\n";
}
