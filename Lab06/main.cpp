#include <iostream>
#include <fstream>
#include <stdlib.h>


void printMenu();

int main(int argc, char *argv[])
{
     int choice = 0;

     while(choice != 6)
     {
          printMenu();
          std::cin>>choice;

          if(choice == 1)//insert
          {

          }
          else if(choice == 2)//deletemin
          {

          }
          else if(choice == 3)//deletemax
          {

          }
          else if(choice == 4)//remove
          {

          }
          else if(choice == 5)//levelorder
          {

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
     std::cout<<"\nPlease choose one of the following commands by number: \n"
               <<"1-insert\n"
               <<"2-deletemin\n"
               <<"3-deletemax\n"
               <<"4-remove\n"
               <<"5-levelorder\n"
               <<"6-exit\n";
}
