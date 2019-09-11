#include <iostream>
#include<stack>
#include<vector>
#include<time.h>
#include<windows.h>
#include<ctime>
#include "stack.h"

using namespace std;

int prorandom(int j)//产生从0到j-1的随机数
{

    return rand()*j/(RAND_MAX+1);

}


void stltime()
{
        stack<int,vector<int> >s1;
    int i;

     double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

       QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
    srand(time(NULL));
    for(i=0;i<10000000;++i)s1.push(prorandom(20000));
    for(i=0;i<10000000;++i)
    {
        s1.push(prorandom(20000));
        s1.pop();
    }

    QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<"stl顺序栈"<<Time*1000<<"ms"<<"    ";
}


void seqstack2time()
{
    seqstack2<int> s;
    int i;

         double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

       QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

    srand(time(NULL));

    for(i=0;i<10000000;++i)s.push(prorandom(20000));
    for(i=0;i<10000000;++i)
    {
        s.push(prorandom(20000));
        s.pop();
    }

    QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<"基于顺序表实现的顺序栈"<<Time*1000<<"ms"<<"    ";
}

void seqstacktime()
{
    seqstack<int> s;
    int i;

         double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

       QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

    srand(time(NULL));

    for(i=0;i<10000000;++i)s.push(prorandom(20000));
    for(i=0;i<10000000;++i)
    {
        s.push(prorandom(20000));
        s.pop();
    }

    QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<"顺序栈"<<Time*1000<<"ms"<<"    ";
}

void linkstacktime()
{
    linkstack<int> s;
    int i;

         double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

       QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

    srand(time(NULL));

    for(i=0;i<10000000;++i)s.push(prorandom(20000));
    for(i=0;i<10000000;++i)
    {
        s.push(prorandom(20000));
        s.pop();
    }

    QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<"链接实现栈"<<Time*1000<<"ms"<<"    ";
}


int main()
{
    for(int i=0;i<10;i++)
    {
    linkstacktime();
    stltime();
    seqstack2time();
    seqstacktime();

    cout<<endl;

    }

    return 0;
}
