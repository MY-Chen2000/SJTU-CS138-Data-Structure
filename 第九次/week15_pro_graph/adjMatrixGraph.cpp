#include "adjMatrixGraph.h"
#include <iostream>

using namespace std;

template<class Typev,class Typee>
adjMatrixGraph<Typev,Typee>::adjMatrixGraph(int vSize,const Typev d[],const Typee noEdgeFlag)
{
    int i,j;
    vers=vSize;
    edges=0;
    noedge=noEdgeFlag;

    ver=new Typev[vSize];
    for(i=0;i<vSize;++i) ver[i]=d[i];

    edge=new Typee*[vSize];
    for(i=0;i<vSize;++i)
    {
        edge[i]=new Typee[vSize];
        for(j=0;j<vSize;++i) edge[i][j]=noedge;
        edge[i][j]=0;
    }
}

template<class Typev,class Typee>
adjMatrixGraph<Typev,Typee>::~adjMatrixGraph()
{
    delete []ver;
    for(int i=0;i<vers;++i) delete []edge[i];
    delete []edge;
}

template<class Typev,class Typee>
void adjMatrixGraph<Typev,Typee>::insert(Typev x,Typev y,Typee w)
{
    int u=find(x),v=find(y);
    edge[u][v]=w;
    ++edges;
}

template<class Typev,class Typee>
void adjMatrixGraph<Typev,Typee>::remove(Typev x,Typev y)
{
    int u=find(x),v=find(y);
    edge[u][v]=noedge;
    --edges;
}

template<class Typev,class Typee>
bool adjMatrixGraph<Typev,Typee>::exist(Typev x,Typev y) const
{
    int u=find(x),v=find(y);
    if(edge[u][v]==noedge) return false;
    else return true;
}

template<class Typev,class Typee>
void adjMatrixGraph<Typev,Typee>::floyd()const
{
    Typee **d=new Typee*[vers];
    int **prev=new int*[vers];
    int i,j,k;

    for(i=0;i<vers;++i)
    {
        d[i]=new Typee[vers];
        prev[i]=new int[vers];
        for(j=0;j<vers;++j)
        {
            d[i][j]=edge[i][j];
            prev[i][j]=(edge[i][j]!=noedge)?i:-1;
        }
    }

    for(k=0;k<vers;++k)
        for(i=0;i<vers;++i)
            for(j=0;j<vers;++j)
                if(d[i][k]+d[k][j]<d[i][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                    prev[i][j]=prev[k][j];
                }

    cout<<"最短路径长度："<<endl;
    for(i=0;i<vers;++i)
    {
        cout<<endl;
        for(j=0;j<vers;++j) cout<<d[i][j]<<'\t';
    }
    cout<<"最短路径："<<endl;
    for(i=0;i<vers;++i)
    {
        cout<<endl;
        for(j=0;j<vers;++j) cout<<prev[i][j]<<'\t';
    }
}
