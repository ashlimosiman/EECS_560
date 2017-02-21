#include "Executive.h"

Executive::Executive()
{

}

void Executive::run(double lf)
{
     loadFactor = lf;
     std::cout<<"\nLoad Factor: "<<loadFactor<<"\n\n";

     std::cout<<"Open Hash Testing: \n\n";
     openTest();

     std::cout<<"\nDouble Hash Testing: \n\n";
     doubleTest();

     std::cout<<"\nQuadratic Hash Testing: \n\n";
     quadTest();

}

void Executive::openTest()
{
     OpenHash o_table = OpenHash(tableSize);
     double* timings = new double[5];
     for(int tests = 0; tests < 5; tests++)
     {
          std::cout<<tests + 1<<": ";
          double insertions = loadFactor * tableSize;
          int value = 0;
          double length = 0.0;

          srand(time(NULL));
          timer.start();
          for(int x = 0; x < insertions; x++)
          {
               value = (rand() % 2147483647) + 1;
               o_table.insert(value);
          }
          length = timer.stop();
          timings[tests] = length;
          o_table.reset();
          std::cout<<length<<'\n';
     }
     double avg = averageAmt(timings);
     std::cout<<"Average: "<<avg<<'\n';
}

void Executive::doubleTest()
{
     doubleHash d_table = doubleHash(tableSize, K);
     double* timings = new double[5];

     for(int tests = 0; tests < 5; tests++)
     {
          std::cout<<tests + 1<<": ";
          double insertions = loadFactor * tableSize;
          int value = 0;
          double length = 0.0;

          srand(time(NULL));
          timer.start();
          for(int x = 0; x < insertions; x++)
          {
               value = (rand() % 2147483647) + 1;
               d_table.insert(value);
          }
          length = timer.stop();
          timings[tests] = length;
          d_table.initTable();
          std::cout<<length<<'\n';
     }
     double avg = averageAmt(timings);
     std::cout<<"Average: "<<avg<<'\n';
}

void Executive::quadTest()
{
     quadHash q_table = quadHash(tableSize, K);
     double* timings = new double[5];

     for(int tests = 0; tests < 5; tests++)
     {
          std::cout<<tests + 1<<": ";
          double insertions = loadFactor * tableSize;
          int value = 0;
          double length = 0.0;

          srand(time(NULL));
          timer.start();
          for(int x = 0; x < insertions; x++)
          {
               value = (rand() % 2147483647) + 1;
               q_table.insert(value);
          }
          length = timer.stop();
          timings[tests] = length;
          q_table.initTable();
          std::cout<<length<<'\n';
     }
     double avg = averageAmt(timings);
     std::cout<<"Average: "<<avg<<'\n';
}

double Executive::averageAmt(double* results)
{
     double total = 0;
     for(int x = 0; x < 5; x++)
     {
          total = total + results[x];
     }
     double avg = total / 5;
     return(avg);
}
