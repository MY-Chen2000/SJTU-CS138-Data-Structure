#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include<iostream>
#include "stdlib.h"
#include "time.h"



class RandomNumber{
public:
    RandomNumber(){
        srand(time(0));
    }
    int get(int begin = 0, int end = 1){
        return rand()%(end-begin+1)+begin;
    }
};


#endif // RANDOM_H_INCLUDED
