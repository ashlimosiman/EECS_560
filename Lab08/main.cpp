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
               int rookie = 0;
               std::cout<<"Please insert the number that you want to be inserted in the heap: ";
               std::cin>>rookie;

          }
          else if(choice == 2)//deletemin
          {

          }
          else if(choice == 3)//preorder
          {

          }
          else if(choice == 4)//inorder
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
     std::cout<<"\nPlease choose one of the following commands: \n"
               <<"1-insert\n"
               <<"2-deletemin\n"
               <<"3-preorder\n"
               <<"4-inorder\n"
               <<"5-levelorder\n"
               <<"6-Exit\n";
}
