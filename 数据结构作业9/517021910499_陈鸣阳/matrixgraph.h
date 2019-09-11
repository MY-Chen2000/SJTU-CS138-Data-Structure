#ifndef MATRIXGRAPH_H_INCLUDED
#define MATRIXGRAPH_H_INCLUDED

using namespace std;

#include <iostream>
template<class TypeOfVer,class TypeOfEdge>
class graph
{
public:
    virtual void insert(TypeOfVer x,TypeOfVer y ,TypeOfEdge w)=0;
    virtual void remove(TypeOfVer x,TypeOfVer y)=0;
    virtual bool exist(TypeOfVer x,TypeOfVer y)const=0;
    int numOfVer()const {return vers;}
    int numOfEdge()const {return edges;}


protected:
    int vers,edges;
};

template<class TypeOfVer,class TypeOfEdge>
class adjMatrixGraph:public graph<TypeOfVer,TypeOfEdge>
{
public:
    adjMatrixGraph(const TypeOfVer d[],const TypeOfEdge noEdgeFlag,int vSize=1);
    void insert(TypeOfVer x,TypeOfVer y,TypeOfEdge w);
    void remove(TypeOfVer x,TypeOfVer y);
    bool exist(TypeOfVer x,TypeOfVer y)const;
    ~adjMatrixGraph();
    void floyd()const;

private:
    TypeOfEdge **edge;
    TypeOfVer *ver;
    TypeOfEdge noedge;
     int vers,edges;
    int find(TypeOfVer v)const
    {
        for(int i=0;i<vers;++i)
            if(ver[i]==v) return i;
    }
};

template<class TypeOfVer,class TypeOfEdge>
adjMatrixGraph<TypeOfVer,TypeOfEdge>::adjMatrixGraph(const TypeOfVer d[],const TypeOfEdge noEdgeFlag,int vSize)
{
    int i,j;

    vers=vSize;
    edges=0;
    noedge=noEdgeFlag;

    ver=new TypeOfVer[vSize];
    for(i=0;i<vSize;++i) ver[i]=d[i];

    edge=new TypeOfEdge*[vSize];

    for(i=0;i<vSize;++i)
    {

        edge[i]=new TypeOfEdge[vSize];

        for(j=0;j<vSize;++j) edge[i][j]=noedge;

        edge[i][i]=0;
    }

}

template<class TypeOfVer,class TypeOfEdge>
adjMatrixGraph<TypeOfVer,TypeOfEdge>::~adjMatrixGraph()
{
    delete[]ver;
    for(int i=0;i<vers;++i)delete[]edge[i];
    delete[]edge;
}

template<class TypeOfVer,class TypeOfEdge>
void adjMatrixGraph<TypeOfVer,TypeOfEdge>::insert(TypeOfVer x,TypeOfVer y,TypeOfEdge w)
{
    int u=find(x),v=find(y);
    edge[u][v]=w;
    ++edges;
}

template<class TypeOfVer,class TypeOfEdge>
void adjMatrixGraph<TypeOfVer,TypeOfEdge>::remove(TypeOfVer x,TypeOfVer y)
{
        int u=find(x),v=find(y);

        edge[u][v]=noedge;
        --edges;
}

template<class TypeOfVer,class TypeOfEdge>
bool adjMatrixGraph<TypeOfVer,TypeOfEdge>::exist(TypeOfVer x,TypeOfVer y)const
{
    int u=find(x),v=find(y);
    if(edge[u][v]==noedge)return false;
    else return true;
}



template<class TypeOfVer,class TypeOfEdge>
void adjMatrixGraph<TypeOfVer,TypeOfEdge>::floyd()const
{
    TypeOfEdge **d=new TypeOfEdge*[vers];
    int **prev=new int *[vers];
    int i,j,k;

    for(i=0;i<vers;++i)
    {
        d[i]=new TypeOfEdge[vers];
        prev[i]=new int[vers];
        for(j=0;j<vers;++j)
        {
            d[i][j]=edge[i][j];
            prev[i][j]=(edge[i][j]!=noedge)?i:-1;
        }
    }

    for(k=0;k<vers;++k)
    {

        for(i=0;i<vers;++i)
        {
            for(j=0;j<vers;++j)
            {

                if(d[i][k]+d[k][j]<d[i][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }

    cout<<"minlen"<<endl;
    for(i=0;i<vers;++i)
    {
        cout<<endl;
        for(j=0;j<vers;++j)
        {
            cout<<d[i][j]<<'\t';
        }
        cout<<endl;
    }

    cout<<"shortestpath"<<endl;
    for(i=0;i<vers;++i)
    {
        cout<<endl;
        for(j=0;j<vers;++j)cout<<prev[i][j]<<'\t';
    }
}

#endif // MATRIXGRAPH_H_INCLUDED
