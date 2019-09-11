#include <iostream>
#include "mytree.h"
#include<ctime>
#include<windows.h>
#include"time.h"
#include <Mmsystem.h>

using namespace std;


void task1()
{
     binarytree<char> tree;
      cout<<"tree10 1"<<endl;
      tree.createTree("tree101.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

            cout<<"tree10 2"<<endl;
      tree.createTree("tree102.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree10 3"<<endl;
      tree.createTree("tree103.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree11 1"<<endl;
      tree.createTree("tree111.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree11 2"<<endl;
      tree.createTree("tree112.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree11 3"<<endl;
      tree.createTree("tree113.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree12 1"<<endl;
      tree.createTree("tree121.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree12 2"<<endl;
      tree.createTree("tree122.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree12 3"<<endl;
      tree.createTree("tree123.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree13 1"<<endl;
      tree.createTree("tree131.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree13 2"<<endl;
      tree.createTree("tree132.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree13 3"<<endl;
      tree.createTree("tree133.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree14 1"<<endl;
      tree.createTree("tree141.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree14 2"<<endl;
      tree.createTree("tree142.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree14 3"<<endl;
      tree.createTree("tree143.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree15 1"<<endl;
      tree.createTree("tree151.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree15 2"<<endl;
      tree.createTree("tree152.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree15 3"<<endl;
      tree.createTree("tree153.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree20 1"<<endl;
      tree.createTree("tree201.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree20 2"<<endl;
      tree.createTree("tree202.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

      cout<<"tree20 3"<<endl;
      tree.createTree("tree203.txt",'@');
      tree.checkComplete();
      tree.checkFull();
      tree.count2Degree();

}


void pretimecmp()
{
   binarytree<char> tree;

   tree.createTree("tree101.txt",'@');
   clock_t start,finish;
   double totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree10 1:"<<totaltime<<"ms";
   //
   //
      tree.createTree("tree102.txt",'@');

   totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree10 2:"<<totaltime<<"ms";
//
//
     tree.createTree("tree103.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree10 3:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree111.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree11 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree112.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree11 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree113.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree11 3:"<<totaltime<<"ms";
   //
   //
           tree.createTree("tree121.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree12 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree122.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree12 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree123.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree12 3:"<<totaltime<<"ms";
   //
   //
           tree.createTree("tree131.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree13 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree132.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree13 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree133.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree13 3:"<<totaltime<<"ms";
   //
   //
           tree.createTree("tree141.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree14 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree142.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree14 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree143.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree14 3:"<<totaltime<<"ms";
   //
   //
   tree.createTree("tree151.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree15 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree152.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree15 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree153.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree15 3:"<<totaltime<<"ms";
   //
   //
           tree.createTree("tree201.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree20 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree202.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree20 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree203.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.preorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre time of tree20 3:"<<totaltime<<"ms";

}

void pre_timecmp()
{
       binarytree<char> tree;

   tree.createTree("tree101.txt",'@');
   clock_t start,finish;
   double totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree10 1:"<<totaltime<<"ms";
   //
   //
      tree.createTree("tree102.txt",'@');

   totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree10 2:"<<totaltime<<"ms";
//
//
     tree.createTree("tree103.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree10 3:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree111.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree11 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree112.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree11 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree113.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree11 3:"<<totaltime<<"ms";
   //
   //
           tree.createTree("tree121.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree12 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree122.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree12 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree123.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree12 3:"<<totaltime<<"ms";
   //
   //
           tree.createTree("tree131.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree13 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree132.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree13 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree133.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree13 3:"<<totaltime<<"ms";
   //
   //
           tree.createTree("tree141.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree14 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree142.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree14 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree143.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree14 3:"<<totaltime<<"ms";

   //
   //
   tree.createTree("tree151.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree15 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree152.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree15 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree153.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree15 3:"<<totaltime<<"ms";
   //
   //
           tree.createTree("tree201.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree20 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree202.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree20 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree203.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the pre_ time of tree20 3:"<<totaltime<<"ms";
}

/*void posttimecmp()
{
    binarytree<char> tree;

   tree.createTree("tree101.txt",'@');
   clock_t start,finish;
   double totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.pre_order();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree10 1:"<<totaltime<<"ms";
   //
   //
      tree.createTree("tree102.txt",'@');

   totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree10 2:"<<totaltime<<"ms";
//
//
     tree.createTree("tree103.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree10 3:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree111.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree11 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree112.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree11 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree113.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree11 3:"<<totaltime<<"ms";
   //
   //
           tree.createTree("tree121.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree12 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree122.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree12 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree123.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree12 3:"<<totaltime<<"ms";
   //
   //
           tree.createTree("tree131.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree13 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree132.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree13 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree133.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree13 3:"<<totaltime<<"ms";
   //
   //
           tree.createTree("tree141.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree14 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree142.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree14 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree143.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree14 3:"<<totaltime<<"ms";
   //
   //
           tree.createTree("tree141.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree14 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree142.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree14 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree143.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree14 3:"<<totaltime<<"ms";
   //
   //
   tree.createTree("tree151.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree15 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree152.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree15 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree153.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree15 3:"<<totaltime<<"ms";
   //
   //
           tree.createTree("tree201.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree20 1:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree202.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree20 2:"<<totaltime<<"ms";
   //
   //
        tree.createTree("tree203.txt",'@');

totaltime=0;
   start=clock();

   for(int i=0;i<1000;i++)
   {
      tree.midorder();
   }


   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the mid time of tree20 3:"<<totaltime<<"ms";
}
*/



int main()
{
//   pretimecmp();
//   pre_timecmp();
task1();
    return 0;
}
