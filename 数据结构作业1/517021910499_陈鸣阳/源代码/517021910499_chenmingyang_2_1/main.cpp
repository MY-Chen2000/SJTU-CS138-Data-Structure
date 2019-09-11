
#include <iostream>

#include<ctime>

#include<cstdlib>

#include<time.h>

#include<windows.h>

using namespace std;


int maxSubsequenceSum(int a[],int size,int &start,int &end)
{
    int maxSum = 0;

    for(int i=0;i<size;i++)
        for(int j=i;j<size;j++)
    {
        int thisSum=0;
        for(int k=i;k<=j;k++)
            thisSum+=a[k];
            if(thisSum>maxSum)
            {
                maxSum=thisSum;
                start=i;
                end=j;
            }
    }

    return maxSum;
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
    int a[10];
    for(i=0;i<10;++i)
    {
        a[i]=rand();
            }
QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ
    maxSubsequenceSum(a,10,start,end);
   QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs
    cout<<"�����СΪ10ʱ�㷨һ����ʱ�䣺"<<Time*1000<<"ms"<<endl;


}
