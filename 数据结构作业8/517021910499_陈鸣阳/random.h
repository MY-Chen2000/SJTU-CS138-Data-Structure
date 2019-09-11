#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include<iostream>
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include<cstring>
#include<sstream>
#include"lll_int.h"


class RandomNumber{
public:
    RandomNumber(){
        srand(time(0));
    }
    int get(int begin = 0, int end = 1){
        return rand()%(end-begin+1)+begin;
    }



};
    RandomNumber rn;
class RandomString
{
    public:
    RandomString(){
        srand(time(0));
    }
    string getshort()
{

    int i1=rn.get(10000,99999);
    int i2=rn.get(1,9);

    stringstream ss;

    ss<<i1;
    string str1 = ss.str();
    ss.str("");
    ss<<i2;
    string str2=ss.str();
    ss.str("");

    ss<<str2;
    ss<<str1;


    string tmp=ss.str();



    return tmp;

}
    string getlong()
{

    int i1=rn.get(1,9);
    int i2=rn.get(100000,999999);
    int i3=rn.get(100000,999999);
    int i4=rn.get(100000,999999);

    stringstream ss;
    ss<<i1;
    string str1 = ss.str();
    ss.str("");
    ss<<i2;
    string str2=ss.str();
    ss.str("");
    ss<<i3;
    string str3=ss.str();
    ss.str("");
    ss<<i4;
    string str4=ss.str();
    ss.str("");

    string tmp=str1+str2+str3+str4;

    return tmp;

}

};






#endif // RANDOM_H_INCLUDED
