#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED


#include "sort.h"
#include "matrixgraph.h"
#include "listgraph.h"
#include <iostream>
#include <fstream>



using namespace std;

void checkdfs1()
{
    int d[10]={1,2,3,4,5,6,7,8,9,10};
    int a,b;

    ifstream fin;
    fin.open("bfs&dfs1.txt");
    if(!fin.is_open ())
      cout << "Open file failure" << endl;
    int v,e,n;
    fin>>v;
    fin>>e;
    fin>>n;


    adjListGraph<int,int> g(v,d);


    for(int i=0;i<e;++i)
    {
        fin>>a;
        fin>>b;
        g.insert(a,b,1);
        g.insert(b,a,1);
    }

    for(int i=0;i<n;++i)
    {
        fin>>a;
        fin>>b;
        g.havedfs(a,b);
    }
}


void checkbfs1()
{
        int d[10]={1,2,3,4,5,6,7,8,9,10};
    int a,b;

    ifstream fin;
    fin.open("bfs&dfs1.txt");
    if(!fin.is_open ())
      cout << "Open file failure" << endl;
    int v,e,n;
    fin>>v;
    fin>>e;
    fin>>n;


    adjListGraph<int,int> g(v,d);


    for(int i=0;i<e;++i)
    {
        fin>>a;
        fin>>b;
        g.insert(a,b,1);
        g.insert(b,a,1);
    }

        for(int i=0;i<n;++i)
    {
        fin>>a;
        fin>>b;
        g.havebfs(a,b);
    }
}

void checkdfs2()
{
        int d[10]={1,2,3,4,5,6,7,8,9,10};
    int a,b;

    ifstream fin;
    fin.open("bfs&dfs2.txt");
    if(!fin.is_open ())
      cout << "Open file failure" << endl;
    int v,e,n;
    fin>>v;
    fin>>e;
    fin>>n;


    adjListGraph<int,int> g(v,d);


    for(int i=0;i<e;++i)
    {
        fin>>a;
        fin>>b;
        g.insert(a,b,1);
    }

    for(int i=0;i<n;++i)
    {
        fin>>a;
        fin>>b;
        g.havedfs(a,b);
    }
}

void checkbfs2()
{
    int d[10]={1,2,3,4,5,6,7,8,9,10};
    int a,b;

    ifstream fin;
    fin.open("bfs&dfs2.txt");
    if(!fin.is_open ())
      cout << "Open file failure" << endl;
    int v,e,n;
    fin>>v;
    fin>>e;
    fin>>n;


    adjListGraph<int,int> g(v,d);


    for(int i=0;i<e;++i)
    {
        fin>>a;
        fin>>b;
        g.insert(a,b,1);

    }

        for(int i=0;i<n;++i)
    {
        fin>>a;
        fin>>b;
        g.havebfs(a,b);
    }

}

void testprim()
{
        int d[9]={1,2,3,4,5,6,7,8,9};
    int a,b,w;

    ifstream fin;
    fin.open("Kruscal&Prim.txt");
    if(!fin.is_open ())
      cout << "Open file failure" << endl;
    int v,e;
    fin>>v;
    fin>>e;



    adjListGraph<int,int> g(v,d);


    for(int i=0;i<e;++i)
    {
        fin>>a;
        fin>>b;
        fin>>w;
        g.insert(a,b,w);
        g.insert(b,a,w);
    }

int no=788;
        g.prim(no);
}

void testkruskal()
{
        int d[9]={1,2,3,4,5,6,7,8,9};
    int a,b,w;

    ifstream fin;
    fin.open("Kruscal&Prim.txt");
    if(!fin.is_open ())
      cout << "Open file failure" << endl;
    int v,e;
    fin>>v;
    fin>>e;



    adjListGraph<int,int> g(v,d);


    for(int i=0;i<e;++i)
    {
        fin>>a;
        fin>>b;
        fin>>w;
        g.insert(a,b,w);
        g.insert(b,a,w);
    }
     g.kruskal();
}

void testdijkstra1()
{
    int d[6]={1,2,3,4,5,6};
    int a,b,w;

    ifstream fin;
    fin.open("Floyd&Dijkstra1.txt");
    if(!fin.is_open ())
      cout << "Open file failure" << endl;
    int v,e;
    fin>>v;
    fin>>e;



    adjListGraph<int,int> g(v,d);


    for(int i=0;i<e;++i)
    {
        fin>>a;
        fin>>b;
        fin>>w;

        g.insert(a,b,w);
        g.insert(b,a,w);
    }

int no=788;
        g.dijkstra(1,no);

}

void testdijkstra2()
{
    int d[5]={1,2,3,4,5};
    int a,b,w;

    ifstream fin;
    fin.open("Floyd&Dijkstra2.txt");
    if(!fin.is_open ())
      cout << "Open file failure" << endl;
    int v,e;
    fin>>v;
    fin>>e;



    adjListGraph<int,int> g(v,d);


    for(int i=0;i<e;++i)
    {
        fin>>a;
        fin>>b;
        fin>>w;

        g.insert(a,b,w);

    }

int no=788;
        g.dijkstra(1,no);
}

void testfloyd()
{
        int d[6]={1,2,3,4,5,6};
    int a,b,w;

    ifstream fin;
    fin.open("Floyd&Dijkstra1.txt");
    if(!fin.is_open ())
      cout << "Open file failure" << endl;
    int v,e;
    fin>>v;
    fin>>e;

    int noedge=10000;

    adjMatrixGraph<int,int> g(d,noedge,v);


    for(int i=0;i<e;++i)
    {
        fin>>a;
        fin>>b;
        fin>>w;

        g.insert(a,b,w);
        g.insert(b,a,w);
    }

        g.floyd();
}

void testfloyd2()
{
        int d[5]={1,2,3,4,5};
    int a,b,w;

    ifstream fin;
    fin.open("Floyd&Dijkstra2.txt");
    if(!fin.is_open ())
      cout << "Open file failure" << endl;
    int v,e;
    fin>>v;
    fin>>e;

    int noedge=10000;

    adjMatrixGraph<int,int> g(d,noedge,v);


    for(int i=0;i<e;++i)
    {
        fin>>a;
        fin>>b;
        fin>>w;

        g.insert(a,b,w);
        g.insert(b,a,w);
    }

        g.floyd();

}


#endif // TEST_H_INCLUDED
