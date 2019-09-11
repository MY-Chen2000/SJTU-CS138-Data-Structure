#ifndef QUEUE2_H_INCLUDED
#define QUEUE2_H_INCLUDED

#include<iostream>


using namespace std;

template <class T>
class queue
{
public:
    virtual bool isempty()const=0;                     //�п�
    virtual void enqueue(const T&x)=0;        //���
    virtual T dequeue()=0;                     //����
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
//����ʵ��
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
                   //���ǰΪ�ն���
    else
      rear=rear->next=new node(x);
}
*/




#include <iostream>


using namespace std;

template <class T>
struct LinkNode         //��������Ķ���
{
    T data;             //������
    LinkNode<T> *link;  //ָ���򡪡����ָ��
    //����ʼ��ָ���Ա�Ĺ��캯��
    LinkNode(LinkNode<T>* ptr = NULL){ link = ptr; }
    //��ʼ��������ָ���Ա�Ĺ��캯��
    LinkNode(const T& value, LinkNode<T>* ptr = NULL){ data = value; link = ptr; }
};

template <class T>
class LinkedQueue
{
public:
    LinkedQueue();                      //���캯��
    ~LinkedQueue();                     //��������
public:
    LinkNode<T>* getHead() const;   //��ȡ��ͷ���
    bool EnQueue(const T& x);       //��Ԫ��x���
    bool DeQueue(T& x);             //��ͷԪ�س��ӣ�������Ԫ�ص�ֵ������x
    bool IsEmpty() const;           //�ж϶����Ƿ�Ϊ��
    void MakeEmpty();               //��ն��е�����
private:
    LinkNode<T> *front; //��ͷָ�룬����ͷָ��
    LinkNode<T> *rear;  //��βָ�룬����βָ��
};

//���캯��
template <class T>
LinkedQueue<T>::LinkedQueue()
: front(NULL), rear(NULL)
{
    cout << "$ ִ�й��캯��" << endl;
}

//��������
template <class T>
LinkedQueue<T>::~LinkedQueue()
{
    cout << "$ ִ����������" << endl;
    MakeEmpty();
}

//��ȡ��ͷ���
template <class T>
LinkNode<T>* LinkedQueue<T>::getHead() const
{
    return front;
}

//��Ԫ��x���
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

//��ͷԪ�س��ӣ�������Ԫ�ص�ֵ������x
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

//�ж϶����Ƿ�Ϊ��
template <class T>
bool LinkedQueue<T>::IsEmpty() const
{
    return (NULL == front) ? true : false;
}

//��ն��е�����
template <class T>
void LinkedQueue<T>::MakeEmpty()
{
    LinkNode<T> *curNode = NULL;
    while (NULL != front)           //������Ϊ��ʱ��ɾȥ���������н��
    {
        curNode = front;            //���汻ɾ���
        front = curNode->link;      //��ɾ������һ������Ϊͷ���
        delete curNode;             //��������ժ�±�ɾ���
    }
}


#endif // QUEUE2_H_INCLUDED















