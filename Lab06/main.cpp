#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "minThree.h"


void printMenu();

int main(int argc, char *argv[])
{
     /*FIRST HALF OF LAB 6*/
     minThreeHeap myHeap;
     int choice = 0;

     while(choice != 6)
     {
          printMenu();
          std::cin>>choice;

          if(choice == 1)//insert
          {
               int included = 0;
               std::cout<<"Value to insert: ";
               std::cin>>included;
               myHeap.insert(included);
          }
          else if(choice == 2)//deletemin
          {
               myHeap.deletemin();
          }
          else if(choice == 3)//deletemax
          {
               myHeap.deletemax();
          }
          else if(choice == 4)//remove
          {
               int banished = 0;
               std::cout<<"Value to remove: ";
               std::cin>>banished;
               myHeap.remove(banished);
          }
          else if(choice == 5)//levelorder
          {
               myHeap.levelorder();
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

     /*FIRST HALF OF LAB 6*/

     /*SECOND HALF OF LAB 6*/
     
     /*SECOND HALF OF LAB 6*/

          return(0);
}

void printMenu()
{
     std::cout<<"\nPlease choose one of the following commands by number: \n"
               <<"1-insert\n"
               <<"2-deletemin\n"
               <<"3-deletemax\n"
               <<"4-remove\n"
               <<"5-levelorder\n"
               <<"6-exit\n";
}
