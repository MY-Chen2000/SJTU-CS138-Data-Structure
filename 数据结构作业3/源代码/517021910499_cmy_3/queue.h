#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template <class T>
class queue
{
public:
    virtual bool isempty;                     //判空
    virtual void enqueue(const T&x)=0;        //入队
    virtual T dequeue()=0                     //出队
    virtual T gethead()const=0;
    virtual ~queue(){}
}

template<class T>
class seqqueue:public queue<T>
{
private:
    T *elem;
    int maxsize;
    int front,rear;
    void doublespace();

public:
    seqqueue(int size=10);
    ~seqqueue();
    bool isempty()const;
    void enqueue(const T&x);
    T dequeue();
    T gethead()const;
};

template<class T>
seqqueue<T>::seqqueue(int size)
{
    elem=new T[size];
    maxsize=size;
    front=rear=0;
}

template<class T>
seqqueue<T>::~seqqueue()
{
    delete[]elem;
}

template<class T>
bool seqqueue<T>::isempty()const
{
    return front==rear;
}

template<class T>
T seqqueue<T>::dequeue()
{
    front=(front+1)%maxsize;
    return elem[front];
}

template<class T>
T seqqueue<T>::gethead()const
{
    return elem[(front+1)%maxsize];
}

template <class T>
void seqqueue<T>::enqueue(const T&x)
{
    if((rear+1)%maxsize==front)doublespace();
    elem[rear]=x;
}

template<class T>
void seqqueue<T>::doublespace()
{
    T*tmp =elem;
    elem=new T[2*maxsize];
    for(int i=1;i<=maxsize;++i)
        elem[i]=tmp[(front+i)%maxsize];
    front=0;rear=maxsize;
    maxsize*=2;
    delete tmp;
}

//*************
//链表实现
//*******************
template<class T>
class linkqueue:public queue<T>
{
private:
    struct node
    {
        T data;
        node *next;
        node (const T&x,node*N=NULL)
        {
            data=x;
            next=N;
        }
        node():next(NULL){}
        ~node(){}
    };

    node *front,*rear;

public:
    linkqueue();
    ~linkqueue();
    bool isempty()const;
    void enqueue(const T&x);
    T dequeue();
    T gethead()const;

};

template<class T>
linkqueue<T>::linkqueue()
{
    front=rear=NULL;
}

template<class T>
linkqueue<T>::~linkqueue()
{
    node *tmp;
    while(front!=NULL)
    {
        tmp=front;
        front=front->next;
        delete tmp;
    }
}

template<class T>
bool linkqueue<T>::isempty()const
{
    return front==NULL;
}

template<class T>
T linkqueue<T>::dequeue()
{
    node *tmp=front;
    T value=front->data;
    front=front->next;
    if(front==NULL)rear==NULL;
    delete tmp;
    return value;
}

template<class T>
T linkqueue<T>::gethead()const
{
    return front->data;
}

template <class T>
void linkqueue<T>::enqueue(const T&x)
{
    if(rear==NULL)
        front=rear=new node(x);            //入队前为空队列
    else
      rear=rear->next=new node(x);
}



#endif // QUEUE_H_INCLUDED















