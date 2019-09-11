#include <iostream>
#include "mystring.h"
#include "stdlib.h"
#include<ctime>
#include<windows.h>
#include"time.h"
#include <Mmsystem.h>
#pragma comment(lib, "Winmm.lib")

using namespace std;

//注： 查找1000次用循环50000次生成的长字符串有内存问题 因此采用了较短的字符串做测试

linkstring linkcreate(int n=50000)
{
    linkstring a="abcdefghijklmnopqrst";
    for(int i=1;i<n;++i)
    {
        a.insert(0/*prorandom(a.length())*/,linkpro20());


    }

    return a;
}

void linkfind1000(linkstring tmp)
{
//    linkstring tmp;
//    tmp=linkcreate(500);
    int count=0;
    clock_t start,finish;
   double totaltime=0;
   start=clock();
//    while(totaltime<8)
//  {

     for(int i=0;i<1000;++i)
    {
        const linkstring s=linkcreate(1);

        tmp.find(s);

    }                 //把你的程序代码插入到这里面
   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   count++;

//  }
   cout<<"\nlinkstring find 1000 times  time"<<totaltime/count<<"second"<<endl;

}

void provesqrt()
{
    linkstring t,tmp;
    t=linkcreate();

    tmp=t;
    for(int i=100;i<sqrt(tmp.length());i=i+400)
    {
        tmp=t;
        tmp.reconstruct(i);
        cout<<i<<":";
        //linkinsert1000(tmp);
        linkremove1000(tmp);

    }

        tmp=t;
        tmp.reconstruct();
        cout<<"sqrt(len):"<<sqrt(tmp.length())<<":";
        //linkinsert1000(tmp);
        linkremove1000(tmp);

        tmp=t;
        tmp.reconstruct(5000);
        cout<<5000<<":";
        //linkinsert1000(tmp);
       linkremove1000(tmp);

        tmp=t;
        tmp.reconstruct(10000);
        cout<<10000<<":";
        //linkinsert1000(tmp);
        linkremove1000(tmp);

        tmp=t;
        tmp.reconstruct(50000);
        cout<<50000<<":";
        //linkinsert1000(tmp);
        linkremove1000(tmp);

        tmp=t;
        tmp.reconstruct(100000);
        cout<<100000<<":";
        //linkinsert1000(tmp);
        linkremove1000(tmp);

//        linkstring tmp2,t;
//    t=linkcreate(125);
//    tmp2=t;
//        for(int i=10;i<sqrt(tmp2.length());i=i+20)
//    {
//        tmp2=t;
//        tmp2.reconstruct(i);
//        cout<<i<<":";
//        linkfind1000(tmp2);
//
//
//    }
//
//        tmp2=t;
//        tmp2.reconstruct();
//        cout<<"sqrt(len)"<<sqrt(tmp2.length())<<":";
//        linkfind1000(tmp2);
//
//        for(int i=100;i<tmp2.length();i=i+500)
//    {
//        tmp2=t;
//        tmp2.reconstruct(i);
//        cout<<i<<":";
//        linkfind1000(tmp2);
//
//    }



}




int main()
{
//    seqstring a="s";
//    seqstring b;
//
//    cout<<a;
//    cout<<endl<<b;
//provesqrt();



seqstring tmp,t;
tmp=seqcreate();
t=tmp;
//
//  seqinsert1000(t);
  t=tmp;
  seqremove1000(t);
//  t=tmp;
//  seqfind1000(t);
// linkinsert1000();
// linkremove1000();





cout<<"end";
    return 0;
}





//    linkstring tmp2,t;
//    t=linkcreate(50000);
//    tmp2=t;
//        for(int i=100;i<sqrt(tmp2.length());i=i+400)
//    {
//        tmp2=t;
//        tmp2.reconstruct(i);
//        cout<<i<<":";
//        linkfind1000(tmp2);
//
//
//    }
//
//        tmp2=t;
//        tmp2.reconstruct();
//        cout<<"sqrt(len)"<<sqrt(tmp2.length())<<":";
//        linkfind1000(tmp2);
//
//        tmp2=t;
//        tmp2.reconstruct(5000);
//        cout<<5000<<":";
//        //linkinsert1000(tmp);
//       linkfind1000(tmp2);
//
//        tmp2=t;
//        tmp2.reconstruct(10000);
//        cout<<10000<<":";
//        //linkinsert1000(tmp);
//        linkfind1000(tmp2);
//
//        tmp2=t;
//        tmp2.reconstruct(50000);
//        cout<<50000<<":";
//        //linkinsert1000(tmp);
//        linkfind1000(tmp2);
//
//        tmp2=t;
//        tmp2.reconstruct(100000);
//        cout<<100000<<":";
//        //linkinsert1000(tmp);
//        linkfind1000(tmp2);









