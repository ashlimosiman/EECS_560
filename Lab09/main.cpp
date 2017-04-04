#include <iostream>
#include <fstream>
#include <stdlib.h>

void printMenu();

int main(int argc, char *argv[])
{
     std::cout<<"Binomial Queue: \n";
     int choice = 0;

     /*ADDING VALUES FROM FILE*/
     int adding = 0;
     std::ifstream file;

     std::cout<<"data.txt elements: ";
     file.open("data.txt");
     while(file>>adding)
     {
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

          }
          else if(choice == 2)//deletemin
          {

          }
          else if(choice == 3)//levelorder
          {

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
