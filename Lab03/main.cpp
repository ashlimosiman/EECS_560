#include <iostream>
#include <fstream>

//COMMENTS

//flag is true if index had a number but was deleted

void printMenu();//prints the menu of options the user has
int hashMethod();//prints options of hashing methods, returns value associated with hashing method choice

int main(int argc, char *argv[])
{
/*initializing*/
    int choice=1;
    int hashOpt = hashMethod();
    std::ifstream init;
    int val=0;
/*-----------*/

/*placing values from a text file into the hash table using user's choice of method*/
    init.open("test.txt");

    init>>val;//taking in size of hash table
    //OpenHash table(val);
    //int* hashTable = new int[val];
/*
    while(init>>val)
    {
         table.insert(val);
    }*/
    init.close();
/*-----------------------*/

/*Double Hashing*/

/*--------------*/

/*Quadratic Hashing*/

/*-----------------*/
    while(choice > 0 && choice < 4)
    {
        //printing options and taking in user's choice
        printMenu();
        std::cin>>choice;

        if(choice == 1)//insert at the end
        {
            /* int newVal = 0;
             std::cout<<"Value to insert: ";
             std::cin>>newVal;

             table.insert(newVal);*/
        }
        else if(choice == 2)//delete node the user chooses
        {
            /* int delVal = 0;
             std::cout<<"Value to delete: ";
             std::cin>>delVal;

             table.remove(delVal);*/
        }
        else if(choice == 3)//print list
        {
             //table.print();
        }
    }//end of while loop

    if(choice != 4 || hashOpt != 3)//user doesn't make a valid choice from the menu or didn't make a valid hashing option
    {
        std::cout<<"Error: Number chosen was not an option\n"
                <<"Quitting...\n";
    }
    else//user chose 4 or the user 
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

int hashMethod()
{
    int choice = 0;
    std::cout<<"Please choose one of the following hash methods: \n"
            <<"1-quadratic\n"
            <<"2-double hashing\n"
            <<"3-exit\n";
    std::cin>>choice;
    return(choice);
}
