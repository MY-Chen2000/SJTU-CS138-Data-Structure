#include <iostream>
#include "dst.h"
#include "avl.h"


using namespace std;

void createavltime()
{

    clock_t start,finish;
   double totaltime=0;
   start=clock();


    for(int i=0;i<10;i++)
    {
        createavl("tree1.txt");

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of create avltree(txt1):"<<totaltime*100<<"ms";

   totaltime=0;
   start=clock();


    for(int i=0;i<10;i++)
    {
        createavl("tree2.txt");

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of create avltree(txt2):"<<totaltime*100<<"ms";



}

void createbintime()
{

    clock_t start,finish;
   double totaltime=0;
   start=clock();


    for(int i=0;i<10;i++)
    {
        createbin("tree1.txt");

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of create bintree(txt1):"<<totaltime*100<<"ms";

   totaltime=0;
   start=clock();


    for(int i=0;i<10;i++)
    {
        createbin("tree2.txt");

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of create bintree(txt2):"<<totaltime*100<<"ms";



}


void findavltime()
{

    clock_t start,finish;
   double totaltime=0;
   start=clock();


    for(int i=0;i<20;i++)
    {
        findavl("tree1.txt");

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of find avltree(txt1):"<<totaltime*50<<"ms";

   totaltime=0;
   start=clock();


    for(int i=0;i<20;i++)
    {
        findavl("tree2.txt");

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of find avltree(txt2):"<<totaltime*50<<"ms";



}

void findbintime()
{

    clock_t start,finish;
   double totaltime=0;
   start=clock();


    for(int i=0;i<20;i++)
    {
        findbin("tree1.txt");

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of find bintree(txt1):"<<totaltime*50<<"ms";

   totaltime=0;
   start=clock();


    for(int i=0;i<20;i++)
    {
        findbin("tree2.txt");

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of find bintree(txt2):"<<totaltime*50<<"ms";



}

void delebintime()
{

    clock_t start,finish;
   double totaltime=0;
   start=clock();


    for(int i=0;i<20;i++)
    {
        delebin("tree1.txt",10000);

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of delete bintree(txt1,10000):"<<totaltime*50<<"ms";
//***************
   totaltime=0;
   start=clock();


    for(int i=0;i<20;i++)
    {
        delebin("tree1.txt",20000);

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of delete bintree(txt1,20000):"<<totaltime*50<<"ms";

   //***************
   totaltime=0;
   start=clock();


    for(int i=0;i<20;i++)
    {
        delebin("tree1.txt",30000);

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of delete bintree(txt1,30000):"<<totaltime*50<<"ms";

   //***************
   totaltime=0;
   start=clock();


    for(int i=0;i<20;i++)
    {
        delebin("tree1.txt",40000);

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of delete bintree(txt1,40000):"<<totaltime*50<<"ms";

   //***************
   totaltime=0;
   start=clock();


    for(int i=0;i<20;i++)
    {
        delebin("tree1.txt",50000);

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of delete bintree(txt1,50000):"<<totaltime*50<<"ms";



}

void deleavltime()
{

    clock_t start,finish;
   double totaltime=0;
   start=clock();


    for(int i=0;i<10;i++)
    {
        deleavl("tree1.txt",10000);

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of delete avltree(txt1,10000):"<<totaltime/10<<"s";
//   //&&&&&&&&&&
//
//   totaltime=0;
//   start=clock();
//
//
//    for(int i=0;i<20;i++)
//    {
//        deleavl("tree2.txt",10000);
//
//    }
//
//    finish=clock();
//   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
//   cout<<endl<<"the time of delete avltree(txt2,10000):"<<totaltime*50<<"ms";
//
//      totaltime=0;
//   start=clock();

//*&&&&&&&&&&&&
   totaltime=0;
   start=clock();
    for(int i=0;i<10;i++)
    {
        deleavl("tree1.txt",20000);

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of delete avltree(txt1,20000):"<<totaltime/10<<"s";

   //*&&&&&&&&&&&&
   totaltime=0;
   start=clock();
    for(int i=0;i<10;i++)
    {
        deleavl("tree1.txt",30000);

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of delete avltree(txt1,30000):"<<totaltime/10<<"s";

   //*&&&&&&&&&&&&
   totaltime=0;
   start=clock();
    for(int i=0;i<10;i++)
    {
        deleavl("tree1.txt",40000);

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of delete avltree(txt1,40000):"<<totaltime/10<<"s";

   //*&&&&&&&&&&&&
   totaltime=0;
   start=clock();
    for(int i=0;i<10;i++)
    {
        deleavl("tree1.txt");

    }

    finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<endl<<"the time of delete avltree(txt1,50000):"<<totaltime/10<<"s";




}

int main()

{
createbintime();
    createavltime();

//
//    findavltime();
//    findbintime();

//*************************************
//上下分开跑
//**************************************
//   deleavltime();
//   delebintime();



    return 0;
}
