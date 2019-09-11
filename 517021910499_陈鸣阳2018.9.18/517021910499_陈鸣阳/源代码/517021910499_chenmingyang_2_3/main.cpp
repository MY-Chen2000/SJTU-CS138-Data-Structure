#include <iostream>

#include<ctime>

#include<cstdlib>

#include<time.h>

#include<windows.h>

using namespace std;

int maxSum(int a[],int left,int right,int &start,int &end)
{
    int maxLeft,maxRight,center;
    int leftSum=0,rightSum=0;
    int maxLeftTmp=0,maxRightTmp=0;
    int startL,startR,endL,endR;

    if(left==right)
    {
        start=end=left;
        return a[left]>0?a[left]:0;
    }

    center=(left+right)/2;
    maxLeft=maxSum(a,left,center,startL,endL);
    maxRight=maxSum(a,center+1,right,startR,endR);

    start=center;
    for(int i=center;i>=left;--i)
    {
        leftSum+=a[i];
        if(leftSum>maxLeftTmp)
        {
            maxLeftTmp=leftSum;
            start=i;
        }
    }

    end=center+1;
    for(int i=center+1;i<=right;++i)
    {
        rightSum+=a[i];
        if(rightSum>maxRightTmp)
        {
            maxRightTmp=rightSum;
            end=i;
        }
    }

    if(maxLeft>maxRight)
         if(maxLeft>maxLeftTmp+maxRightTmp)
         {
             start=startL;
             end=endL;
             return maxLeft;
         }
         else return maxLeftTmp+maxRightTmp;
    else
        if(maxRight>maxLeftTmp+maxRightTmp)
    {
        start=startR;
        end=endR;
        return maxRight;
    }
    else return maxLeftTmp +maxRightTmp;
}



int maxSubsequenceSum(int a[], int size, int &start,int &end)
{
     return maxSum(a,0,size-1,start,end);
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
QueryPerformanceCounter(&nBeginTime);//开始计时
    maxSubsequenceSum(a,100,start,end);
   QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s
    cout<<"数组大小为100时算法三运行时间："<<Time*1000000<<"微秒"<<endl;


    QueryPerformanceFrequency(&nFreq);

    srand(time(NULL));
    int b[1000];
    for(i=0;i<1000;++i)
    {
        b[i]=rand();
            }
QueryPerformanceCounter(&nBeginTime);//开始计时
    maxSubsequenceSum(b,1000,start,end);
   QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s
    cout<<"数组大小为1000时算法三运行时间："<<Time*1000000<<"微秒"<<endl;





QueryPerformanceFrequency(&nFreq);

    srand(time(NULL));
    int c[10000];
    for(i=0;i<10000;++i)
    {
        c[i]=rand();
            }
QueryPerformanceCounter(&nBeginTime);//开始计时
    maxSubsequenceSum(c,10000,start,end);
   QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s
    cout<<"数组大小为10000时算法三运行时间："<<Time*1000000<<"微秒"<<endl;



}






