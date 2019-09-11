#ifndef MYTREE_H_INCLUDED
#define MYTREE_H_INCLUDED

#include<fstream>
#include<iostream>
#include<math.h>
#include<istream>
#include"stack2.h"


using namespace std;



template <class T>
class queue
{
public:
    virtual bool isempty()const=0;                     //判空
    virtual void enqueue(const T&x)=0;        //入队
    virtual T DeQueue()=0;                     //出队
    virtual T gethead()const=0;
    virtual ~queue(){}
};



//*************
//链表实现
//*******************
//template<class T>
//class linkqueue:public queue<T>
//{
//private:
//    struct node
//    {
//        T data;
//        node *next;
//        node (const T&x,node*N=NULL)
//        {
//            data=x;
//            next=N;
//        }
//        node():next(NULL){}
//        ~node(){}
//    };
//
//    node *front,*rear;
//
//public:
//    linkqueue();
//    ~linkqueue();
//    bool isempty()const;
//    void enqueue(const T&x);
//    T dequeue();
//    T gethead()const;
//
//};
//
//template<class T>
//linkqueue<T>::linkqueue()
//{
//    front=rear=NULL;
//}
//
//template<class T>
//linkqueue<T>::~linkqueue()
//{
//    node *tmp;
//    while(front!=NULL)
//    {
//        tmp=front;
//        front=front->next;
//        delete tmp;
//    }
//}
//
//template<class T>
//bool linkqueue<T>::isempty()const
//{
//    return front==NULL;
//}
//
//template<class T>
//T linkqueue<T>::dequeue()
//{
//    node *tmp=front;
//    T value=front->data;
//    front=front->next;
//    if(front==NULL)rear==NULL;
//    delete tmp;
//    return value;
//}
//
//template<class T>
//T linkqueue<T>::gethead()const
//{
//    return front->data;
//}
//
//template <class T>
//void linkqueue<T>::enqueue(const T&x)
//{
//    if(rear==NULL)
//        front=rear=new node(x);            //入队前为空队列
//    else
//      rear=rear->next=new node(x);
//}


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
    //cout << "$ 执行构造函数" << endl;
}

//析构函数
template <class T>
LinkedQueue<T>::~LinkedQueue()
{
    //cout << "$ 执行析构函数" << endl;
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

template<class T>
class btree
{
public:
    virtual void clear()=0;
    virtual bool IsEmpty()const=0;
    virtual T Root(T flag)const=0;
    virtual T parent(T x, T flag)const=0;
    virtual T lchild(T x,T flag)const=0;
    virtual T rchild(T x,T flag)const=0;
    virtual void delleft( T x)=0;
    virtual void delright( T x)=0;
    virtual void preorder()const=0;
    virtual void midorder()const=0;
    virtual void postorder()const=0;
    virtual void levelorder()const=0;
};

//template<class T>
//class binarytree;
//
//template<class T>
//void printtree(binarytree<T>&t,T flag)
//{
//    LinkedQueue<T> q;
//    q.EnQueue(t.root->data);
//    cout<<endl;
//    while(!q.IsEmpty())
//    {
//        T p,l,r;
//        p=q.DeQueue();
//        l=t.lchild(p,flag);
//        r=t.rchild(p,flag);
//        if(l!=flag)q.EnQueue(l);
//        if(r!=flag)q.EnQueue(r);
//    }
//}


template<class T>
class binarytree:public btree<T>
{
//    friend void printtree( binarytree &t, T flag);


private:
    struct node    //二叉树的结点类
    {
        node *left,*right;  //结点左右儿子的地址
        T data;             //结点的数据信息

        node():left(NULL),right(NULL){}
        node(T item,node *l=NULL,node *r=NULL):data(item),left(l),right(r){}
        ~node(){}
    };

    struct stnode
    {
        node *nod;
        int timespop;

        stnode(node *n=NULL):nod(n),timespop(0){}
    };

    node *root;//二叉树的根节点

public:
    int c2d=0;
    binarytree():root(NULL){}
    binarytree(T x){root=new node(x);}
    ~binarytree();
    void clear();
    bool IsEmpty()const;
    T Root(T flag)const;
    T lchild(T x,T flag)const;
    T rchild(T x,T flag)const;
    void delleft(T x);
    void delright(T x);
    void preorder()const;
    void midorder()const;
    void postorder()const;
    void levelorder()const;
    void createtree(T flag);
    void createTree(char *filename, T flag);
    T parent(T x,T flag)const{return flag;}
    //
    void printtree(/*binarytree<T>&t,*/T flag)
{
    LinkedQueue<T> q;
    q.EnQueue(root->data);
    cout<<endl;
    while(!q.IsEmpty())
    {
        T p,l,r;
        q.DeQueue(p);
        l=lchild(p,flag);
        r=rchild(p,flag);
        cout<<p<<"   "<<l<<"   "<<r<<endl;
        if(l!=flag)q.EnQueue(l);
        if(r!=flag)q.EnQueue(r);
    }
}
//
    void pre_order()const;
    void mid_order()const;
    void post_order()const;
void Switch();
void count2Degree();
void checkFull();
void checkComplete();
void createTreeFromPreMid(T * pre, T* mid,int len);

private:
    node *find(T x,node *t)const;
    void clear(node *&t);
    void preorder(node *t)const;
    void midorder(node *t)const;
    void postorder(node *t)const;
    void Switch(node *t);
    void count2Degree(node *t);
    int high(node *t);
    bool checkComplete(node *t);
    void createTreeFromPreMid2(T * pre, T* mid,int len,node *t);
    int GetPos(T * str, T ch,int len);

};

template<class T>
bool binarytree<T>::IsEmpty()const
{
    return root==NULL;
}

template<class T>
T binarytree<T>::Root(T flag)const
{
    if(root==NULL)return flag;
    else return root->data;
}

template<class T>
void binarytree<T>::clear(binarytree<T>::node *&t)
{
    if(t==NULL) return;
    clear(t->left);
    clear(t->right);
    delete t;
    t=NULL;
}

template <class T>
void binarytree<T>::clear()
{
    clear(root);
}

template<class T>
binarytree<T>::~binarytree()
{
    clear(root);
}

template <class T>
void binarytree<T>::preorder(binarytree<T>::node *t)const
{
    if(t==NULL)return;
    //cout<<t->data<<' ';
    preorder(t->left);
    preorder(t->right);
}

template <class T>
void binarytree<T>::preorder()const
{
    //cout<<"\n前序遍历:";
    preorder(root);
}

template <class T>
void binarytree<T>::postorder(binarytree<T>::node *t)const
{
    if(t==NULL)return;

    postorder(t->left);
    postorder(t->right);
    //cout<<t->data<<' ';
}

template <class T>
void binarytree<T>::postorder()const
{
    //cout<<"\n后序遍历:";
    postorder(root);
}

template <class T>
void binarytree<T>::midorder(binarytree<T>::node *t)const
{
    if(t==NULL)return;

    midorder(t->left);
    //cout<<t->data<<' ';
    midorder(t->right);

}

template <class T>
void binarytree<T>::midorder()const
{
    //cout<<"\n中序遍历:";
    midorder(root);
}

template <class T>
void binarytree<T>::levelorder()const
{
    LinkedQueue<node *>que; //LinkedQueue模板 在同一个h 文件
    node *tmp;

    cout<<"\n层次遍历：";
    que.EnQueue(root);

    while(!que.IsEmpty())
    {
        que.DeQueue(tmp);
        cout<<tmp->data<<' ';
        if(tmp->left)que.EnQueue(tmp->left);
        if(tmp->right)que.EnQueue(tmp->right);

    }

}

template<class T>
typename binarytree<T>::node *binarytree<T>::find(T x,binarytree<T>::node *t)const
{
    node *tmp;
    if(t==NULL)return NULL;
    if(t->data==x) return t;
    if(tmp=find(x,t->left))return tmp;
    else return find(x,t->right);
}

template <class T>
void binarytree<T>::delleft(T x)
{
    node *tmp=find(x,root);
    if(tmp==NULL)return;
    clear(tmp->left);
}

template <class T>
void binarytree<T>::delright(T x)
{
    node *tmp=find(x,root);
    if(tmp==NULL)return;
    clear(tmp->right);
}

template<class T>
T binarytree <T>::lchild(T x, T flag)const
{
    node *tmp=find(x,root);
    if(tmp==NULL||tmp->left==NULL)return flag;

    return tmp->left->data;
}

template<class T>
T binarytree <T>::rchild(T x, T flag)const
{
    node *tmp=find(x,root);
    if(tmp==NULL||tmp->right==NULL)return flag;

    return tmp->right->data;
}

template <class T>
void binarytree <T>::createtree(T flag)
{
    LinkedQueue<node *>que;
    node *tmp;
    T x,ldata,rdata;

    //创建树，输入flag表示空
    cout<<"\n输入根节点：";
    cin>>x;
    root=new node(x);
    que.EnQueue(root);

    while(!que.IsEmpty())
    {
        que.DeQueue(tmp);

        cout<<"\n输入"<<tmp->data<<"的两个儿子("<<flag<<"表示空节点):";
        cin>>ldata>>rdata;





        if(ldata!=flag)
        {
            tmp->left=new node(ldata);
            que.EnQueue(tmp->left);
        }
        if(rdata!=flag)
        {
            tmp->right=new node(rdata);
            que.EnQueue(tmp->right);
        }
    }

    //cout<<"create complete!";
}

template <class T>
void  binarytree <T>::createTree(char *filename, T flag)
{
    ifstream fin;
    fin.open(filename);
    if(!fin.is_open ())
      cout << "Open file failure" << endl;




//
//fin>>temp;
//a.insert(i,temp);
//if(&&i<j)
////

    LinkedQueue<node *>que;
    node *tmp;
    T x,ldata,rdata;



    //创建树，输入flag表示空

    int count=0;
    char n1;
    int n;
    fin>>n1;
    n=n1-48;
    //cout<<"size"<<n;
//  while(count<3)
//  {
      int i=0;
      int s,m;
      char m1;
      fin>>m1;
      m=m1-48;
     // cout<<m<<endl;

      s=10*n+m;


      if(fin.eof()==0)
      {
          fin>>x;
          i++;
      }

    root=new node(x);
    que.EnQueue(root);

    while(!que.IsEmpty()&&fin.eof()==0&&i<pow(2,s)-1)
    {
        que.DeQueue(tmp);


        if(fin.eof()==0)
        {
            fin>>ldata;

            i++;
        }
        else break;
         if(fin.eof()==0)
         {
             fin>>rdata;

             i++;
         }
            else break;



        if(ldata!=flag)
        {
            tmp->left=new node(ldata);
            que.EnQueue(tmp->left);
        }
        if(rdata!=flag)
        {
            tmp->right=new node(rdata);
            que.EnQueue(tmp->right);
        }

    }

   // cout<<"create complete!";



//  }


}

template <class T>
void binarytree <T>::Switch(binarytree<T>::node *t)
{
        if(t==NULL)return;
    node *tmp;
    Switch(t->left);
    Switch(t->right);

    tmp=t->left;
    t->left=t->right;
    t->right=tmp;

}

template <class T>
void binarytree <T>::Switch()
{
        cout<<"\n交换:";
    Switch(root);
}

template <class T>
void binarytree <T>::count2Degree(binarytree<T>::node *t)
{

        if(t==NULL)return;

    count2Degree(t->left);
    count2Degree(t->right);
    if(t->left!=NULL&&t->right!=NULL)c2d++;



}

template <class T>
void binarytree <T>::count2Degree()
{

        cout<<"\ncount 2 degree";
    count2Degree(root);
    cout<<c2d<<endl;
    c2d=0;
}



template <class T>
void binarytree <T>::checkFull()
{
count2Degree(root);
   if((pow(2,high(root))-1-pow(2,high(root)-1))==c2d)
   {
       cout<<"full"<<endl;
       c2d=0;
   }
   else
   {
       cout<<"not full"<<endl;
       c2d=0;
   }

}

template <class T>
int binarytree <T>::high(binarytree<T>::node *t)
{
    if(t==NULL)
    return 0;

    else return max(high(t->left),high(t->right))+1;



}


template <class T>
bool binarytree <T>::checkComplete(binarytree<T>::node *t)
{
        if( t == NULL) return true;

        LinkedQueue<node *> que;
        que.EnQueue(t);

        bool flag=false;

        node *tmp;

        while(!que.IsEmpty())
        {

            que.DeQueue(tmp);

            if((tmp->left==NULL)&&(tmp->right!=NULL))
            {
                return false;
            }



            if(flag&&((tmp->left!=NULL)||(tmp->right!=NULL)))
            {
                return false;
            }

            if(tmp->left!=NULL)
            {
                que.EnQueue(tmp->left);
            }

            if(tmp->right!=NULL)
            {
                que.EnQueue(tmp->right);
            }
            else flag=true;
        }

        return true;

}

template <class T>
void binarytree <T>::checkComplete()
{
    if(checkComplete(root))cout<<"is complete"<<endl;
    else cout<<"not complete"<<endl;
}

template <class T>
int binarytree <T>::GetPos(T * str, T ch,int len)
{
    for(int i=0; i<len; i++)
    {
        if(ch==str[i])
        {
            return i;
        }
    }
    return -1;
}

template <class T>
void binarytree <T>::createTreeFromPreMid(T * pre, T * mid,int len)
{
    root=new node(pre[0]);
    createTreeFromPreMid2(pre, mid,len,root);
}


template <class T>
void binarytree <T>::createTreeFromPreMid2(T * pre, T * mid,int len,node *t)
{


    if(t==NULL)return;

    t->data=pre[0];
    int i=GetPos(mid,pre[0],len);

    if(i>=len-1)
    {
        t->right=NULL;

    }

    else t->right=new node(pre[i+1]);

    if(i==0)
        t->left=NULL;
    else t->left=new node(pre[1]);

    createTreeFromPreMid2(&pre[1], mid, i, t->left);
    createTreeFromPreMid2(&pre[i+1], &mid[i+1],len-i-1, t->right);


}


template <class T>
void binarytree<T>::pre_order()const
{
    linkstack<node *> s;
    node *current;

    //cout<<"前序遍历：";
    s.push(root);
    while(!s.isempty())
    {
        current=s.pop();
        //cout<<current->data<<"  " ;
        if(current->right!=NULL)s.push(current->right);
        if(current->left!=NULL)s.push(current->left);
    }
    //cout<<endl;
}

template <class T>
void binarytree<T>::mid_order()const
{
    linkstack<stnode> s;
    stnode current(root);

    //cout<<"中序遍历：";
    s.push(current);
    while(!s.isempty())
    {
        current=s.pop();
        if(++current.timespop==2)
        {
            //cout<<current.nod->data<<"  ";
            if(current.nod->right!=NULL)s.push(stnode(current.nod->right));
        }

        else
        {
            s.push(current);
            if(current.nod->left!=NULL)
                s.push(stnode(current.nod->left));
        }
    }
    //cout<<endl;
}

template<class T>
void binarytree<T>::post_order()const
{
    linkstack<stnode> s;
    stnode current(root);

    //cout<<"后序遍历：";
    s.push(current);

    while(!s.isempty())
    {
        current=s.pop();

        if(++current.timespop==3)
        {
            //cout<<current.nod->data<<"  ";
            continue;
        }
        s.push(current);
        if(current.timespop==1)
        {
            if(current.nod->left!=NULL)
                s.push(stnode(current.nod->left));

        }
        else
        {
            if(current.nod->right!=NULL)s.push(stnode((current.nod->right)));
        }
    }
    //cout<<endl;

}














































#endif // MYTREE_H_INCLUDED
