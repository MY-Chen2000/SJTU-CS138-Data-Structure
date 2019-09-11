#ifndef DST_H_INCLUDED
#define DST_H_INCLUDED

#include<iostream>
#include "math.h"
#include<fstream>
#include "string.h"
#include "time.h"

#include "random.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


template <class KEY,class OTHER>
struct SET
{
    KEY key;
    OTHER other;
};

template<class KEY,class OTHER>
class dynamicSearchTable
{
public:
    virtual SET<KEY,OTHER> *find(const KEY &x)const=0;
    virtual void insert(const SET<KEY,OTHER>&x)=0;
    virtual void remove(const KEY &x)=0;
    virtual ~dynamicSearchTable(){}
};

template <class KEY,class OTHER>
class BinarySearchTree:public dynamicSearchTable<KEY,OTHER>
{
private:
    struct BinaryNode
    {
        SET<KEY,OTHER> data;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode(const SET<KEY,OTHER> &thedata,BinaryNode *lt=NULL,BinaryNode *rt=NULL):data(thedata),left(lt),right(rt){}
    };

    BinaryNode *root;

    bool coflag;

    int sfi=0;
    int sfisize=0;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    SET<KEY,OTHER> *find(const KEY &x)const;
    void insert(const SET<KEY,OTHER>&x);
    void remove(const KEY &x);
    void checkorder();
    void deletei(KEY x);

    SET<KEY,OTHER> *searchfori(int i);
    void midorder();

private:
    void insert(const SET<KEY,OTHER>&x,BinaryNode *&t);
    void remove(const KEY &x,BinaryNode *&t);
    SET<KEY,OTHER>*find(const KEY &x,BinaryNode *t)const;
    void makeEmpty(BinaryNode *t);
    bool checkorder(BinaryNode *&t);

    SET<KEY,OTHER> *searchfori(int i,BinaryNode *t);
    void sfiSon(KEY *&a,BinaryNode *t);
    void deletei(KEY x,BinaryNode *&t);

    //辅助函数
    int high(BinaryNode *t);
    void midorder(BinaryNode *t);

};

template <class KEY,class OTHER>
SET<KEY,OTHER>*BinarySearchTree<KEY,OTHER>::find(const KEY &x)const
{
    return find(x,root);
}

template <class KEY,class OTHER>
SET<KEY,OTHER>*BinarySearchTree<KEY,OTHER>::find(const KEY &x,BinaryNode *t)const
{
    if(t==NULL||t->data.key==x)        //找到或不存在
        return (SET<KEY,OTHER> *)t;
    if(x<t->data.key)
        return find(x,t->left);      //继续查找左子树
    else return find(x,t->right);    //继续查找右子树
}

template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::insert(const SET<KEY,OTHER>&x)
{
    insert(x,root);
}

template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::insert(const SET<KEY,OTHER>&x,BinaryNode *&t)
{
    if(t==NULL)
        t=new BinaryNode(x,NULL,NULL);
    else if(x.key<t->data.key)
        insert(x,t->left);
    else if(t->data.key<x.key)
        insert(x,t->right);
}

template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::remove(const KEY &x)
{
    remove(x,root);
}

template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::remove(const KEY &x,BinaryNode *&t)
{
    if(t==NULL)return;
    if(x<t->data.key)remove(x,t->left);
    else if(x>t->data.key)remove(x,t->right);
    else if(t->left!=NULL&&t->right!=NULL)
    {
        BinaryNode *tmp=t->right;
        while(tmp->left!=NULL)tmp=tmp->left;
        t->data=tmp->data;
        remove(t->data.key,t->right);
    }
    else //被删结点是叶结点或只有一个孩子
    {
        BinaryNode *oldNode=t;
        t=(t->left!=NULL)?t->left:t->right;
        delete oldNode;
    }

}

template<class KEY,class OTHER>
BinarySearchTree<KEY,OTHER>::BinarySearchTree()
{
    root=NULL;
}

template<class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::makeEmpty(BinaryNode *t)
{
    if(t==NULL)return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

template <class KEY,class OTHER>
BinarySearchTree<KEY,OTHER>::~BinarySearchTree()
{
    makeEmpty(root);
}

template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::checkorder()
{
    checkorder(root);
    if(coflag)cout<<"the binatree order is right"<<endl;
    else cout<<"the binatree order is wrong"<<endl;
    coflag=true;

}

template <class KEY,class OTHER>
bool BinarySearchTree<KEY,OTHER>::checkorder(BinaryNode *&t)
{

   if(t==NULL) return true;
   if(t->left!=NULL)
   {
      checkorder(t->left);
   }
   if(t->right!=NULL)checkorder(t->right);

   if((t->left!=NULL)&&(t->left->data.key>t->data.key))coflag=false;
   if((t->right)!=NULL&&(t->right->data.key<t->data.key)) coflag=false;

   return true;

}

template <class KEY,class OTHER>
SET<KEY,OTHER> *BinarySearchTree<KEY,OTHER>::searchfori(int i)
{
    return searchfori(i,root);
}

template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::sfiSon(KEY *&a,BinaryNode *t)
{
    if(t==NULL)return;

    sfiSon(a,t->left);
    a[sfi]=t->data.key;
    sfi++;
    sfisize++;
    sfiSon(a,t->right);
}

template <class KEY,class OTHER>
SET<KEY,OTHER> *BinarySearchTree<KEY,OTHER>::searchfori(int i,BinaryNode *t)
{
    int height=high(root);
     int size=pow(2,height)-1;
     KEY *tmp=new KEY[size];
     sfiSon(tmp,t);


     sfi=0;
     KEY tmp2=tmp[sfisize-i];
     sfisize=0;
     return find(tmp2);

}
template <class KEY,class OTHER>
int BinarySearchTree<KEY,OTHER>::high(BinaryNode *t)
{
    if(t==NULL)
    return 0;

    else return max(high(t->left),high(t->right))+1;



}

template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::deletei(KEY x)
{
    deletei(x,root);
}

template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::deletei(KEY x,BinaryNode *&t)
{
    if(t->left!=NULL)deletei(x,t->left);
    if(t->right!=NULL)deletei(x,t->right);
    if(t->data.key<x)remove(t->data.key,t);
}

struct testdata
{
    int id;
    string name;
    string sex;
    int age;
    int score;
};

void createbin(char * filename)
{
    ifstream fin(filename);

    int tmpid;

    if(!fin.is_open ())
      cout << "Open file failure" << endl;

       BinarySearchTree<int,testdata> tree;
       SET<int,testdata> a;


    while(fin.eof()==0)
    {
        fin>>tmpid;
        a.key=tmpid;
        a.other.id=tmpid;
        fin>>a.other.name;
        fin>>a.other.sex;
        fin>>a.other.age;
        fin>>a.other.score;
        tree.insert(a);
    }
//    tree.midorder();

    fin.close();
}


template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::midorder(BinaryNode *t)
{
    if(t==NULL)return;

    midorder(t->left);
    cout<<t->data.key<<' '/*<<t->data.other*/<<endl;
    midorder(t->right);

}

template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::midorder()
{
    cout<<"\n中序遍历:"<<endl;
    midorder(root);
}

void findbin(char * filename)
{
    ifstream fin(filename);

    int tmpid;

    if(!fin.is_open ())
      cout << "Open file failure" << endl;

       BinarySearchTree<int,testdata> tree;
       SET<int,testdata> a;


    while(fin.eof()==0)
    {
        fin>>tmpid;
        a.key=tmpid;
        a.other.id=tmpid;
        fin>>a.other.name;
        fin>>a.other.sex;
        fin>>a.other.age;
        fin>>a.other.score;
        tree.insert(a);
    }
//    tree.midorder();

    RandomNumber ran;

    for(int i=0;i<500;i++)
    {
        tree.find(ran.get(1,50000));
    }

    for(int i=0;i<500;i++)
    {
        tree.find(ran.get(50001,100000));
    }



    fin.close();
}

void delebin(char * filename,int treesize=50000)
{
    ifstream fin(filename);

    int tmpid;
    int cntsize=0;
    int treeid[treesize];

     vector<int> temp;

    if(!fin.is_open ())
      cout << "Open file failure" << endl;

       BinarySearchTree<int,testdata> tree;
       SET<int,testdata> a;


    while(fin.eof()==0&&cntsize<treesize)
    {
        fin>>tmpid;
        a.key=tmpid;
        a.other.id=tmpid;
        temp.push_back(tmpid);
        fin>>a.other.name;
        fin>>a.other.sex;
        fin>>a.other.age;
        fin>>a.other.score;
        tree.insert(a);
        cntsize++;
    }
//    tree.midorder();

    RandomNumber ran;
    random_shuffle(temp.begin(), temp.end());

    for(int i=0;i<500;i++)
    {
        tree.remove(temp.at(i));
    }

    for(int i=0;i<500;i++)
    {
        tree.remove(ran.get(50001,100000));
    }



    fin.close();
}

#endif // DST_H_INCLUDED
