#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <iostream>
#include <fstream>



using namespace std;


void shellsort(int a[],int size)
{
    int step,i,j;
    int tmp;

    for(step=size/2;step>0;step/=2)
        for(i=step;i<size;++i)
        {
            tmp=a[i];
            for(j=i-step;j>=0&&a[j]>tmp;j-=step)
                a[j+step]=a[j];
            a[j+step]=tmp;
        }


}


void percolatedown(int a[],int hole,int size)
{
    int child;
    int tmp=a[hole];

    for(;hole*2+1<size;hole=child)
    {
        child=hole*2+1;
        if(child!=size-1&&a[child+1]>a[child])
            child++;
        if(a[child]>tmp)a[hole]=a[child];
        else break;
    }
    a[hole]=tmp;
}

void heapSort(int a[],int size)
{
    int i;
    int tmp;

    for(i=size/2-1;i>=0;i--)
        percolatedown(a,i,size);

    for(i=size-1;i>0;--i)
    {
        tmp=a[0];
        a[0]=a[i];
        a[i]=tmp;
        percolatedown(a,0,i);
    }
}





void bubbleSort(int a[],int size)
{
    int i,j;
   int tmp;
    bool flag=true;

    for(i=1;i<size&&flag;++i)
    {
       flag=false;
       for(j=0;j<size-i;++j)
       if(a[j+1]<a[j])
       {
           tmp=a[j];
           a[j]=a[j+1];
           a[j+1]=tmp;
           flag=true;
       }
    }
}

int divide(int a[],int low,int high)
{
    int k=a[low];
    do{
        while(low<high&&a[high]>=k) --high;
        if(low<high){a[low]=a[high];++low;}
        while(low<high&&a[low]>=k) ++low;
        if(low<high){a[high]=a[low];--high;}
    }while(low!=high);
    a[low]=k;
    return low;
}

void quickSort(int a[],int low,int high)
{
    int mid;
    if(low>=high) return;
    mid=divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}

void quickSort(int a[],int size)
{
    quickSort(a,0,size-1);
}

struct bucketnode
{
    int data;
    bucketnode *next;

    bucketnode(){next=NULL;}
    bucketnode(int d):data(d){next=NULL;}
};

void bucketSort(bucketnode *&p)
{
    bucketnode *bucket[10],*last[10],*tail;
    int i,j,k,base=1,max=0,len=0;

    for(tail=p;tail!=NULL;tail=tail->next)
        if(tail->data>max) max=tail->data;

    if(max==0) len=0;
    else while(max>0){++len;max/=10;}

    for(i=1;i<=len;++i)
    {
        for(j=0;j<=9;++j) bucket[j]=last[j]=NULL;
        while(p!=NULL)
        {
            k=p->data/base%10;
            if(bucket[k]==NULL) bucket[k]=last[k]=p;
            else last[k]=last[k]->next=p;
            p=p->next;
        }
        p=NULL;
        for(j=0;j<=9;++j)
        {
            if(bucket[j]==NULL) continue;
            if(p==NULL) p=bucket[j];
            else tail->next=bucket[j];
            tail=last[j];
        }
        tail->next=NULL;
        base*=10;
    }
}
#endif // SORT_H_INCLUDED
