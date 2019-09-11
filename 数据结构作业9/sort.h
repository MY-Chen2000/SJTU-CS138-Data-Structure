#ifndef 9_H_INCLUDED
#define 9_H_INCLUDED



template<class KEY,class OTHER>
void shellsort(SET<KEY,OTHER>a[],int size)
{
    int step,i,j;
    SET<KEY,OTHER>tmp;

    for(step=size/2;step>0;step/=2)
        for(i=step;i<size;++i)
        {
            tmp=a[i];
            for(j=i-step;j>=0&&a[j].key>tmp.key;j-=step)
                a[j+step]=a[j];
            a[j+step]=tmp;
        }


}

template<class KEY,class OTHER>
void heapSort(SET<KEY,OTHER>a[],int size)
{
    int i;
    SET<KEY,OTHER>tmp;

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

template<class KEY,class OTHER>
void percolatedown(SET<KEY,OTHER>a[],int hole,int size)
{
    int child;
    SET<KEY,OTHER>tmp=a[hole];

    for(;hole*2+1<size;hole=child)
    {
        child=hole*2+1;
        if(child!=size-1&&a[child+1].key>a[child].key)
            child++;
        if(a[child].key>tmp.key)a[hole]=a[child];
        else break;
    }
    a[hole]=tmp;
}

template<class KEY,class OTHER>
void bubbleSort(SET<KEY,OTHER>a[],int size)
{
    int i,j;
    SET<KEY,OTHER>tmp;
    bool flag=true;

    for(i=1;i<size&&flag;++i)
    {

    }
}



#endif // 9_H_INCLUDED
