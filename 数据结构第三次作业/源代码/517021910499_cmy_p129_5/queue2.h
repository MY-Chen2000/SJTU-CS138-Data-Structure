#ifndef QUEUE2_H_INCLUDED
#define QUEUE2_H_INCLUDED

#include<iostream>


using namespace std;

template <class T>
class queue
{
public:
    virtual bool isempty()const=0;                     //判空
    virtual void enqueue(const T&x)=0;        //入队
    virtual T dequeue()=0;                     //出队
    virtual T gethead()const=0;
    virtual ~queue(){}
};
/*
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
*/

/*
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
        node (const T &x,node*N=NULL)
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
    {
        rear=new node(x);
        front=rear;
    }
                   //入队前为空队列
    else
      rear=rear->next=new node(x);
}
*/




#include <iostream>


using namespace std;

template <class T>
struct LinkNode         //链表结点类的定义
{
    T data;             //数据域
    LinkNode<T> *link;  //指针域——后继指针
    //仅初始化指针成员的构造函数
    LinkNode(LinkNode<T>* ptr = NULL){ link = ptr; }
    //初始化数据与指针成员的构造函数
    LinkNode(const T& value, LinkNode<T>* ptr = NULL){ data = value; link = ptr; }
};

template <class T>
class LinkedQueue
{
public:
    LinkedQueue();                      //构造函数
    ~LinkedQueue();                     //析构函数
public:
    LinkNode<T>* getHead() const;   //获取队头结点
    bool EnQueue(const T& x);       //新元素x入队
    bool DeQueue(T& x);             //队头元素出队，并将该元素的值保存至x
    bool IsEmpty() const;           //判断队列是否为空
    void MakeEmpty();               //清空队列的内容
private:
    LinkNode<T> *front; //队头指针，即链头指针
    LinkNode<T> *rear;  //队尾指针，即链尾指针
};

//构造函数
template <class T>
LinkedQueue<T>::LinkedQueue()
: front(NULL), rear(NULL)
{
    cout << "$ 执行构造函数" << endl;
}

//析构函数
template <class T>
LinkedQueue<T>::~LinkedQueue()
{
    cout << "$ 执行析构函数" << endl;
    MakeEmpty();
}

//获取队头结点
template <class T>
LinkNode<T>* LinkedQueue<T>::getHead() const
{
    return front;
}

//新元素x入队
template <class T>
bool LinkedQueue<T>::EnQueue(const T& x)
{
    LinkNode<T> *newNode = new LinkNode<T>(x);
    if (NULL == newNode)
    {
        return false;
    }

    if (NULL == front)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->link = newNode;
        rear = rear->link;
    }
    return true;
}

//队头元素出队，并将该元素的值保存至x
template <class T>
bool LinkedQueue<T>::DeQueue(T& x)
{
    if (true == IsEmpty())
    {
        return false;
    }
    LinkNode<T> *curNode = front;
    front = front->link;
    x = curNode->data;
    delete curNode;
    return true;
}

//判断队列是否为空
template <class T>
bool LinkedQueue<T>::IsEmpty() const
{
    return (NULL == front) ? true : false;
}

//清空队列的内容
template <class T>
void LinkedQueue<T>::MakeEmpty()
{
    LinkNode<T> *curNode = NULL;
    while (NULL != front)           //当链表不为空时，删去链表中所有结点
    {
        curNode = front;            //保存被删结点
        front = curNode->link;      //被删结点的下一个结点成为头结点
        delete curNode;             //从链表上摘下被删结点
    }
}


#endif // QUEUE2_H_INCLUDED















