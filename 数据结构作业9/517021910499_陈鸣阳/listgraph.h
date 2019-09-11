#ifndef LISTGRAPH_H_INCLUDED
#define LISTGRAPH_H_INCLUDED

#include "matrixgraph.h"
#include "disjointset.h"
#include "linkq.h"
#include "prioque.h"

template<class TypeOfVer,class TypeOfEdge>
class adjListGraph:public graph<TypeOfVer,TypeOfEdge>
{
    public:
        adjListGraph(int vSize,const TypeOfVer d[]);
        void insert(TypeOfVer x,TypeOfVer y,TypeOfEdge w);
        void remove(TypeOfVer x,TypeOfVer y);
        bool exist(TypeOfVer x,TypeOfVer y)const;
        void dfs()const;
        void bfs()const;
        void kruskal()const;
        void prim(TypeOfEdge noEdge)const;
        void dijkstra(TypeOfVer start,TypeOfEdge noEdge)const;
        void printPath(int start,int end,int prev[])const;
        ~adjListGraph();
        void havedfs(int start,int end,bool visited[])const;
        void havedfs(int start,int end)const;
        void havebfs(int start,int end)const;
    private:
        int vers,edges;
        struct edgenode
        {
            int end;
            TypeOfEdge weight;
            edgenode *next;

            edgenode(int e,TypeOfEdge w,edgenode *n=NULL)
            {end=e;weight=w;next=n;}
        };

        struct vernode
        {
            TypeOfVer ver;
            edgenode *head;

            vernode(edgenode *h=NULL){head=h;}
        };

        vernode *verlist;
        int find(TypeOfVer v)const
        {
            for(int i=0;i<vers;++i)
                if(verlist[i].ver==v) return i;
        }


        struct edge
        {
            int beg,end;
            TypeOfEdge w;
            bool operator<(const edge &rp)const{return w<rp.w;}
        };

        void dfs(int start,bool visited[]) const;
};

template<class TypeOfVer,class TypeOfEdge>
adjListGraph<TypeOfVer,TypeOfEdge>::adjListGraph(int vSize,const TypeOfVer d[])
{
    vers=vSize;
    edges=0;
    verlist=new vernode[vSize];
    for(int i=0;i<vSize;++i) verlist[i].ver=d[i];
}

template<class TypeOfVer,class TypeOfEdge>
adjListGraph<TypeOfVer,TypeOfEdge>::~adjListGraph()
{
    int i;
    edgenode *tmp;
    for(i=0;i<vers;++i)
        while((tmp=verlist[i].head)!=NULL)
        {
            verlist[i].head=tmp->next;
            delete tmp;
        }
    delete []verlist;
}

template<class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::insert(TypeOfVer x,TypeOfVer y,TypeOfEdge w)
{
    int u=find(x),v=find(y);
    verlist[u].head=new edgenode(v,w,verlist[u].head);
    ++edges;
}

template<class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::remove(TypeOfVer x,TypeOfVer y)
{
    int u=find(x),v=find(y);
    edgenode *p=verlist[u].head,*q;

    if(p==NULL) return;
    if(p->end==v)
    {
        verlist[u].head=p->next;
        delete p;
        --edges;return;
    }
    while(p->next!=NULL&&p->next->end!=v) p=p->next;
    if(p->next!=NULL)
    {
        q=p->next;
        p->next=q->next;
        delete q;
        --edges;
    }
}

template<class TypeOfVer,class TypeOfEdge>
bool adjListGraph<TypeOfVer,TypeOfEdge>::exist(TypeOfVer x,TypeOfVer y) const
{
    int u=find(x),v=find(y);
    edgenode *tmp=verlist[u].head;

    while(tmp->end!=v&&tmp!=NULL) tmp=tmp->next;
    if(tmp==NULL) return false;
    else return true;
}

template<class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::dfs()const
{
    bool *visited=new bool[vers];

    for(int i=0;i<vers;++i) visited[i]=false;

    for(int i=0;i<vers;++i)
    {
        if(visited[i]) continue;
        dfs(i,visited);
        cout<<endl;
    }
}

template<class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::dfs(int start,bool visited[])const
{
    edgenode *p=verlist[start].head;

    cout<<verlist[start].ver<<'\t';
    visited[start]=true;
    while(p!=NULL)
    {
        if(visited[p->end]==false) dfs(p->end,visited);
        p=p->next;
    }
}

template<class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::bfs() const
{
    bool *visited=new bool[vers];
    int currentnode;
    linkQueue<int> q;
    edgenode *p;

    for(int i=0;i<vers;++i) visited[i]=false;

    for(int i=0;i<vers;++i)
    {
        if(visited[i]==true) continue;
        q.enQueue(i);
        while(!q.isEmpty())
        {
            currentnode=q.deQueue();
            if(visited[currentnode]==true) continue;
            cout<<verlist[currentnode].ver<<'\t';
            visited[currentnode]=true;
            p=verlist[currentnode].head;
            while(p!=NULL)
            {
                if(visited[p->end]==false) q.enQueue(p->end);
                p=p->next;
            }
        }
        cout<<endl;
    }
}

template<class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::kruskal() const
{
    int edgesAccepted=0,u,v;
    edgenode *p;
    edge e;
    disjointSet ds(vers);
    priorityQueue<edge> pq;

    for(int i=0;i<vers;++i)
    {
        for(p=verlist[i].head;p!=NULL;p=p->next)
            if(i<p->end)
            {
                e.beg=i;
                e.end=p->end;
                e.w=p->weight;
                pq.enQueue(e);
            }
    }

    while(edgesAccepted<vers-1)
    {
        e=pq.deQueue();
        u=ds.Find(e.beg);
        v=ds.Find(e.end);
        if(u!=v)
        {
            edgesAccepted++;
            ds.Union(u,v);
            cout<<'('<<verlist[e.beg].ver<<','<<verlist[e.end].ver<<')';
        }
    }
}

template<class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::prim(TypeOfEdge noEdge)const
{
    bool *flag=new bool[vers];
    TypeOfEdge *lowCost=new TypeOfEdge[vers];
    int *startnode=new int[vers];

    edgenode *p;
    TypeOfEdge min;
    int start,i,j;

    for(i=0;i<vers;++i)
    {
        flag[i]=false;
        lowCost[i]=noEdge;
    }
    start=0;
    for(i=1;i<vers;++i)
    {
        for(p=verlist[start].head;p!=NULL;p=p->next)
            if(!flag[p->end]&&lowCost[p->end]>p->weight)
            {
                lowCost[p->end]=p->weight;
                startnode[p->end]=start;
            }
        flag[start]=true;
        min=noEdge;
        for(j=0;j<vers;++j)
            if(lowCost[j]<min){min=lowCost[j];start=j;}
        cout<<'('<<verlist[startnode[start]].ver<<','<<verlist[start].ver<<')';
        lowCost[start]=noEdge;
    }
    delete []flag;
    delete []startnode;
    delete []lowCost;
}

template<class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::printPath(int start,int end,int prev[])const
{
    if(start==end)
    {
        cout<<verlist[start].ver;
        return;
    }
    printPath(start,prev[end],prev);
    cout<<"-"<<verlist[end].ver;
}

template<class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::dijkstra(TypeOfVer start,TypeOfEdge noEdge)const
{
    TypeOfEdge *distance=new TypeOfEdge[vers];
    int *prev=new int[vers];
    bool *known=new bool[vers];

    int u,sNo,i,j;
    edgenode *p;
    TypeOfEdge min;
    for(i=0;i<vers;++i)
    {
        known[i]=false;
        distance[i]=noEdge;
    }

    sNo=find(start);

    distance[sNo]=0;
    prev[sNo]=sNo;

    for(i=1;i<vers;++i)
    {
        min=noEdge;
        for(j=0;j<vers;++j)
            if(!known[j]&&distance[j]<min)
            {
                min=distance[j];
                u=j;
            }
        known[u]=true;
        for(p=verlist[u].head;p!=NULL;p=p->next)
            if(!known[p->end]&&distance[p->end]>min+p->weight)
            {
                distance[p->end]=min+p->weight;
                prev[p->end]=u;
            }
    }

    for(i=0;i<vers;++i)
    {
        cout<<"from"<<start<<"to"<<verlist[i].ver<<"path"<<endl;
        printPath(sNo,i,prev);
        cout<<" len:"<<distance[i]<<endl;
    }
}

template<class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::havedfs(int start,int end)const
{
    bool *visited=new bool[vers];

    for(int i=0;i<vers;++i)visited[i]=false;

    havedfs(start,end,visited);
}

template<class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::havedfs(int start,int end,bool visited[])const
{
    dfs(start-1,visited);

    if(visited[end-1])cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}


template<class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::havebfs(int start,int end)const
{
    bool *visited=new bool[vers];
    int currentnode;
    linkQueue<int> q;
    edgenode *p;

    for(int i=0;i<vers;++i) visited[i]=false;

    for(int i=0;i<vers;++i)
    {
        if(i!=start-1)continue;
        if(visited[i]==true) continue;
        q.enQueue(i);
        while(!q.isEmpty())
        {
            currentnode=q.deQueue();
            if(visited[currentnode]==true) continue;
            cout<<verlist[currentnode].ver<<'\t';
            visited[currentnode]=true;
            p=verlist[currentnode].head;
            while(p!=NULL)
            {
                if(visited[p->end]==false) q.enQueue(p->end);
                p=p->next;
            }
        }
        cout<<endl;
    }
    if(visited[end-1])cout<<"yes";
    else cout<<"no";
}

#endif // LISTGRAPH_H_INCLUDED
