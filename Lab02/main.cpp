#include <iostream>
#include <fstream>
#include "doubleLinkedList.h"
#include "OpenHash.h"
//COMMENTS

void printMenu();

int main(int argc, char *argv[])
{
    int choice=1;

    std::ifstream init;
    int val=0;

    init.open("test.txt");

    init>>val;
    OpenHash table(val);

    while(init>>val)
    {
         table.insert(val);
    }
    init.close();

    while(choice > 0 && choice < 4)
    {
        //printing options and taking in user's choice
        printMenu();
        std::cin>>choice;

        if(choice == 1)//insert at the end
        {
             int newVal = 0;
             std::cout<<"Value to insert: ";
             std::cin>>newVal;

             table.insert(newVal);
        }
        else if(choice == 2)//delete node the user chooses
        {
             int delVal = 0;
             std::cout<<"Value to delete: ";
             std::cin>>delVal;

             table.remove(delVal);
        }
        else if(choice == 3)//print list
        {
             table.print();
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
