#ifndef 9GRAPH_H_INCLUDED
#define 9GRAPH_H_INCLUDED


template<class TypeOfVer,class TypeOfEdge>
class graph
{
public:
    virtual void insert(TypeOfVer x,TypeOfVer y ,TypeOfEdge w)=0;
    virtual void remove(TypeOfVer x,TypeOfVer y)=0;
    virtual bool exist(TypeOfVer x,TypeOfVer y)const=0;
    int numOfVer()const {return Vers;}
    int numOfEdge()const {return Edges;}


protected:
    int Vers,Edges;
};
template<class TypeOfVer,class TypeOfEdge>
class adjMatrixGraph:public graph<TypeOfVer,TypeOfEdge>
{
public:
    adjMatrixGraph(int vSize,const TypeOfver d[],const TypeOfEdge noEdgeFlag);
    void insert(TypeOfVer x,TypeOfVer y,TypeOfEdge w);
    void remove(TypeOfVer x,TypeOfVer y);
    bool exist(TypeOfVer x,TypeOfVer y)const;
    ~adjMatrixGraph();
    void floyd()const;

private:
    TypeOfEdge **edge;
    TypeOfVer *ver;
    TyprOfEdge noEdge;
    int find(TypeOfVer v)const
    {
        for(int i=0;i<vers;++i)
            if(ver[i]==v) return i;
    }
};

template<class TypeOfVer,class TypeOfEdge>
adjMatrixGraph<TypeOfVer,TypeOfEdge>::adjMatrixGraph(int vSize,const TypeOfVer d[],const TypeOfEdge noEdgeFlag)
{
    int i,j;

    vers=vSize;
    edges=0;
    nodge=noEdgeFlag;

    ver=new TypeOfVer[vSize];
    for(i=0;i<vSize;++i) ver[i]=d[i];

    edge=new TypeOfEdge*[vSize];
    for(i=0;i<vSize;++i)
    {
        edge[i]=new TypeOfEdge[vSize];
        for(j=0;j<vSize;++i) edge[i][j]=noedge;
        edge[i][j]=0;
    }
}

template<class TypeOfVer,class TypeOfEdge>
adjMatrixGraph<TypeOfVer,TypeOfEdge>::~adjMatrixGraph()
{
    delete[]ver;
    for(int i=0;i<Vers;++i)delete[]edge[i];
    delete[]edge;
}

template<class TypeOfVer,class TypeOfEdge>
void adjMatrixGraph<TypeOfVer,TypeOfEdge>::insert(TypeOfVer x,TypeOfVer y,TypeOfEdge w)
{
    int u=find(x),v=find(y);
    edge[u][v]=w;
    ++Edges;
}

template<class TypeOfVer,class TypeOfEdge>
void adjMatrixGraph<TypeOfVer,TypeOfEdge>::remove(TypeOfVer x,TypeOfVer y)
{
        int u=find(x),v=find(y);

        edge[u][v]=noEdge;
        --Edges;
}

template<class TypeOfVer,class TypeOfEdge>
bool adjMatrixGraph<TypeOfVer,TypeOfEdge>::exist(TypeOfVer x,TypeOfVer y)const
{
    int u=find(x),v=find(y);
    if(edge[u][v]==noEdge)return false;
    else return true;
}



template<class TypeOfVer,class TypeOfEdge>
void adjMatrixGraph<TypeOfVer,TypeOfEdge>::floyd()const
{
    TypeOfEdge **d=new TypeOfEdge*[Vers];
    int **prev=new int *[Vers];
    int i,j,k;

    for(i=0;i<Vers;++i)
    {
        d[i]=new TypeOfEdge[Vers];
        prev[i]=new int[Vers];
        for(j=0;j<Vers;++j)
        {
            d[i][j]=edge[i][j];
            prev[i][j]=(edge[i][j]!=noEdge)?i:-1;
        }
    }

    for(k=0;k<Vers;++k)
    {
        for(i=0;i<Vers;++i)
        {
            for(j=0;j<Vers;++j)
            {
                if(d[i][k]+d[k][j]<d[i][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }

    cout<<"最短路径长度"<<endl;
    for(i=0;i<Vers;++i)
    {
        cout<<endl;
        for(j=0;j<Vers;++j)
        {
            cout<<d[i][j]<<'\t';
        }
    }

    cout<<"最短路径"<<endl;
    for(i=0;i<Vers;++i)
    {
        cout<<endl;
        for(j=0;j<Vers;++j)cout<<prev[i][j]<<'\t';
    }
}


#endif // 9GRAPH_H_INCLUDED
