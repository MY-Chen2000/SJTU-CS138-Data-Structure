#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include "dst.h"

template <class KEY,class OTHER>
class AvlTree:public dynamicSearchTable<KEY,OTHER>
{
    struct AvlNode
    {
        SET<KEY,OTHER> data;
        AvlNode *left;
        AvlNode *right;
        int height;//结点的高度

        AvlNode(const SET<KEY,OTHER> &element ,AvlNode *lt,AvlNode *rt,int h=1):data(element),left(lt),right(rt),height(h){}

    };

    AvlNode *root;


    //辅助变量
    bool coflag;

    int sfi=0;
    int sfisize=0;

public:
    AvlTree(){root=NULL;}
    ~AvlTree(){makeEmpty(root);}
    SET<KEY,OTHER> *find(const KEY &x)const;
    void insert (const SET<KEY,OTHER> &x);
    void remove(const KEY &x);
    void checkorder();

    //
        void midorder();
        //

    SET<KEY,OTHER> *searchfori(int i);
    void deletei(KEY x);


private:
    void insert (const SET<KEY,OTHER> &x,AvlNode *&t);
    bool remove(const KEY &x,AvlNode *&t);
    void makeEmpty(AvlNode *t);
    int height(AvlNode *t)const{return t==NULL?0:t->height;}
    void LL(AvlNode *&t);
    void LR(AvlNode *&t);
    void RL(AvlNode *&t);
    void RR(AvlNode *&t);
    int max(int a,int b){return (a>b)?a:b;}
    bool adjust(AvlNode *&t,int subTree);
    bool checkorder(AvlNode *&t);
     SET<KEY,OTHER> *searchfori(int i,AvlNode *t);
     void deletei(KEY x,AvlNode *&t);


    //辅助函数
    void midorder(AvlNode *t);
    void sfiSon(KEY *&a,AvlNode *t);

};

template <class KEY,class OTHER>
SET<KEY,OTHER> *AvlTree<KEY,OTHER>::find(const KEY &x)const
{
    AvlNode *t=root;

    while(t!=NULL&&t->data.key!=x)
    {
        if(t->data.key>x)t=t->left;
        else t=t->right;


    }
        if(t==NULL)return NULL;
        else return (SET<KEY,OTHER>*)t;
}

template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::LL(AvlNode *&t)
{


    AvlNode *t1=t->left;
    t->left=t1->right;
    t1->right=t;
    t->height=max(height(t->left),height(t->right))+1;
    t1->height=max(height(t1->left),height(t))+1;
    t=t1;
}

template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::RR(AvlNode *&t)
{

    AvlNode *t1=t->right;
    t->right=t1->left;
    t1->left=t;
    t->height=max(height(t->left),height(t->right))+1;
    t1->height=max(height(t1->right),height(t))+1;
    t=t1;
}

template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::LR(AvlNode *&t)
{


    RR(t->left);
    LL(t);
}

template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::RL(AvlNode *&t)
{

    LL(t->right);
    RR(t);
}

template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::insert(const SET<KEY,OTHER>& x)
{
    insert(x,root);
}

template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::insert(const SET<KEY,OTHER>& x,AvlNode *&t)
{
    if(t==NULL)
        t=new AvlNode(x,NULL,NULL);
    else if(x.key<t->data.key)
    {
        insert(x,t->left);
        if(height(t->left)-height(t->right)==2)
            if(x.key<t->left->data.key)LL(t);else LR(t);
    }
    else if(x.key>t->data.key)
    {
        insert(x,t->right);
        if(height(t->right)-height(t->left)==2)
            if(t->right->data.key<x.key)RR(t);else RL(t);
    }


    t->height=max(height(t->left),height(t->right))+1;
}

template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::remove(const KEY & x)
{
    remove(x,root);
}

template <class KEY,class OTHER>
bool AvlTree<KEY,OTHER>::remove(const KEY & x,AvlNode *&t)
{
    if(t==NULL)return true;
    if(x==t->data.key)
    {
        if(t->left==NULL||t->right==NULL)
        {
            AvlNode *oldnode=t;
            t=(t->left!=NULL)?t->left:t->right;
            delete oldnode;
            return false;
        }
        else
        {
            AvlNode *tmp=t->right;
            while(tmp->left!=NULL)tmp=tmp->left;
            t->data=tmp->data;
            if(remove(tmp->data.key,t->right))return true;
            return adjust(t,1);
        }
    }

    if(x<t->data.key)
    {
        if(remove(x,t->left))return true;
        return adjust(t,0);
    }
    else
    {
        if(remove(x,t->right))return true;
        return adjust(t,1);
    }
}

template <class KEY,class OTHER>
bool AvlTree<KEY,OTHER>::adjust(AvlNode *&t,int subTree)
{
    if(subTree)
    {
        if(height(t->left)-height(t->right)==1)return true;
        if(height(t->right)==height(t->left)){--t->height;return false;}
        if(height(t->left->right)>height(t->left->left))
        {
            LR(t);
            return false;
        }
        LL(t);
        if(height(t->right)==height(t->left))return false;else return true;

    }
    else
    {
        if(height(t->left)-height(t->right)==1)return true;
        if(height(t->right)==height(t->left)){--t->height;return false;}
        if(height(t->right->left)>height(t->right->right))
        {
            RL(t);
            return false;
        }
        RR(t);
        if(height(t->right)==height(t->left))return false;else return true;

    }

}


template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::checkorder()
{
    checkorder(root);
    if(coflag)cout<<"the avltree order is right"<<endl;
    else cout<<"the avltree order is wrong"<<endl;
    coflag=true;

}

template <class KEY,class OTHER>
bool AvlTree<KEY,OTHER>::checkorder(AvlNode *&t)
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

template<class KEY,class OTHER>
void AvlTree<KEY,OTHER>::makeEmpty(AvlNode *t)
{
    if(t==NULL)return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::midorder(AvlNode *t)
{
    if(t==NULL)return;

    midorder(t->left);
    cout<<t->data.key<<' '/*<<t->data.other*/<<endl;
    midorder(t->right);

}

template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::midorder()
{
    cout<<"\n中序遍历:"<<endl;
    midorder(root);
}

template <class KEY,class OTHER>
SET<KEY,OTHER> *AvlTree<KEY,OTHER>::searchfori(int i)
{
    return searchfori(i,root);
}

template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::sfiSon(KEY *&a,AvlNode *t)
{
    if(t==NULL)return;

    sfiSon(a,t->left);
    a[sfi]=t->data.key;
    sfi++;
    sfisize++;
    sfiSon(a,t->right);
}

template <class KEY,class OTHER>
SET<KEY,OTHER> *AvlTree<KEY,OTHER>::searchfori(int i,AvlNode *t)
{
     int size=pow(2,t->height)-1;
     KEY *tmp=new KEY[size];
     sfiSon(tmp,t);


     sfi=0;
     KEY tmp2=tmp[sfisize-i];
     sfisize=0;
     return find(tmp2);

}

template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::deletei(KEY x)
{
    deletei(x,root);
}

template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::deletei(KEY x,AvlNode *&t)
{
    if(t->left!=NULL)deletei(x,t->left);
    if(t->right!=NULL)deletei(x,t->right);
    if(t->data.key<x)remove(t->data.key,t);
}



void createavl(char * filename)
{
    ifstream fin(filename);

    int tmpid;

    if(!fin.is_open ())
      cout << "Open file failure" << endl;

       AvlTree<int,testdata> tree;
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

void findavl(char * filename)
{
    ifstream fin(filename);

    int tmpid;

    if(!fin.is_open ())
      cout << "Open file failure" << endl;

       AvlTree<int,testdata> tree;
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

void deleavl(char * filename,int treesize=50000)
{
    ifstream fin(filename);



    int cntsize=0;
    int tmpid;

    if(!fin.is_open ())
      cout << "Open file failure" << endl;

       AvlTree<int,testdata> tree;
       SET<int,testdata> a;

      vector<int> temp;

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


#endif // AVL_H_INCLUDED
