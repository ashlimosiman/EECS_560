#include <iostream>

//Due Monday

void printMenu();

int main(int argc, char *argv[])
{
    std::string filename;
    int choice=1;

    //asking user for a file to make a double linked list
    std::cout<<"What is the filename to populate the linked list?\n";
    std::cin>>filename;

    while(choice > 0 && choice < 5)
    {
        //printing options and taking in user's choice
        printMenu();
        std::cin>>choice;

        if(choice == 1)//insert at the end
        {

        }
        else if(choice == 2)//delete node the user chooses
        {

        }
        else if(choice == 3)//reverse the list
        {

        }
        else if(choice == 4)//print list
        {

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
