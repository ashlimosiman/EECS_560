#include <iostream>
#include <fstream>
#include <stdlib.h>


void printMenu();

int main(int argc, char *argv[])
{

     int choice = 0;

     /* Filling tree with elemnets from a text file
     std::ifstream data;
     int input = 0;
     data.open("data.txt");

     while(data>>input)
     {
          mainTree.insert(input);
     }

     data.close();
     --------------------------------------------*/

     while(choice != 8)
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
          else if(choice == 4)//levelorder
          {

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
