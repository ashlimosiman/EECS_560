#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "BST.h"

void printMenu();

int main(int argc, char *argv[])
{
     BST mainTree;
     int choice = 0;

     /* Filling tree with elemnets from a text file*/
     std::ifstream data;
     int input = 0;
     data.open("data.txt");

     while(data>>input)
     {
          mainTree.insert(input);
     }

     data.close();
     /*--------------------------------------------*/

     while(choice != 8)
     {
          printMenu();
          std::cin>>choice;

          if(choice == 1)//insert
          {
               int newVal = 0;
               std::cout<<"Value to insert: ";
               std::cin>>newVal;
               mainTree.insert(newVal);
          }
          else if(choice == 2)//remove
          {
               int deleter = 0;
               std::cout<<"Value to remove: ";
               std::cin>>deleter;
               mainTree.remove(deleter);
               std::cout<<"\n\nWARNING: Not deleting just yet\n\n";
          }
          else if(choice == 3)//deletemin
          {
               mainTree.deletemin();
               std::cout<<"\n\nWARNING: Not deleting just yet\n\n";
          }
          else if(choice == 4)//deletemax
          {
               mainTree.deletemax();
               std::cout<<"\n\nWARNING: Not deleting just yet\n\n";
          }
          else if(choice == 5)//preorder
          {
               mainTree.preorder();
          }
          else if(choice == 6)//inorder
          {
               mainTree.inorder();
          }
          else if(choice == 7)//levelorder
          {
               mainTree.levelorder();
               std::cout<<"\n\nWARNING: Not printing just yet\n\n";
          }
          else if(choice < 1 || choice > 8) // not an option
          {
               std::cout<<"Invalid input\n";
          }
     }

     if(choice == 8)
     {
          std::cout<<"Exiting...\n\n";
     }

     return(0);
}

void printMenu()
{
     std::cout<<"\nPlease choose one of the following commands: \n"
               <<"1-insert\n"
               <<"2-remove\n"
               <<"3-deletemin\n"
               <<"4-deletemax\n"
               <<"5-preorder\n"
               <<"6-inorder\n"
               <<"7-levelorder\n"
               <<"8-exit\n";
}
