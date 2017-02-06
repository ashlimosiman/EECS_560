#include <iostream>
#include <fstream>
#include <vector>
#include "doubleLinkedList.h"
//COMMENTS
std::vector<int> originList;

void printMenu();
void fillList(std::string filename);

int main(int argc, char *argv[])
{
    std::string filename;
    int choice=1;
    doubleLinkedList list;


    //asking user for a file to make a double linked list
    std::cout<<"What is the filename to populate the linked list?\n";
    std::cin>>filename;
    fillList(filename);
    /*for(unsigned int x=0; x< originList.size(); x++)
    {
         list.addBack(originList.at(x));
    }*/
    while(!originList.empty())
    {
         list.addFront(originList.back());
         originList.pop_back();
    }

    while(choice > 0 && choice < 5)
    {
        //printing options and taking in user's choice
        printMenu();
        std::cin>>choice;

        if(choice == 1)//insert at the end
        {
             int addVal = 0;
             std::cout<<"Value to add: ";
             std::cin>>addVal;

             if(list.search(addVal))
             {
                  std::cout<<"Integer already in the list.\n";
             }
             else
             {
                  list.addBack(addVal);
             }
        }
        else if(choice == 2)//delete node the user chooses
        {
             int delVal = 0;
             std::cout<<"Value to delete: ";
             std::cin>>delVal;

             if(list.search(delVal))
             {
                  list.removeSelected(delVal);
             }
             else
             {
                  std::cout<<"Integer is not on the list.\n";
             }
        }
        else if(choice == 3)//reverse the list
        {
             std::vector<int> currList = list.toVector();
             doubleLinkedList revList;
             int value = 0;
             std::cout<<"It's not working :(\n\n";
             /*for(unsigned int i = 0 ; i < currList.size() ; i++)
             {
                  revList.addFront(currList.at(i));
             }*/
             /*while(!currList.empty())
             {
                  value = currList.back();
                  revList.addBack(value);
                  currList.pop_back();
             }*/
             //list = revList;
             //currList.clear();
        }
        else if(choice == 4)//print list
        {
             list.printList();
        }
    }//end of while loop

    if(choice != 5)//user doesn't make a valid choice from the menu
    {
        std::cout<<"Error: Number chosen was not an option\n"
                <<"Quitting...\n";
    }
    else//user chose 5
    {
        std::cout<<"Thank You!\n\n";
    }
    originList.clear();


    return(0);
}

void printMenu()
{
    std::cout<<"Please choose one of the following commands:\n"
            <<"1- Insert\n"
            <<"2- Delete\n"
            <<"3- Reverse\n"
            <<"4- Print\n"
            <<"5- Exit\n";
}

void fillList(std::string filename)
{
     std::ifstream init;
     init.open(filename.c_str());

     if(!(init.is_open()) || init.fail())
     {
          std::cout<<"Error: Could not open the file\n\n";
     }
     else
     {
          int temp = 0;
          while(init>>temp)
          {
               originList.push_back(temp);
          }
     }
     init.close();
}
