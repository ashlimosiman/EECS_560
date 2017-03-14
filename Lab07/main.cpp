#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "minMaxHeap.h"

void printMenu();

int main(int argc, char *argv[])
{
     minMaxHeap heapful;
     int choice = 0;

     while(choice != 5)
     {
          printMenu();
          std::cin>>choice;

          if(choice == 1)//insert
          {
               int rookie = 0;
               std::cout<<"Please insert the number that you want to be inserted in the tree: ";
               std::cin>>rookie;

               heapful.insert(rookie);
          }
          else if(choice == 2)//deletemin
          {
               heapful.deletemin();
          }
          else if(choice == 3)//deletemax
          {
               heapful.deletemax();
          }
          else if(choice == 4)//levelorder
          {
               heapful.levelorder();
          }
          else if(choice < 1 || choice > 5) // not an option
          {
               std::cout<<"Invalid input\n";
          }
     }

     if(choice == 5)
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
               <<"3-deletemax\n"
               <<"4-levelorder\n"
               <<"5-exit\n";
}
