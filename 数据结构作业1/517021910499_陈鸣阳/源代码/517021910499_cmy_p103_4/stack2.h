#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


template <class T>
class stack1
{
public:
    virtual bool isempty()const=0;
    virtual void push(const T &x)=0;//进栈
    virtual T pop()=0;//出栈
    virtual T top()const=0;//取栈顶元素
    virtual ~stack1(){}//虚析构函数
};


//****************
//顺序栈
//*****************
template <class T>
class seqstack:public stack1<T>
{
private:
    T *elem;
    int top_p;
    int maxsize;
    void doublespace();

public:
    seqstack(int initsize=10)
    {
      elem=new T[initsize];
      maxsize=initsize;
      top_p=-1;

    }
    ~seqstack()
    {
         delete []elem;
    }
    bool isempty()const;
    void push(const T&x);
    T pop();
    T top()const;

};



template <class T>
bool seqstack<T>::isempty()const
{
    return top_p==-1;
}

template <class T>
void seqstack<T>::push(const T&x)
{
    if(top_p==maxsize-1)doublespace();

    elem[++top_p]=x;
}

template<class T>
T seqstack<T>::pop()
{
    return elem[top_p--];
}

template <class T>
T seqstack<T>::top()const
{
    return elem[top_p];
}

template <class T>
void seqstack<T>::doublespace()
{
    T *tmp=elem;

    elem=new T[2*maxsize];

    for(int i=0;i<maxsize;++i)
    {
        elem[i]=tmp[i];
    }

    maxsize*=2;
    delete[]tmp;
}

//********************
//链接实现
//*********************

template <class T>
class linkstack:public stack1<T>
{
private:
    struct node
    {
        T data;
        node *next;
        node (const T&x,node *N=NULL)
        {
            data=x;
            next=N;
        }
        node():next(NULL){}
        ~node(){}
    };

    node *top_p;

public:
    linkstack();
    ~linkstack();
    bool isempty()const;
    void push(const T&x);
    T pop();
    T top()const;
};

template <class T>
linkstack<T>::linkstack()
{
    top_p=NULL;
}

template <class T>
linkstack<T>::~linkstack()
{
    node *tmp;
    while(top_p!=NULL)
    {
        tmp=top_p;
        top_p=top_p->next;
        delete tmp;
    }
}

template <class T>
bool linkstack<T>::isempty()const
{
    return top_p==NULL;
}

template <class T>
void linkstack<T>::push(const T &x)
{
    top_p=new node(x,top_p);
}


template<class T>
T linkstack<T>::pop()
{
    node *tmp=top_p;
    T x=tmp->data;
    top_p=top_p->next;
    delete tmp;
    return x;
}

template <class T>
T linkstack<T>::top()const
{
    return top_p->data;
}




#endif // STACK_H_INCLUDED







































