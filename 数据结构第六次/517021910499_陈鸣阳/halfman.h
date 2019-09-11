#ifndef HALFMAN_H_INCLUDED
#define HALFMAN_H_INCLUDED


#include"string.h"
#include<fstream>
#include<iostream>
#include<istream>
#include"linear_list.h"


using namespace std;



template<class T>
class hftree
{
    friend void decode(char *filename);
    friend void encode(char *filename);

private:
    struct node
    {
        T data;
        int weight;
        int parent,left,right;

    };

    node *elem;
    int length;

public:
//*****
      int s[123]={0};
//********
    slinklist<char> hafnode;

    struct hfcode
    {
        T data;
        string code;
    };

    hftree(const T*x,const int *w,int size);
    hftree(char *filename);
    void getcode(hfcode result[]);
    ~hftree(){delete[]elem;}
    void calculateWeight(char *filename);
    void getcode();
};

template <class T>
hftree<T>::hftree(char *filename)
{
    calculateWeight(filename);


   //cout<<hafnode.length();

    for(int i=0;i<123;i++)
    {
        if(s[i]!=0&&i!=10)
        {
         hafnode.insert(0,(char)i);
//         hafnode.traverse();
         //cout<<hafnode.length();
        }
    }

    char *zimu=new char[hafnode.length()+1];

    for(int i=0;i<hafnode.length();++i)
    {
        zimu[i]=hafnode.visit(i);
        //cout<<zimu[i]<<"  ";
    }
    //zimu[hafnode.length()]='\0';
    //cout<<endl<<zimu<<endl;
    int *quanzhi=new int[hafnode.length()];
    for(int i=0;i<hafnode.length();++i)
    {
        quanzhi[i]=s[(int)hafnode.visit(i)];
        //cout<<quanzhi[i]<<"  ";
    }
//    for(int i=0;i<hafnode.length();++i)
//    {
//        cout<<quanzhi[i];
//    }

   const int max_int=32767;
    int min1,min2;  //最小树、次最小树的权值
    int x,y;        //最小树、次最小树的下标
    int i;

    //置初值
    length=2*hafnode.length();
    elem = new node[length];

    for(i=hafnode.length();i<length;++i)
    {
        elem[i].weight=quanzhi[i-hafnode.length()];
        elem[i].data=zimu[i-hafnode.length()];
        elem[i].parent=elem[i].left=elem[i].right=0;
    }

    //归并森林中的树
    for(i=hafnode.length()-1;i>0;--i)
    {
        min1=min2=max_int;
        x=y=0;
        for(int j=i+1;j<length;++j)
            if(elem[j].parent==0)
                if(elem[j].weight<min1)
            {
                min2=min1;
                min1=elem[j].weight;
                x=y;
                y=j;
            }
            else if(elem[j].weight<min2)
            {
                min2=elem[j].weight;
                x=j;
            }
        elem[i].weight=min1+min2;
        elem[i].left=x;
        elem[i].right=y;
        elem[i].parent=0;
        elem[x].parent=i;
        elem[y].parent=i;
    }


}


template <class T>
hftree<T>::hftree(const T *v,const int *w,int size)
{
    const int max_int=32767;
    int min1,min2;  //最小树、次最小树的权值
    int x,y;        //最小树、次最小树的下标
    int i;

    //置初值
    length=2*size;
    elem = new node[length];

    for(i=size;i<length;++i)
    {
        elem[i].weight=w[i-size];
        elem[i].data=v[i-size];
        elem[i].parent=elem[i].left=elem[i].right=0;
    }

    //归并森林中的树
    for(i=size-1;i>0;--i)
    {
        min1=min2=max_int;
        x=y=0;
        for(int j=i+1;j<length;++j)
            if(elem[j].parent==0)
                if(elem[j].weight<min1)
            {
                min2=min1;
                min1=elem[j].weight;
                x=y;
                y=j;
            }
            else if(elem[j].weight<min2)
            {
                min2=elem[j].weight;
                x=j;
            }
        elem[i].weight=min1+min2;
        elem[i].left=x;
        elem[i].right=y;
        elem[i].parent=0;
        elem[x].parent=i;
        elem[y].parent=i;
    }


}

template <class T>
void hftree<T>::getcode(hfcode result[])
{
    int size=length/2;
    int p,s;

    for(int i=size;i<length;++i)
    {
        result[i-size].data=elem[i].data;
        result[i-size].code="";
        p=elem[i].parent;s=i;
        while(p)
        {
            if(elem[p].left==s)
                result[i-size].code='0'+result[i-size].code;
            else result[i-size].code='1'+result[i-size].code;
            s=p;
            p=elem[p].parent;
        }
    }
}


template <class T>
void hftree<T>::calculateWeight(char *filename)
{
    ifstream fin;
    fin.open(filename);
    if(!fin.is_open ())
      cout << "Open file failure" << endl;



    char tmp;
    int t;

    fin>>noskipws;
    while(!fin.eof())
    {
        fin>>tmp;
        t=(int)tmp;

        ++s[t];
    }

//    for(int i=0;i<123;i++)
//    {
//        tmp=(char)i;
//        cout<<tmp<<":"<<s[i]<<endl;
//    }

   // fin.close();


}

template <class T>
void hftree<T>::getcode()
{
    int huffman=0;
    hftree<char>::hfcode result[hafnode.length()];
     getcode(result);
        for(int i=0;i<hafnode.length();++i)
    {
        cout<<result[i].data<<' '<<result[i].code<<endl;
        //cout<<"#bianma:"<<result[i].code<<"$machang:"<<result[i].code.length()<<"#quanzhi:"<<elem[hafnode.length()+i].weight<<endl;
        huffman=huffman+result[i].code.length()*elem[hafnode.length()+i].weight;
        //cout<<huffman<<endl;
    }
    //cout<<"final"<<huffman;

}


void encode(char *filename)
{
    hftree<char>tree(filename);
    hftree<char>::hfcode result[tree.hafnode.length()];
    tree.getcode(result);




   // 生成文件名
    char *of="hufm.txt";
    char *in="copy.txt";
    string str1(filename);
    string str11=str1.substr(0,5);
    string str2(of);
    string str4(in);


    string str3,str5;
    str3=str11+str2;
    str5=str11+str4;
    const char *combout=str3.data();
    const char *combin=str5.data();
    //

    ofstream out(combout);

    char temp;

     ifstream fin2;
    fin2.open(combin);


    if(!fin2.is_open ())
      cout << "Open file failure" << endl;
    while(fin2.peek() != EOF)
    {
      int pos=0;
      temp=fin2.get();
      cout<<temp;
      while(result[pos].data!=temp)
      {
        pos++;
      }

      out<<result[pos].code;
    }



}


void decode(char *filename)
{

    string str1(filename);
    string str11=str1.substr(0,5);
//
//
    hftree<char>tree(filename);
    hftree<char>::hfcode result[tree.hafnode.length()];
    tree.getcode(result);
//
//    // 生成文件名
    char *of="decode.txt";
    char *in="hufm.txt";
//
//
    string str2(of);
    string str4(in);
//
//
    string str3,str5;
    str3=str11+str2;
    str5=str11+str4;
    const char *combout=str3.data();
    const char *combin=str5.data();
//    //
//
    ofstream out(combout);
//
    ifstream fin3;
    fin3.open(combin);
    if(!fin3.is_open ())
      cout << "Open file failure" << endl;
//
      char temp;
      string tofind="";
//
      bool flag=false;
//
//
    while(!fin3.eof())
    {
        int pos=0;
       temp=fin3.get();
       //cout<<temp<<endl;



       string tmp2(tofind);

       tofind=tmp2+temp;
       //cout<<tofind<<endl;


//       cout<<"***"<<tree.hafnode.length()<<"***";
       while(result[pos].code.compare(tofind)!=0&&pos<tree.hafnode.length()-1)
      {
        pos++;
//        cout<<result[pos].code<<endl;
//        cout<<result[pos].code.compare(tofind)<<endl;

      }
      if (result[pos].code.compare(tofind)==0)flag=true;
      if(flag)
      {
          if(pos==34)
          {
              out<<" ";
          }
          else out<<result[pos].data;
          //cout<<result[pos].data<<"&&"<<result[pos].code<<endl;
          //cout<<tofind<<endl;
          tofind="";
          flag=false;
          cout<<pos<<result[pos].data<<endl;
      }
    }
//
//
//
//    fin3.close();
//    out.close();

}













#endif // HALFMAN_H_INCLUDED
