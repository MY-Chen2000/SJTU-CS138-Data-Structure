#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

using namespace std;
#include <iostream>
#include<cmath>
#include<ctime>
#include "stdlib.h"
#include<string>

class seqstring
{
    friend seqstring operator+(const seqstring &s1,const seqstring &s2);
    friend bool operator==(const seqstring &s1,const seqstring &s2);
    friend bool operator!=(const seqstring &s1,const seqstring &s2);
    friend bool operator>(const seqstring &s1,const seqstring &s2);
    friend bool operator>=(const seqstring &s1,const seqstring &s2);
    friend bool operator<(const seqstring &s1,const seqstring &s2);
    friend bool operator<=(const seqstring &s1,const seqstring &s2);
    friend ostream &operator<<(ostream &os,const seqstring &s2);

    char *data;
    int len;

public:
    seqstring(const char *s="");
    seqstring(const seqstring &other);
    ~seqstring();
    int length()const;
    seqstring &operator=(const seqstring &other);
    seqstring substr(int start,int num)const;
    void insert(int start, const seqstring &s);
    void remove(int start , int num);
    void frequency();
    int find(const seqstring &sub)const;
    void replace(const string &s1, const string &s2);

};

seqstring::seqstring(const char *s)
{
    for(len=0;s[len]!='\0';++len);
    data=new char[len+1];
    for(len=0;s[len]!='\0';++len)
    {
        data[len]=s[len];
    }
    data[len]='\0';
}

seqstring::seqstring(const seqstring &other)
{
    data=new char[other.len+1];
    for(len=0;len<=other.len;++len)
    {
        data[len]==other.data[len];
    }
}

seqstring::~seqstring()
{
    delete data;
}

int seqstring::length()const
{
    return len;
}

seqstring &seqstring::operator=(const seqstring &other)
{
    if(this==&other)return *this;
    delete data;
    data=new char[other.len+1];
    for(len=0;len<=other.len;++len)
    {
        data[len]=other.data[len];
    }
   len--;
    return *this;
}

seqstring seqstring::substr(int start,int num)const
{
    if(start>len-1||start<0) return " ";
    seqstring tmp;
    tmp.len=(start+num>len)?len-start:num;
    delete tmp.data;
    tmp.data=new char[tmp.len+1];
    int i;
    for(i=0;i<tmp.len;++i)
    {
        tmp.data[i]=data[start+i];
    }
    tmp.data[i]='\0';

    return tmp;
}

void seqstring::insert(int start , const seqstring &s)
{
    char *tmp=data;
    int i;

    if(start>len||start<0)return;
    len+=s.len;
    data=new char[len+1];
    for(i=0;i<start;++i)
    {
        data[i]=tmp[i];
    }
    for(i=0;i<s.len;++i)
    {
        data[start+i]=s.data[i];
    }
    for(i=start;tmp[i]!='\0';++i)
    {
        data[i+s.len]=tmp[i];
    }
    data[i+s.len]='\0';
    delete tmp;

}

void seqstring::remove(int start,int num)
{
    if(start>len-1||start<0)return;
    if(start+num>=len)
    {
        data[start]='\0';
        len=start;
    }
    else
    {
        for(len=start;data[len+num]!='\0';++len)
            data[len]=data[len+num];
        data[len]='\0';
    }
}

seqstring operator+(const seqstring &s1,const seqstring &s2)
{
    seqstring tmp;
    int i;

    tmp.len=s1.len+s2.len;
    delete tmp.data;
    tmp.data= new char[tmp.len+1];
    for(int i=0;i<s1.len;++i)
    {
        tmp.data[i]=s1.data[i];
    }
    for(i=0;i<s2.len;++i)
    {
        tmp.data[s1.len+i]=s2.data[i];
    }
    tmp.data[s1.len+s2.len]='\0';
    return tmp;

}

bool operator==(const seqstring &s1,const seqstring &s2)
{
    if(s1.len!=s2.len)return false;
    for(int i=0;i<s1.len;++i)
    {
        if(s1.data[i]!=s2.data[i])return false;
    }
    return true;
}

bool operator!=(const seqstring &s1,const seqstring &s2)
{

    return !(s1==s2);
}

bool operator>(const seqstring &s1,const seqstring &s2)
{
    for(int i=0;i<s1.len;++i)
        if(s1.data[i]>s2.data[i])
    return true;
    else if(s1.data[i]<s2.data[i])
        return false;
    return false;
}

bool operator>=(const seqstring &s1,const seqstring &s2)
{
    return (s1==s2||s1>s2);
}

bool operator<(const seqstring &s1,const seqstring &s2)
{
    return !(s1>=s2);
}

bool operator<=(const seqstring &s1,const seqstring &s2)
{
    return !(s1>s2);
}

ostream &operator<<(ostream &os,const seqstring &s)
{
    os<<s.data;
    return os;
}

void seqstring::frequency()
{
     int count[127] = {0};

     int i;
     while(data[i]!='\0')
     {

             int tmp1;
             tmp1=int(data[i]);
             ++count[tmp1];
             ++i;

     }

     for(int j=32;j<127;++j)
     {
         char tmp2=j;
         cout<<tmp2<<":"<<count[j]<<"time"<<endl;
     }

}

//Á¬½ÓÊµÏÖ********************
//**************************
class linkstring
{
    friend linkstring operator+(const linkstring &s1,const linkstring &s2);
    friend bool operator==(const linkstring &s1,const linkstring &s2);
    friend bool operator!=(const linkstring &s1,const linkstring &s2);
    friend bool operator>(const linkstring &s1,const linkstring &s2);
    friend bool operator>=(const linkstring &s1,const linkstring &s2);
    friend bool operator<(const linkstring &s1,const linkstring &s2);
    friend bool operator<=(const linkstring &s1,const linkstring &s2);
    friend ostream &operator<<(ostream &os,const linkstring &s2);

    struct node
    {
        int size;
        char *data;
        node *next;

        node(int s=1,node *n=NULL){data=new char[s];size=0;next=n;}
    };

    node *head;
    int len;
    int nodesize;

    void clear();
    void findpos(int start,int &pos,node *&p)const;
    void split(node *p,int pos);
    void merge(node *p);
public:
    linkstring(const char*s="");
    linkstring(const linkstring &other);
    ~linkstring();
    int length()const;
    linkstring &operator=(const linkstring &other);
    linkstring substr(int start , int num)const;
    void insert(int start ,const linkstring &s);
    void remove(int start,int num);
    void reconstruct(int nodeSize);
    void frequency();
    int find(const linkstring &sub)const;
    void replace(const string &s1, const string &s2);

};

linkstring::linkstring(const char *s)
{
    node *p;
    for(len=0;s[len]!='\0';++len);
    nodesize=sqrt(len);
    p=head=new node(1);
    while(*s)
    {
        p=p->next=new node(nodesize);
        for(;p->size<nodesize&&*s;++p->size,++s)
            p->data[p->size]=*s;
    }
}

linkstring::linkstring(const linkstring &other)
{
    node *p,*otherp=other.head->next;

    p=head=new node(1);
    len=other.len;
    nodesize=other.nodesize;
    while(otherp)
    {
        p=p->next=new node(nodesize);
        for(;p->size<otherp->size;++p->size)
            p->data[p->size]=otherp->data[p->size];
        otherp=otherp->next;
    }
}

void linkstring::clear()
{
    node *p=head->next,*nextp;

    while(p)
    {
        nextp=p->next;
        delete p;
        p=nextp;
    }
}

linkstring::~linkstring()
{
    clear();
    delete head;
}

int linkstring::length()const
{
    return len;
}

linkstring &linkstring::operator=(const linkstring&other)
{
    node *p=head,*otherp=other.head->next;

    if(this==&other)return *this;
    clear();
    len=other.len;
    nodesize=other.nodesize;
    while(otherp)
    {
        p=p->next=new node(nodesize);
        for(;p->size<otherp->size;++p->size)
        {
            p->data[p->size]=otherp->data[p->size];
        }
        otherp=otherp->next;
    }

    return *this;
}

void linkstring::findpos(int start,int &pos,node *&p)const
{



        int count=0;
    p=head->next;

    while(count<=start)
    {
        if((count+p->size)<start)
        {
            count+=p->size;
            p=p->next;
        }
        else
        {
            pos=start-count;
            return;
        }
    }


}

linkstring linkstring::substr(int start,int num)const
{
    linkstring tmp;
    int count=0,pos;
    node *p,*tp=tmp.head;

    if(start<0||start>len-1)return tmp;

    num=(start+num>len)?len-start:num;
    tmp.len=num;
    tmp.nodesize=sqrt(num);

    findpos(start,pos,p);

    for(int i=0;i<tmp.len;)
    {
        tp=tp->next=new node(tmp.nodesize);
        for(;tp->size<tmp.nodesize&&i<tmp.len;++tp->size,++i)
        {
            if(pos==p->size)
            {
                p=p->next;
                pos=0;
            }
            tp->data[tp->size]=p->data[pos++];
        }
    }

    return tmp;
}

void linkstring::split(node *p,int pos)
{
    int i;
    p->next=new node(nodesize,p->next);
    for(i=pos;i<p->size;++i)
    {
        p->next->data[i-pos]=p->data[i];
    }
    p->next->size=i-pos;
    p->size=pos;
}

void linkstring::merge(node *p)
{
    node *nextp=p->next;
    if(p->size+nextp->size<=nodesize)
    {
        for(int pos=0;pos<nextp->size;++pos,++p->size)
        {
            p->data[p->size]=nextp->data[pos];
        }
        p->next=nextp->next;
        delete nextp;
    }
}

void linkstring::insert(int start,const linkstring &s)
{

    if((start==0)&&(head->next==NULL))
    {
        *this=s;
        return ;
    }
    node *p,*nextp,*tmp;
    int pos;
    if(start<0||start>len)return;
    findpos(start,pos,p);
    //cout<<"pos"<<pos<<endl;
    //cout<<p->data[0]<<endl;
    split(p,pos);
   // cout<<*this<<endl;
    nextp=p->next;
    tmp=s.head->next;
    while(tmp)
    {
        for(pos=0;pos<tmp->size;++pos)
        {
            if(p->size==nodesize)p=p->next=new node(nodesize);
          p->data[p->size]=tmp->data[pos];

            ++p->size;
        }
        tmp=tmp->next;
    }
    len+=s.len;
    p->next=nextp;
    merge(p);

}

void linkstring::remove(int start, int num)
{
        if(start<0||start>len-1)return;

        node *startp;
        int pos;

        findpos(start,pos,startp);
        split(startp,pos);
        if(start+num>=len)
        {
            num=len-start;
            len=start;
        }
        else len-=num;

        while(true)
        {
            node*nextp=startp->next;
            if(num>nextp->size)
            {
                num-=nextp->size;
                startp->next=nextp->next;
                delete nextp;
            }
            else
            {
                split(nextp,num);
                startp->next=nextp->next;
                delete nextp;
                break;
            }
        }
        merge(startp);
}

linkstring operator+(const linkstring &s1,const linkstring &s2)
{
    char *tmp=new char[s1.len+s2.len+1];
    linkstring::node *p;
    int count =0, i;

    for(p=s1.head->next;p!=NULL;p=p->next)
    {
        for(i=0;i<p->size;++i)
            tmp[count++]=p->data[i];
    }
    for(p=s2.head->next;p!=NULL;p=p->next)
    {
        for(i=0;i<p->size;++i)
            tmp[count++]=p->data[i];
    }
    tmp[count]='\0';
    linkstring returnvalue(tmp);
    delete tmp;
    return returnvalue;

//      linkstring s3;
//      s3=s1;
//
//      int m=s3.len;
//
//      s3.insert(m,s2);
//
//      return s3;
}

bool operator==(const linkstring &s1,const linkstring &s2)
{
    linkstring::node *p1=s1.head->next,*p2=s2.head->next;
    int pos1=0,pos2=0;

    if(s1.len!=s2.len)return false;
    while(p1&&p2)
    {
        if(p1->data[pos1]!=p2->data[pos2])return false;
        if(++pos1==p1->size)
        {
            p1=p1->next;
            pos1=0;
        }
        if(++pos2==p2->size)
        {
            p2=p2->next;
            pos2=0;
        }
    }
    return true;
}

bool operator!=(const linkstring &s1,const linkstring &s2)
{
    return !(s1==s2);
}

bool operator>(const linkstring &s1,const linkstring &s2)
{
    linkstring::node *p1=s1.head->next,*p2=s2.head->next;
    int pos1=0,pos2=0;

    while(p1)
    {
        if(p2==NULL)return true;
        if(p1->data[pos1]>p2->data[pos2])return true;
        if(p1->data[pos1]<p2->data[pos2])return false;
        if(++pos2==p2->size)
        {
            p2=p2->next;
            pos2=0;
        }
        if(++pos1==p1->size)
        {
            p1=p1->next;
            pos1=0;
        }
    }
    return false;
}

bool operator>=(const linkstring &s1,const linkstring &s2)
{
    return (s1==s2||s1>s2);
}

bool operator<(const linkstring &s1,const linkstring &s2)
{
    return!(s1>=s2);
}

bool operator<=(const linkstring &s1,const linkstring &s2)
{
    return !(s1>s2);
}

ostream &operator<<(ostream &os, const linkstring &s)
{
    linkstring::node *p=s.head->next;
    int pos =0;

    while(p)
    {
        for(pos=0;pos<p->size;++pos)
            os<<p->data[pos];
            os<<"->";
        p=p->next;
    }
    return os;
}

void linkstring::reconstruct(int nodsize=0)//不传递参数时nodesize为sqrt(len) 传递参数时为所传递的参数值
{
   if(nodsize==0)nodsize=sqrt(len);

   linkstring tmp=*this;
   node *p,*tmpp=tmp.head->next;

   p=head=new node(1);
   len=tmp.len;
   nodesize=nodsize;




    int m=0,k=0;
    int count=tmp.length();
   while(tmpp)
    {
        k=0;


        p->next=new node(nodesize);
        p=p->next;

        for(;k<nodesize&&count>0;++k)
        {

            p->data[k]=tmpp->data[m];

            if(m==tmpp->size-1)
            {
                tmpp=tmpp->next;
                m=-1;
            }
            ++m;
              ++p->size;

             --count;
        }

    }




}

void linkstring::frequency()
{
     int count[127] = {0};
     node *p;
     p=head->next;
     while(p!=NULL)
     {
         for(int i=0;i<p->size;++i)
         {
             int tmp1;
             tmp1=int(p->data[i]);
             ++count[tmp1];
         }
         p=p->next;
     }

     for(int i=32;i<127;++i)
     {
         char tmp2=i;
         cout<<tmp2<<":"<<count[i]<<"time"<<endl;
     }

}

int prorandom(int j)//产生从0到j-1的随机数
{

    return rand()*j/(RAND_MAX+1);

}

//生成20个任意字符
seqstring pro20()
{
    srand(time(NULL)+rand());
    char *tmp=new char[21];

    for(int i=0;i<20;++i)
    {

        char s=prorandom(95)+32;
        tmp[i]=s;

    }
    tmp[20]='\0';
    seqstring a(tmp);
    return a;

}

linkstring linkpro20(int n=20)
{
    srand(time(NULL)+rand());
    char *tmp=new char[n+1];

    for(int i=0;i<n;++i)
    {

        char s=prorandom(26)+65;
        tmp[i]=s;

    }
    tmp[n]='\0';
    linkstring a(tmp);
    return a;

}

int seqstring::find(const seqstring &sub)const
{
    int *p=new int[sub.len];
    int i,j;

    //生成失效函数
    p[0]=-1;
    for(i=1;i<sub.len;++i)
    {
        j=i-1;
        while(j>=0&&sub.data[p[j]+1]!=sub.data[i]) j=p[j];
        if(j<0) p[i]=-1;
        else p[i]=p[j]+1;
    }


    //查找
    i=j=0;
    while(i<len&&j<sub.len)
    {
        if(sub.data[j]==data[i]){++i;++j;}
        else if(j==0)++i;
          else j=p[j-1]+1;
    }
    delete []p;
    if(j==sub.len)
        return i-j;
    else return -1;
}

void seqstring::replace(const string &s1, const string &s2)
{
    const char *a1=s1.c_str(),*a2=s2.c_str();

    seqstring seq1(a1),seq2(a2);
    while(this->find(seq1)!=-1)
    {
        int tmp=this->find(seq1);
        this->remove(tmp,seq1.length());
        this->insert(tmp,seq2);
    }
}

int linkstring::find(const linkstring &sub)const
{

    linkstring::node *p2=sub.head->next;
    int *p=new int[sub.len];
    int i,j;

    //生成失效函数
    p[0]=-1;
    for(i=1;i<sub.len;++i)
    {
        j=i-1;
        while(j>=0&&sub.substr(p[j]+1,1)!=sub.substr(i,1)) j=p[j];
        if(j<0) p[i]=-1;
        else p[i]=p[j]+1;
    }


    //查找
    i=j=0;
    while(i<len&&j<sub.len)
    {
        if(sub.substr(j,1)==substr(i,1)){++i;++j;}
        else if(j==0)++i;
          else j=p[j-1]+1;
    }
    delete []p;
    if(j==sub.len)
        return i-j;
    else return -1;


}

void linkstring::replace(const string &s1, const string &s2)
{

    const char *a1=s1.c_str(),*a2=s2.c_str();

    linkstring link1(a1),link2(a2);
    while(this->find(link1)!=-1)
    {
        int tmp=this->find(link1);
        this->remove(tmp,link1.length());
        this->insert(tmp,link2);
    }
}


seqstring seqcreate(int n=50000)
{
    seqstring a;
    for(int i=0;i<n;++i)
    {
        a.insert(prorandom(a.length()),pro20());

    }

    return a;
}



void seqinsert1000(seqstring tmp)
{
//    seqstring tmp;
//    tmp=seqcreate();
     int count=0;
    clock_t start,finish;
   double totaltime=0;
   start=clock();
    while(totaltime<20)
  {
        for(int i=0;i<1000;++i)
    {
        tmp.insert(prorandom(tmp.length()),pro20());
    }         //把你的程序代码插入到这里面

   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   count++;

  }

   cout<<"\nseqstring insert 1000 times average time"<<(totaltime/count)<<"second"<<endl;

}

void linkinsert1000(linkstring tmp)
{
//    linkstring tmp;
//    tmp=linkcreate();
     int count=0;
    clock_t start,finish;
   double totaltime=0;
   start=clock();
    while(totaltime<0.6)
  {
        for(int i=0;i<1000;++i)
    {
        tmp.insert(prorandom(tmp.length()-1)+1,linkpro20(2));

    }         //把你的程序代码插入到这里面

   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   count++;

  }

   cout<<"\nlinkstring insert 1000 times  time"<<(totaltime/count)<<"second"<<endl;

}

void seqremove1000(seqstring tmp)
{
//    seqstring tmp;
//    tmp=seqcreate();
    int count=0;
    clock_t start,finish;
   double totaltime=0;
   start=clock();
    while(totaltime<1)
  {

     for(int i=0;i<1000;++i)
    {
        tmp.remove(prorandom(100000),prorandom(900));
    }                 //把你的程序代码插入到这里面
   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   count++;

  }
   cout<<"\nseqstring remove 1000 times average time"<<totaltime/count<<"second"<<endl;

}

void linkremove1000(linkstring tmp)
{
//    linkstring tmp;
//    tmp=linkcreate();
    int count=0;
    clock_t start,finish;
   double totaltime=0;
   start=clock();
//    while(totaltime<5)
//  {

     for(int i=0;i<1000;++i)
    {
        tmp.remove(prorandom(100000),prorandom(900));
    }                 //把你的程序代码插入到这里面
   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   count++;
//
//  }
   cout<<"\nlinkstring remove 1000 times  time"<<(totaltime/count)*1000<<"ms"<<endl;

}


void seqfind1000(seqstring tmp)
{
//    seqstring tmp;
//    tmp=seqcreate();
    int count=0;
    clock_t start,finish;
   double totaltime=0;
   start=clock();
    while(totaltime<20)
  {

     for(int i=0;i<1000;++i)
    {
        const seqstring s=seqcreate(1);

        tmp.find(s);
    }                 //把你的程序代码插入到这里面
   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   count++;

  }
   cout<<"\nseqstring find 1000 times average time"<<totaltime/count<<"second"<<endl;

}





#endif // MYSTRING_H_INCLUDED
