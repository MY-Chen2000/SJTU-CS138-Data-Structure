#include <iostream>
using namespace std;
#include<cstdio>
#include<vector>

#ifndef LINEAR_LIST_H_INCLUDED
#define LINEAR_LIST_H_INCLUDED

template <class T>
class extendedlist
{
public:
    virtual void clear()=0;
    virtual int length()const = 0;
    virtual void insert(int i,const T &x)=0;
  virtual void remove(int i)=0;
   virtual int search(const T &x)const=0;
   virtual T visit(int i)const=0;
    virtual void traverse()const=0;
    virtual int lastIndexOf(const T &x)const=0;
   virtual void halfRemove()=0;
    virtual ~extendedlist(){};
};


//顺序表
//sssssssssssssssssss
template<class T>
class seqlist:public extendedlist<T>
{
private:
    T *data;
    int currentlength;
    int maxsize;
    void doublespace();
    bool checkindex(int idx)const
    {
        if(idx>=currentlength||idx<0)
            return false;
        else return true;
    }
    void reduceSpace(double percentage = 0.25, double reduceRatio = 0.5)
    {
        int tmp=maxsize;
        if ((double(currentlength)/maxsize)<percentage)
        {
             maxsize=maxsize*reduceRatio;
             for(int i=tmp;i>maxsize;--i)delete &data[i];

        }

    }
public:
    seqlist(int initsize=10);
    ~seqlist();
    void clear();
    int length()const;
    void insert(int i,const T &x);
    void remove(int i);
    int search(const T &x)const;
    T visit(int i)const;
    void traverse()const;
    int lastIndexOf(const T &x)const;
     void halfRemove();
};


//单链表
//sssssssssssssssss

template <class T>
class slinklist:public extendedlist<T>
{
private:
    struct node
    {
        T data;
        node *next;

        node(const T &x,node *n=NULL)
        {
            data=x;
            next=n;
        }
        node():next(NULL){};
        ~node(){};
    };
   node *head;
   int currentlength;

   node *move(int i)const;

bool checkindex(int idx)const
    {
        if(idx>=currentlength||idx<0)
            return false;
        else return true;
    }

public:
    slinklist();
    ~slinklist(){clear();delete head;}

    void clear();
    int length()const {return currentlength;}
    void insert(int i,const T&x);
    void remove(int i);
    int search(const T &x)const;
    T visit(int i)const;
    void traverse()const;
    int lastIndexOf(const T &x)const;
    void halfRemove();
};

//双链表
//ssssssssssssss
template<class T>
class dlinklist:public extendedlist<T>
{
private:
    struct node
    {
        T data;
        node *prev,*next;

        node(const T &x,node *p=NULL,node *n=NULL)
        {
            data=x;
            next=n;
            prev=p;
        }
        node():next(NULL),prev(NULL){}
        ~node(){}
    };

    node *head,*tail;
    int currentlength;

    node *move(int i)const;

    bool checkindex(int idx)const
    {
        if(idx>=currentlength||idx<0)
            return false;
        else return true;
    }

public:
    dlinklist();
    ~dlinklist(){clear();delete head;delete tail;}

    void clear();
    int length()const{return currentlength;}
    void insert(int i,const T&x);
    void remove(int i);
    int search(const T&x)const;
    T visit(int i)const;
    void traverse()const;
    int lastIndexOf(const T &x)const;
    void halfRemove();
};

//封装
//sssssssssssssss//
template<class T>
class myvector:public extendedlist<T>
{
private:
    bool checkindex(int idx)const
    {
        if(idx>=vec.size()||idx<0)
            return false;
        else return true;
    }
    //经过测试好像不能delete掉
  //  void reduceSpace(double percentage = 0.25, double reduceRatio = 0.5)
    //{
    //    int tmp=vec.capacity();
    //    if ((double(vec.size())/vec.capacity())<percentage)
  //      {
 //            vec.capacity()=vec.capacity()*reduceRatio;
   //          for(int i=tmp;i>vec.capacity();--i)delete &vec[i];

  //      }

   // }
public:
    vector<T> vec;
    typename vector<T>::iterator vecp;
    typename vector<T>::const_iterator p;
public:
    myvector();
    ~myvector();
   void clear();
   int length()const{return vec.size();}
    void insert(int i,const T &x);
   void remove(int i);
    int search(const T &x)const;
   T visit(int i)const;
   void traverse()const;
    int lastIndexOf(const T &x)const;
    void halfRemove();

};

#endif // LINEAR_LIST_H_INCLUDED



//实现顺序表
//ssssssssssssss
//ssssssssss
//sssssssssssss

template <class T>
seqlist<T>::~seqlist()
{
    delete[]data;
}

template <class T>
void seqlist<T>::clear()
{
    currentlength=0;
}

template <class T>
int seqlist<T>::length()const
{
    return currentlength;
}

template <class T>
T seqlist<T>::visit(int i)const
{
    if(checkindex(i))
    return data[i];
    else {cout<<"wrong input"<<endl;throw -1;}
}

template <class T>
void seqlist<T>::traverse()const
{
    cout<<endl;
    for(int i=0;i<currentlength;++i)
        cout<<data[i]<<endl;
}

template <class T>
seqlist<T>::seqlist(int initsize)//构造函数
{
    data=new T [initsize];
    maxsize=initsize;
    currentlength=0;
}

template <class T>
int seqlist<T>::search(const T &x)const
{
    int i;
    for(i=0;i<currentlength&&data[i]!=x;++i);
    if(i==currentlength)return -1;
    else return i;
}

template <class T>
void seqlist<T>::doublespace()
{
    T *tmp=data;
    maxsize*=2;
    data=new T[maxsize];
    for (int i=0;i<currentlength;++i)
        data[i]=tmp[i];
    delete[]tmp;
}

template <class T>
void seqlist<T>::insert(int i,const T &x)
{
    if(i>0)
        {if(!checkindex(i-1)) {cout<<"wrong input"<<endl;throw -1;}}
    if(i<0){cout<<"wrong input"<<endl;throw -1;}
    if(currentlength==maxsize)
        doublespace();
    for(int j=currentlength;j>i;j--)
        data[j]=data[j-1];
    data[i]=x;
    ++currentlength;
}

template <class T>
void seqlist<T>::remove(int i)
{
    if(checkindex(i))
    {for(int j=i;j<currentlength-1;j++)
            data[j]=data[j+1];
        --currentlength;
        reduceSpace();
        }

    else {cout<<"wrong input"<<endl;throw -1;}

}

template<class T>
int seqlist<T>::lastIndexOf(const T &x)const
{
   int i;
   for(i=currentlength-1;i>=0&&data[i]!=x;--i);
   return i;
}

template<class T>
void seqlist<T>::halfRemove()
{
   for(int j=1;j<=currentlength-1;j++)
   {
        remove(j);
   }


}

//实现单链表
//ssssssssssss
//ssssssssssss
//ssssssssssssssssss
template<class T>
typename slinklist<T>::node *slinklist<T>::move(int i)const
{
    node *p=head;
    while(i-->=0)p=p->next;
    return p;
}

template<class T>
slinklist<T>::slinklist()//构造函数
{
    head=new node;
    currentlength=0;
}

template<class T>
void slinklist<T>::clear()
{
    node *p=head->next,*q;
    head->next=NULL;
    while (p!=NULL)
    {
        q=p->next;
        delete p;
        p=q;
    }
    currentlength=0;
}

template<class T>
void slinklist<T>::insert(int i,const T&x)
{
    node *pos;

        if(i<0){cout<<"wrong input"<<endl;throw -1;}
        else if(!checkindex(i-1)&&i>0) {cout<<"wrong input"<<endl;throw -1;}


    pos=move(i-1);
    pos->next=new node(x,pos->next);
    ++currentlength;
}

template<class T>
void slinklist<T>::remove(int i)
{
    node *pos,*delp;

    if(checkindex(i))
    {
         pos=move(i-1);
    delp=pos->next;
    pos->next=delp->next;
    delete delp;
    --currentlength;
    }
    else {cout<<"wrong input"<<endl;throw -1;}
}

template<class T>
int slinklist<T>::search(const T&x)const
{
    node *p=head->next;
    int i=0;

    while(p!=NULL&&p->data!=x){p=p->next;++i;}
    if(p==NULL)return -1;else return i;
}

template<class T>
T slinklist<T>::visit(int i) const
{
    if(checkindex(i))
    return move(i)->data;
    else {cout<<"wrong input"<<endl;throw -1;}

}

template<class T>
void slinklist<T>::traverse()const
{
    node *p=head->next;
    cout<<endl;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<endl;
}

template<class T>
int slinklist<T>::lastIndexOf(const T &x)const
{
    node *p=head->next;
    int i=-1;

    for(int j=0;j<currentlength;++j)
    {
        if(p->data==x)i=j;
        p=p->next;
    }

    return i;




}

template<class T>
void slinklist<T>::halfRemove()
{
   for(int j=1;j<=currentlength-1;j++)
   {
        remove(j);
   }


}


//实现双链表
//sssssssssssss/
//ssssssssssssss
//sssssssssssss
template<class T>
dlinklist<T>::dlinklist()//构造函数
{
    head=new node;
    head->next=tail=new node;
    tail->prev=head;
    currentlength=0;
}

template<class T>
typename dlinklist<T>::node *dlinklist<T>::move(int i)const
{
    node *p=head;
    while(i-->=0)p=p->next;
    return p;
}

template<class T>
void dlinklist<T>::insert(int i,const T&x)
{
    node *pos,*tmp;

      if(i>0)
        {if(!checkindex(i-1)) throw -1;}
    if(i<0){cout<<"wrong input"<<endl;throw -1;}

    pos=move(i);
    tmp=new node(x,pos->prev,pos);
    pos->prev->next=tmp;
    pos->prev=tmp;
    ++currentlength;
}
template<class T>
void dlinklist<T>::remove(int i)
{
    node *pos;

    if(checkindex(i))
    {
        pos = move(i);
    pos->prev->next=pos->next;
    pos->next->prev=pos->prev;
    delete pos;
    --currentlength;
    }
    else {cout<<"wrong input"<<endl;throw -1;}

}

template<class T>
void dlinklist<T>::clear()
{
    node *p=head->next,*q;
    head->next=tail;
    tail->prev=head;
    while(p!=tail)
    {
        q=p->next;
        delete p;
        p=q;
    }
    currentlength=0;
}

template<class T>
int dlinklist<T>::search(const T&x)const
{
    node *p=head->next;
    int i;

    for(i=0;p!=tail&&p->data!=x;++i)p=p->next;
    if(p==tail)return -1;else return i;
}

template<class T>
T dlinklist<T>::visit(int i)const
{
     if(checkindex(i))
    return move(i)->data;
    else {cout<<"wrong input"<<endl;throw -1;}
}

template<class T>
void dlinklist<T>::traverse()const
{
    node *p=head->next;
    cout<<endl;
    while(p!=tail)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<endl;
}

template<class T>
int dlinklist<T>::lastIndexOf(const T &x)const
{
   node *p=tail->prev;
    int i;

    for(i=0;p!=head&&p->data!=x;++i)p=p->prev;
    if(p==head)return -1;else return currentlength-1-i;

}


template<class T>
void dlinklist<T>::halfRemove()
{
   for(int j=1;j<=currentlength-1;j++)
   {
        remove(j);
   }
}


//封装实现
//ffffffffffffff
//ffffffffffff
//ssfffffffffffff

template<class T>
myvector<T>::myvector()//构造函数
{}

template <class T>
myvector<T>::~myvector()
{
    vec.clear();
}

template <class T>
void myvector<T>::insert(int i,const T&x)
{
    if(i<=vec.size()&&i>=0)
    {
        int j=0;
        for(vecp=vec.begin();j<=i-1;vecp++){j++;}
        vec.insert(vecp,x);
    }
    if(i==vec.size()+1) vec.push_back(x);
    if(i<0||i>vec.size()+1){cout<<"wrong input"<<endl;throw -1;}
}


template<class T>
void myvector<T>::traverse()const
{
  for(int i=0;i<vec.size();i++)
     {
         cout<<vec[i]<<endl;
     }
}

template<class T>
void myvector<T>::remove(int i)
{
     if(!checkindex(i)){cout<<"wrong input"<<endl;throw -1;}
     if(i<=vec.size())
    {
        int j=0;
        for(vecp=vec.begin();j<=i-1;vecp++){j++;}
        vec.erase(vecp);
    }
}


template<class T>
int myvector<T>::lastIndexOf(const T &x)const
{
   int i=0;
   for(i=vec.size()-1;i>=0&&vec[i]!=x;--i);
    return i;
}

template<class T>
void myvector<T>::halfRemove()
{
  for(int j=1;j<=vec.size()-1;j++)
   {
        remove(j);
   }
}

template<class T>
void myvector<T>::clear()
{
    vec.clear();
}

template<class T>
T myvector<T>::visit(int i) const
{
    if(!checkindex(i)){cout<<"wrong input"<<endl;throw -1;}
    return vec.at(i);
}

template <class T>
int myvector<T>::search(const T &x)const
{
    int i=0;
   for(i=0;i<vec.size()&&vec[i]!=x;++i);
    return i;
}

//user类实现
class user
{
    friend  ostream& operator<<(ostream &os,const user& obj);
    friend  bool operator!=(const user &u1,const user &u2);
    friend  bool operator==(const user &u1,const user &u2);
public:
    string name;
    string gender;
    int age;
    int score;
public:
    user(){};
    ~user(){};
};


//user函数重载
ostream& operator<<(ostream &os,const user& obj)
{
    os<<obj.name<<"   "<<obj.gender<<"   "<<obj.age<<"   "<<obj.score;
    return os;
}

bool operator!=(const user &u1,const user &u2)
{
    return !(u1.name==u2.name&&u1.gender==u2.gender&&u1.age==u2.age&&u1.score==u2.score);
}

bool operator==(const user &u1,const user &u2)
{
    return (u1.name==u2.name&&u1.gender==u2.gender&&u1.age==u2.age&&u1.score==u2.score);
}
//



























