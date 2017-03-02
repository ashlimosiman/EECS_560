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
               int newbie = 0;
               std::cout<<"Value to insert: ";
               std::cin>>newbie;
               if(mainTree.insert(newbie))
               {
                    std::cout<<newbie<<" placed in tree\n";
               }
          }
          else if(choice == 2)//remove
          {
               int deleter = 0;
               std::cout<<"Value to remove: ";
               std::cin>>deleter;
               if(mainTree.remove(deleter))
               {
                    std::cout<<deleter<<" removed\n";
               }
          }
          else if(choice == 3)//deletemin
          {
               int minnie = mainTree.getMin();

               if(mainTree.deletemin())
               {
                    std::cout<<minnie<<" removed\n";
               }
          }
          else if(choice == 4)//deletemax
          {
               int maxie = mainTree.getMax();
               if(mainTree.deletemax())
               {
                    std::cout<<maxie<<" removed\n";
               }
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
