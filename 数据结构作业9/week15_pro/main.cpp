//1--10000,2--50000£¨3--100000£¨4--200000£¨5--500000
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void shellSort(int a[],int size);//œ£∂˚≈≈–Ú
void percolateDown(int a[],int hole,int size);
void heapSort(int a[],int size);//∂—≈≈–Ú
void bubbleSort(int a[],int size);//√∞≈›≈≈–Ú
int divide(int a[],int low,int high);
void quickSort(int a[],int low,int high);
void quickSort(int a[],int size){quickSort(a,0,size-1);}//øÏÀŸ≈≈–Ú
struct bucketnode
{
    int data;
    bucketnode *next;

    bucketnode(){next=NULL;}
    bucketnode(int d):data(d){next=NULL;}
};
void bucketSort(bucketnode *&p);//ª˘ ˝≈≈–Ú

int main()
{
    ifstream fp("sort5.txt");
    int i=0,start,a[500000]={0};
    string tmp;
    while(!fp.eof())
    {
        getline(fp,tmp);
        a[i]=atof(tmp.c_str());
        ++i;
    }

    bucketnode *b=new bucketnode,*bmp,*head;
    for(int j=0;j<i;++j)
    {
        b->data=a[j];
        bmp=new bucketnode;
        if(j==0) head=b;
        b=b->next=bmp;
        ++j;
    }

    start=clock();
    shellSort(a,500000);
    cout<<"œ£∂˚≈≈–Ú£∫"<<clock()-start<<"ms"<<endl;

    /*start=clock();
    heapSort(a,500000);
    cout<<"∂—≈≈–Ú£∫"<<clock()-start<<"ms"<<endl;

    /*start=clock();
    bubbleSort(a,500000);
    cout<<"√∞≈›≈≈–Ú£∫"<<clock()-start<<"ms"<<endl;

    start=clock();
    quickSort(a,500000);
    cout<<"øÏÀŸ≈≈–Ú£∫"<<clock()-start<<"ms"<<endl;*/

    /*start=clock();
    bucketSort(head);
    cout<<"ª˘ ˝≈≈–Ú£∫"<<clock()-start<<"ms"<<endl;*/
    return 0;
}


void shellSort(int a[],int size)
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

void percolateDown(int a[],int hole,int size)
{
    int child;
    int tmp=a[hole];

    for(;hole*2+1<size;hole=child)
    {
        child=hole*2+1;
        if(child!=size-1&&a[child+1]>a[child])
            child++;
        if(a[child]>tmp) a[hole]=a[child];
        else break;
    }
    a[hole]=tmp;
}

void heapSort(int a[],int size)
{
    int i;
    int tmp;

    for(i=size/2-1;i>=0;i--)
        percolateDown(a,i,size);
    for(i=size-1;i>0;i--)
    {
        tmp=a[0];a[0]=a[i];a[i]=tmp;
        percolateDown(a,0,i);
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
        for(j=0;j<size-1;++j)
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
