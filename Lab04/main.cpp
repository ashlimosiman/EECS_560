#include <iostream>
#include <fstream>

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

/*-----------------------*/

/*Double Hashing*/
    /* if(hashOpt == 2)
     {
          init.open("test.txt");

          init>>val;//taking in size of hash table
          doubleHash table(val);

          while(init>>val)//filling table from file
          {
               table.insert(val);
          }

          init.close();

          while(choice != 4)
          {
               printMenu();//printing user's options
               std::cin>>choice;

               if(choice == 1)//insert
               {
                    int newVal = 0;
                    std::cout<<"Which number do you want to insert into the hash table?\n";
                    std::cin>>newVal;

                    table.insert(newVal);
               }
               else if(choice == 2)//delete value
               {
                    int delValue = 0;
                    std::cout<<"What number do you want to remove from the hash table?\n";
                    std::cin>>delValue;

                    table.remove(delValue);
               }
               else if(choice == 3)//print table
               {
                    table.print();
               }
               else if(choice != 4)//not 1 through 4
               {
                    std::cout<<"Error: That was not an option.\n\n";
               }
          }
     }*/
/*--------------*/

/*Quadratic Hashing*/
    /* if(hashOpt == 1)
     {
          init.open("test.txt");
          init>>val;//taking in size of hash table
          quadHash table(val);

          while(init>>val)//filling table from file
          {
               table.insert(val);
          }

          init.close();

          while(choice != 4)
          {
               printMenu();//printing user's options
               std::cin>>choice;

               if(choice == 1)//insert
               {
                    int newVal = 0;
                    std::cout<<"Which number do you want to insert into the hash table?\n";
                    std::cin>>newVal;

                    table.insert(newVal);
               }
               else if(choice == 2)//delete value
               {
                    int delValue = 0;
                    std::cout<<"What number do you want to remove from the hash table?\n";
                    std::cin>>delValue;

                    table.remove(delValue);
               }
               else if(choice == 3)//print table
               {
                    table.print();
               }
               else if(choice != 4)//not 1 through 4
               {
                    std::cout<<"Error: That was not an option.\n\n";
               }
          }
     }*/
/*-----------------*/

    /*if(choice == 4 || hashOpt == 3)//user chose the quit option from one of the menus
    {
        std::cout<<"Thank You!\n\n";
    }*/

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
