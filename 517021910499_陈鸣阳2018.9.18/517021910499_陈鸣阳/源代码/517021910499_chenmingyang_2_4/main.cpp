#include <iostream>

#include<ctime>

#include<cstdlib>

#include<time.h>

#include<windows.h>

using namespace std;

int maxSubsequenceSum(int a[],int size,int &start,int &end)
{
    int maxSum,starttmp,thisSum;
    start=end=maxSum=starttmp=thisSum=0;
    for(int j=0;j<size;++j)
    {
        thisSum+=a[j];
        if(thisSum<=0)
        {
            thisSum=0;
            starttmp=j+1;
        }
        else if(thisSum>maxSum)
        {
            maxSum=thisSum;
            start=starttmp;
            end=j;
        }
    }
}




int main()
{
    int start,end;
    double Time=0;
double counts=0;
LARGE_INTEGER nFreq;
LARGE_INTEGER nBeginTime;
LARGE_INTEGER nEndTime;

QueryPerformanceFrequency(&nFreq);
    int i;
    srand(time(NULL));
    int a[100];
    for(i=0;i<100;++i)
    {
        a[i]=rand();
            }
QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ
    maxSubsequenceSum(a,100,start,end);
   QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs
    cout<<"�����СΪ100ʱ�㷨������ʱ�䣺"<<Time*1000000<<"΢��"<<endl;


    QueryPerformanceFrequency(&nFreq);

    srand(time(NULL));
    int b[1000];
    for(i=0;i<1000;++i)
    {
        b[i]=rand();
            }
QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ
    maxSubsequenceSum(b,1000,start,end);
   QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs
    cout<<"�����СΪ1000ʱ�㷨������ʱ�䣺"<<Time*1000000<<"΢��"<<endl;





QueryPerformanceFrequency(&nFreq);

    srand(time(NULL));
    int c[10000];
    for(i=0;i<10000;++i)
    {
        c[i]=rand();
            }
QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ
    maxSubsequenceSum(c,10000,start,end);
   QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs
    cout<<"�����СΪ10000ʱ�㷨������ʱ�䣺"<<Time*1000000<<"΢��"<<endl;



}


