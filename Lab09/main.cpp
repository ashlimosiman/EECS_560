#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "BinomQueue.h"

void printMenu();

int main(int argc, char *argv[])
{
     std::cout<<"Binomial Queue: \n";
     int choice = 0;
     BinomQueue BQ;

     /*ADDING VALUES FROM FILE*/
     int adding = 0;
     std::ifstream file;

     std::cout<<"data.txt elements: ";
     file.open("data.txt");
     while(file>>adding)
     {
          //BQ.insert(adding);
          std::cout<<adding<<" ";
     }
     std::cout<<"\n";
     file.close();
     /*DONE ADDING*/

     while(choice != 4)
     {
          printMenu();
          std::cin>>choice;

          if(choice == 1)//insert
          {
               int val = 0;
               std::cout<<"Value to insert: ";
               std::cin>>val;

               //BQ.insert(val);
          }
          else if(choice == 2)//deletemin
          {
               BQ.deletemin();
          }
          else if(choice == 3)//levelorder
          {
               BQ.levelorder();
          }
          else if(choice < 1 || choice > 4) // not an option
          {
               std::cout<<"Invalid input\n";
          }
     }

     if(choice == 4)
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
               <<"3-levelorder\n"
               <<"4-Exit\n";
}
