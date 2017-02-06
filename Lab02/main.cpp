#include <iostream>
#include <fstream>
#include "doubleLinkedList.h"
//COMMENTS

void printMenu();

int main(int argc, char *argv[])
{
    int choice=1;
    doubleLinkedList list;
    std::ifstream init;
    int val=0;

    init.open("test.txt");
    while(init>>val)
    {
         list.addBack(val);
    }
    init.close();

    while(choice > 0 && choice < 4)
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

        else if(choice == 3)//print list
        {
             list.printList();
        }
    }//end of while loop

    if(choice != 4)//user doesn't make a valid choice from the menu
    {
        std::cout<<"Error: Number chosen was not an option\n"
                <<"Quitting...\n";
    }
    else//user chose 5
    {
        std::cout<<"Thank You!\n\n";
    }

    return(0);
}

void printMenu()
{
    std::cout<<"Please choose one of the following commands:\n"
            <<"1- Insert\n"
            <<"2- Delete\n"
            <<"3- Print\n"
            <<"4- Exit\n";
}
