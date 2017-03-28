#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Timer.h"
#include "minLeftist.h"
#include "minSkew.h"

double leftBuild[4][5];
double leftOps[4][5];
double skewBuild[4][5];
double skewOps[4][5];

void testHeaps(int n, int seed);
void printResults(int* nVal);
double averageVal(double* nums);

int main(int argc, char *argv[])
{
     int values[4] = {50000, 100000, 200000, 400000};

     std::cout<<"TESTING HEAPS\n\n";

     for(int x = 0; x < 4; x++)//n values
     {
          for(int y = 0; y < 5; y++)//seed values
          {
               testHeaps(x, y);
          }
     }

     std::cout<<"TESTING COMPLETE\n";

     printResults(values);

     return(0);
}

void testHeaps(int n, int seed)
{
     Timer timer;
     minLeft testLeft = minLeft();
     minSkew testSkew = minSkew();
     double endTime = 0;
     int opNum = (0.1)*n;

     srand(seed);

     //TESTING BUILDS
          //LEFTIST HEAP
     timer.start();
     for(int x = 0; x < n; x++)
     {
          testLeft.insert((rand() % (4*n)) + 1);
     }
     endTime = timer.stop();
     leftBuild[n][seed] = endTime;

          //SKEW HEAP
     timer.start();
     for(int x = 0; x < n; x++)
     {
          testSkew.insert((rand() % (4*n)) + 1);
     }
     endTime = timer.stop();
     skewBuild[n][seed] = endTime;

     //TESTING OPERATIONS
          //LEFTIST HEAP
     timer.start();
     for(int x = 0; x < opNum; x++)//number of inertions and delemins
     {
          double operation = rand() / (double)RAND_MAX;//get number to decide which operation to do

          if(operation < (0.5))//will deleteMin
          {
               testLeft.deletemin();
          }
          else//will insert
          {
               testLeft.insert((rand() % (4*n)) + 1);
          }
     }
     endTime = timer.stop();
     leftOps[n][seed] = endTime;

          //SKEW HEAP
     timer.start();
     for(int x = 0; x < opNum; x++)//number of inertions and delemins
     {
          double operation = rand() / (double)RAND_MAX;//get number to decide which operation to do

          if(operation < (0.5))//will deleteMin
          {
               testSkew.deletemin();
          }
          else//will insert
          {
               testSkew.insert((rand() % (4*n)) + 1);
          }
     }
     endTime = timer.stop();
     skewOps[n][seed] = endTime;
}

void printResults(int* nVal)
{
     double times[5];
     std::cout<<"RESULTS: \n\n";

     std::cout<<"LEFTIST HEAP BUILD: \n";
     for(int x = 0; x < 4; x++)//n values
     {
          std::cout<<"\nn = "<<nVal[x]<<"\n";

          for(int y = 0; y < 5; y++)//time results from seeds
          {
               std::cout<<"seed "<<y<<": "<<leftBuild[x][y]<<"\n";
               times[y] = leftBuild[x][y];//array to average results
          }
          std::cout<<"Average: "<<averageVal(times)<<"\n";
     }

     std::cout<<"\nLEFTIST HEAP OPERATIONS: \n";
     for(int x = 0; x < 4; x++)//n values
     {
          std::cout<<"\nn = "<<nVal[x]<<"\n";

          for(int y = 0; y < 5; y++)//time results from seeds
          {
               std::cout<<"seed "<<y<<": "<<leftOps[x][y]<<"\n";
               times[y] = leftOps[x][y];//array to average results
          }
          std::cout<<"Average: "<<averageVal(times)<<"\n";
     }

     std::cout<<"\nSKEW HEAP BUILD: \n";
     for(int x = 0; x < 4; x++)//n values
     {
          std::cout<<"\nn = "<<nVal[x]<<"\n";

          for(int y = 0; y < 5; y++)//time results from seeds
          {
               std::cout<<"seed "<<y<<": "<<skewBuild[x][y]<<"\n";
               times[y] = skewBuild[x][y];//array to average results
          }
          std::cout<<"Average: "<<averageVal(times)<<"\n";
     }

     std::cout<<"\nSKEW HEAP OPERATIONS: \n";
     for(int x = 0; x < 4; x++)//n values
     {
          std::cout<<"\nn = "<<nVal[x]<<"\n";

          for(int y = 0; y < 5; y++)//time results from seeds
          {
               std::cout<<"seed "<<y<<": "<<skewOps[x][y]<<"\n";
               times[y] = skewOps[x][y];//array to average results
          }
          std::cout<<"Average: "<<averageVal(times)<<"\n";
     }
}

double averageVal(double* nums)
{
     double total = 0;
     double avg = 0;

     for(int x = 0; x < 5; x++)//sum of the values
     {
          total = total + nums[x];
     }

     avg = total/5;//average of the total

     return(avg);
}
