#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <stdlib.h>

#include"Timer.h"
#include "OpenHash.h"
#include "doubleHash.h"
#include "quadHash.h"

class Executive
{
    private:
         const int tableSize = 600011;//required size of hashing tables
         const int K = 60000;//num times to attempt placing value
         Timer timer;
         double loadFactor;

    public:
         Executive();
         void run(double lf);
         void openTest();
         void doubleTest();
         void quadTest();
         double averageAmt(double* results);
};

#endif
