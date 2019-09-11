
#include "sort.h"
#include "matrixgraph.h"
#include "listgraph.h"
#include <iostream>
#include <fstream>
#include<ctime>


#include "test.h"

using namespace std;

void testshell()
{
        clock_t start,finish;
    double totaltime=0;
    start=clock();

    for(int i=0;i<20;i++)
    {
       ifstream fin;
       fin.open("sort1.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[10000];

      for(int i=0;i<10000;++i)
      {
          fin>>a[i];
      }

        shellsort(a,10000);
    }

    //*********************8
    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of shell(10000)"<<totaltime*50<<"ms";

        start=clock();

    for(int i=0;i<20;i++)
    {
       ifstream fin;
       fin.open("sort2.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[50000];

      for(int i=0;i<50000;++i)
      {
          fin>>a[i];
      }

        shellsort(a,50000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of shell(50000)"<<totaltime*50<<"ms";

            start=clock();

    for(int i=0;i<20;i++)
    {
       ifstream fin;
       fin.open("sort3.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[100000];

      for(int i=0;i<100000;++i)
      {
          fin>>a[i];
      }

        shellsort(a,100000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of shell(100000)"<<totaltime*50<<"ms";


                start=clock();

    for(int i=0;i<20;i++)
    {
       ifstream fin;
       fin.open("sort4.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[200000];

      for(int i=0;i<200000;++i)
      {
          fin>>a[i];
      }

        shellsort(a,200000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of shell(200000)"<<totaltime*50<<"ms";


                    start=clock();

    for(int i=0;i<20;i++)
    {
       ifstream fin;
       fin.open("sort5.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[500000];

      for(int i=0;i<500000;++i)
      {
          fin>>a[i];
      }

        shellsort(a,500000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of shell(500000)"<<totaltime*50<<"ms";
}

void testheap()
{
        clock_t start,finish;
    double totaltime=0;
    start=clock();

    for(int i=0;i<20;i++)
    {
       ifstream fin;
       fin.open("sort1.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[10000];

      for(int i=0;i<10000;++i)
      {
          fin>>a[i];
      }

        heapSort(a,10000);
    }

    //*********************8
    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of heap(10000)"<<totaltime*50<<"ms";

        start=clock();

    for(int i=0;i<20;i++)
    {
       ifstream fin;
       fin.open("sort2.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[50000];

      for(int i=0;i<50000;++i)
      {
          fin>>a[i];
      }

        heapSort(a,50000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of heap(50000)"<<totaltime*50<<"ms";

            start=clock();

    for(int i=0;i<20;i++)
    {
       ifstream fin;
       fin.open("sort3.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[100000];

      for(int i=0;i<100000;++i)
      {
          fin>>a[i];
      }

        heapSort(a,100000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of heap(100000)"<<totaltime*50<<"ms";


                start=clock();

    for(int i=0;i<20;i++)
    {
       ifstream fin;
       fin.open("sort4.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[200000];

      for(int i=0;i<200000;++i)
      {
          fin>>a[i];
      }

        heapSort(a,200000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of heap(200000)"<<totaltime*50<<"ms";


                    start=clock();

    for(int i=0;i<20;i++)
    {
       ifstream fin;
       fin.open("sort5.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[500000];

      for(int i=0;i<500000;++i)
      {
          fin>>a[i];
      }

        heapSort(a,500000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of heap(500000)"<<totaltime*50<<"ms";
}

void testquick()
{
        clock_t start,finish;
    double totaltime=0;
    start=clock();

    for(int i=0;i<5;i++)
    {
       ifstream fin;
       fin.open("sort1.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[10000];

      for(int i=0;i<10000;++i)
      {
          fin>>a[i];
      }

        quickSort(a,10000);
    }

    //*********************8
    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of quick(10000)"<<totaltime*200<<"ms";

        start=clock();

    for(int i=0;i<5;i++)
    {
       ifstream fin;
       fin.open("sort2.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[50000];

      for(int i=0;i<50000;++i)
      {
          fin>>a[i];
      }

        quickSort(a,50000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of quick(50000)"<<totaltime*200<<"ms";

            start=clock();

    for(int i=0;i<5;i++)
    {
       ifstream fin;
       fin.open("sort3.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[100000];

      for(int i=0;i<100000;++i)
      {
          fin>>a[i];
      }

        quickSort(a,100000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of quick(100000)"<<totaltime*200<<"ms";


                start=clock();

    for(int i=0;i<5;i++)
    {
       ifstream fin;
       fin.open("sort4.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[200000];

      for(int i=0;i<200000;++i)
      {
          fin>>a[i];
      }

        quickSort(a,200000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of quick(200000)"<<totaltime*200<<"ms";


                    start=clock();

    for(int i=0;i<5;i++)
    {
       ifstream fin;
       fin.open("sort5.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[500000];

      for(int i=0;i<500000;++i)
      {
          fin>>a[i];
      }

        quickSort(a,500000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of quick(500000)"<<totaltime*200<<"ms";
}

void testbubble()
{
        clock_t start,finish;
    double totaltime=0;
    start=clock();

    for(int i=0;i<1;i++)
    {
       ifstream fin;
       fin.open("sort1.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[10000];

      for(int i=0;i<10000;++i)
      {
          fin>>a[i];
      }

        bubbleSort(a,10000);
    }

    //*********************8
    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of bubble(10000)"<<totaltime*1000<<"ms";

        start=clock();

    for(int i=0;i<1;i++)
    {
       ifstream fin;
       fin.open("sort2.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[50000];

      for(int i=0;i<50000;++i)
      {
          fin>>a[i];
      }

        bubbleSort(a,50000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of bubble(50000)"<<totaltime*1000<<"ms";

            start=clock();

    for(int i=0;i<1;i++)
    {
       ifstream fin;
       fin.open("sort3.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[100000];

      for(int i=0;i<100000;++i)
      {
          fin>>a[i];
      }

        bubbleSort(a,100000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of bubble(100000)"<<totaltime*1000<<"ms";


                start=clock();

    for(int i=0;i<1;i++)
    {
       ifstream fin;
       fin.open("sort4.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[200000];

      for(int i=0;i<200000;++i)
      {
          fin>>a[i];
      }

        bubbleSort(a,200000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of bubble(200000)"<<totaltime*1000<<"ms";


                    start=clock();

    for(int i=0;i<1;i++)
    {
       ifstream fin;
       fin.open("sort5.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[500000];

      for(int i=0;i<500000;++i)
      {
          fin>>a[i];
      }

        bubbleSort(a,500000);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of bubble(500000)"<<totaltime*1000<<"ms";
}
void testbucket()
{

    clock_t start,finish;
    double totaltime=0;
    start=clock();

    for(int i=0;i<10;i++)
    {
       ifstream fin;
       fin.open("sort1.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[10000];

      for(int i=0;i<10000;++i)
      {
          fin>>a[i];
      }

     bucketnode *b=new bucketnode,*bmp,*head;
    for(int j=0;j<10000;++j)
    {
        b->data=a[j];
        bmp=new bucketnode;
        if(j==0) head=b;
        b=b->next=bmp;
        ++j;
    }
        bucketSort(head);
    }

    //*********************8
    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of bucket(10000)"<<totaltime*100<<"ms";

        start=clock();

    for(int i=0;i<10;i++)
    {
       ifstream fin;
       fin.open("sort2.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[50000];

      for(int i=0;i<50000;++i)
      {
          fin>>a[i];
      }

             bucketnode *b=new bucketnode,*bmp,*head;
    for(int j=0;j<50000;++j)
    {
        b->data=a[j];
        bmp=new bucketnode;
        if(j==0) head=b;
        b=b->next=bmp;
        ++j;
    }
        bucketSort(head);
    }


    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of bubble(50000)"<<totaltime*100<<"ms";

            start=clock();

    for(int i=0;i<10;i++)
    {
       ifstream fin;
       fin.open("sort3.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[100000];

      for(int i=0;i<100000;++i)
      {
          fin>>a[i];
      }

           bucketnode *b=new bucketnode,*bmp,*head;
    for(int j=0;j<100000;++j)
    {
        b->data=a[j];
        bmp=new bucketnode;
        if(j==0) head=b;
        b=b->next=bmp;
        ++j;
    }
        bucketSort(head);
    }



    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of bucket(100000)"<<totaltime*100<<"ms";


                start=clock();

    for(int i=0;i<10;i++)
    {
       ifstream fin;
       fin.open("sort4.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[200000];

      for(int i=0;i<200000;++i)
      {
          fin>>a[i];
      }

             bucketnode *b=new bucketnode,*bmp,*head;
    for(int j=0;j<200000;++j)
    {
        b->data=a[j];
        bmp=new bucketnode;
        if(j==0) head=b;
        b=b->next=bmp;
        ++j;
    }
        bucketSort(head);
    }



    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of bucket(200000)"<<totaltime*100<<"ms";


                    start=clock();

    for(int i=0;i<10;i++)
    {
       ifstream fin;
       fin.open("sort5.txt");
       if(!fin.is_open ())
         cout << "Open file failure" << endl;

       int a[500000];

      for(int i=0;i<500000;++i)
      {
          fin>>a[i];
      }

             bucketnode *b=new bucketnode,*bmp,*head;
    for(int j=0;j<500000;++j)
    {
        b->data=a[j];
        bmp=new bucketnode;
        if(j==0) head=b;
        b=b->next=bmp;
        ++j;
    }
        bucketSort(head);
    }



    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<endl<<"the time of bucket(500000)"<<totaltime*100<<"ms";
}


int main()
{



    return 0;
}
