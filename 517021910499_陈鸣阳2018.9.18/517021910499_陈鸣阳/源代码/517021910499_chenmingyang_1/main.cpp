#include <iostream>

#include<ctime>

#include<cstdlib>

#include<time.h>

#include<windows.h>

using namespace std;


int max1(int array[],int size,int d)
{
    int max=0,i;
    for(i=0;i<size;++i)array[i]*=d;
    for(i=0;i<size;++i)
          if(array[i]>max) max=array[i];
    return max;
}


int max2(int array[],int size,int d)
{
    int max=0,i;
    for(i=0;i<size;++i)
          if(array[i]>max) max=array[i];
    return max*d;
}


int main()
{
    double Time=0;
double counts=0;
LARGE_INTEGER nFreq;
LARGE_INTEGER nBeginTime;
LARGE_INTEGER nEndTime;
QueryPerformanceFrequency(&nFreq);
    int i;
    srand(time(NULL));
    int a[1000];
    for(i=0;i<1000;++i)
    {
        a[i]=rand();
    }
QueryPerformanceCounter(&nBeginTime);//开始计时
    max1(a,1000,2);
   QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s
    cout<<"数组大小为1000时1-1运行时间："<<Time*1000<<"ms"<<endl;




    Time=0;
    counts=0;

QueryPerformanceFrequency(&nFreq);

    srand(time(NULL));
    int b[10000];
    for(i=0;i<10000;++i)
    {
        b[i]=rand();
    }
QueryPerformanceCounter(&nBeginTime);//开始计时
    max1(b,10000,2);
   QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s
    cout<<"数组大小为10000时1-1运行时间："<<Time*1000<<"ms"<<endl;




    Time=0;
    counts=0;

QueryPerformanceFrequency(&nFreq);
    srand(time(NULL));
    int c[100000];
    for(i=0;i<100000;++i)
    {
        c[i]=rand();
    }
QueryPerformanceCounter(&nBeginTime);//开始计时
    max1(c,100000,2);
   QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s
    cout<<"数组大小为100000时1-1运行时间："<<Time*1000<<"ms"<<endl;




    Time=0;
    counts=0;

QueryPerformanceFrequency(&nFreq);
    srand(time(NULL));
    int d[1000];
    for(i=0;i<1000;++i)
    {
        c[i]=rand();
    }
QueryPerformanceCounter(&nBeginTime);//开始计时
    max2(c,1000,2);
   QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s
    cout<<"数组大小为1000时1-2运行时间："<<Time*1000<<"ms"<<endl;





    Time=0;
    counts=0;

QueryPerformanceFrequency(&nFreq);
    srand(time(NULL));
    int e[10000];
    for(i=0;i<10000;++i)
    {
        e[i]=rand();
    }
QueryPerformanceCounter(&nBeginTime);//开始计时
    max2(e,10000,2);
   QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s
    cout<<"数组大小为10000时1-2运行时间："<<Time*1000<<"ms"<<endl;




    Time=0;
    counts=0;

QueryPerformanceFrequency(&nFreq);
    srand(time(NULL));
    int f[100000];
    for(i=0;i<100000;++i)
    {
        f[i]=rand();
    }
QueryPerformanceCounter(&nBeginTime);//开始计时
    max2(f,100000,2);
   QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s
    cout<<"数组大小为100000时1-2运行时间："<<Time*1000<<"ms"<<endl;
}




























