#include "priorityQueue.h"

template<class type>
priorityQueue<type>::priorityQueue(int capacity)
{
    array=new type[capacity];
    maxsize=capacity;
    currentsize=0;
}

template<class type>
priorityQueue<type>::~priorityQueue()
{
    delete[]array;
}

template<class type>
bool priorityQueue<type>::isEmpty()const
{
    return currentsize==0;
}

template<class type>
type priorityQueue<type>::getHead()const
{
    return array[1];
}

template<class type>
void priorityQueue<type>::enQueue(const type &x)
{
    if(currentsize==maxsize-1) doubleSpace();

    int hole=++currentsize;
    for(;hole>1&&x<array[hole/2];hole/=2)
        array[hole]=array[hole/2];
    array[hole]=x;
}

template<class type>
type priorityQueue<type>::deQueue()
{
    type minItem;
    minItem=array[1];
    array[1]=array[currentsize--];
    percolateDown(1);
    return minItem;
}

template<class type>
void priorityQueue<type>::percolateDown(int hole)
{
    int child;
    type tmp=array[hole];

    for(;hole*2<=currentsize;hole=child)
    {
        child=hole*2;
        if(child!=currentsize&&array[child+1]<array[child]) child++;
        if(array[child]<tmp) array[hole]=array[child];
        else break;
    }
    array[hole]=tmp;
}

template<class type>
void priorityQueue<type>::buildHeap()
{
    for(int i=currentsize/2;i>0;i--)
        percolateDown(i);
}

template<class type>
priorityQueue<type>::priorityQueue(const type data[],int size):maxsize(size+10),currentsize(size)
{
    array=new type[maxsize];
    for(int i=0;i<size;++i)
        array[i+1]=data[i];
    buildHeap();
}

template<class type>
void priorityQueue<type>::doubleSpace()
{
    type *tmp=array;
    maxsize*=2;
    array=new type[maxsize];
    for(int i=0;i<=currentsize;++i)
        array[i]=tmp[i];
    delete []tmp;
}
