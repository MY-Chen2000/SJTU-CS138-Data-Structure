#include "adjListGraph.h"
#include <cstddef>
#include <iostream>
#include "linkQueue.h"
#include "linkQueue.cpp"
#include "disjointSet.h"
#include "priorityQueue.h"
#include "priorityQueue.cpp"

using namespace std;

template<class Typev,class Typee>
adjListGraph<Typev,Typee>::adjListGraph(int vSize,const Typev d[])
{
    vers=vSize;
    edges=0;
    verlist=new vernode[vSize];
    for(int i=0;i<vSize;++i) verlist[i].ver=d[i];
}

template<class Typev,class Typee>
adjListGraph<Typev,Typee>::~adjListGraph()
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

template<class Typev,class Typee>
void adjListGraph<Typev,Typee>::insert(Typev x,Typev y,Typee w)
{
    int u=find(x),v=find(y);
    verlist[u].head=new edgenode(v,w,verlist[u].head);
    ++edges;
}

template<class Typev,class Typee>
void adjListGraph<Typev,Typee>::remove(Typev x,Typev y)
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

template<class Typev,class Typee>
bool adjListGraph<Typev,Typee>::exist(Typev x,Typev y) const
{
    int u=find(x),v=find(y);
    edgenode *tmp=verlist[u].head;

    while(tmp->end!=v&&tmp!=NULL) tmp=tmp->next;
    if(tmp==NULL) return false;
    else return true;
}

template<class Typev,class Typee>
void adjListGraph<Typev,Typee>::dfs()const
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

template<class Typev,class Typee>
void adjListGraph<Typev,Typee>::dfs(int start,bool visited[])const
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

template<class Typev,class Typee>
void adjListGraph<Typev,Typee>::bfs() const
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

template<class Typev,class Typee>
void adjListGraph<Typev,Typee>::kruskal() const
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
            cout<<'('<<verlist[e.beg].ver<<','<<verlist[e.end].ver<<')\t';
        }
    }
}

template<class Typev,class Typee>
void adjListGraph<Typev,Typee>::prim(Typee noEdge)const
{
    bool *flag=new bool[vers];
    Typee *lowCost=new Typee[vers];
    int *startnode=new int[vers];

    edgenode *p;
    Typee min;
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

template<class Typev,class Typee>
void adjListGraph<Typev,Typee>::dijkstra(Typev start,Typee noEdge)const
{
    Typee *distance=new Typee[vers];
    int *prev=new int[vers];
    bool *known=new bool[vers];

    int u,sNo,i,j;
    edgenode *p;
    Typee min;
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
        cout<<"从"<<start<<"到"<<verlist[i].ver<<"的路径为："<<endl;
        printPath(sNo,i,prev);
        cout<<"\t长度为："<<distance[i]<<endl;
    }
}

template<class Typev,class Typee>
void adjListGraph<Typev,Typee>::printPath(int start,int end,int prev[])const
{
    if(start==end)
    {
        cout<<verlist[start].ver;
        return;
    }
    printPath(start,prev[end],prev);
    cout<<"-"<<verlist[end].ver;
}

template<class Typev,class Typee>
void adjListGraph<Typev,Typee>::ifhavedfs(int start,int finish)
{
    bool *visited=new bool[vers];
    for(int i=0;i<vers;++i) visited[i]=false;
    if(ifhavedfs(start,finish,visited)) cout<<"Yes!";
    else cout<<"No!";
}

template<class Typev,class Typee>
bool adjListGraph<Typev,Typee>::ifhavedfs(int start,int finish,bool visited[])const
{
    edgenode *p=verlist[start].head;
    visited[start]=true;
    while(p!=NULL)
    {
        if(visited[p->end]==false) ifhavedfs(p->end,finish,visited);
        p=p->next;
    }
    if(visited[finish]==false) return false;
    else return true;
}

template<class Typev,class Typee>
void adjListGraph<Typev,Typee>::ifhavebfs(int start,int finish)
{
    bool *visited=new bool[vers];
    int currentnode;
    linkQueue<int> q;
    edgenode *p;

    for(int i=0;i<vers;++i) visited[i]=false;

    q.enQueue(start);
    while(!q.isEmpty())
    {
        currentnode=q.deQueue();
        if(visited[currentnode]==true) continue;
        visited[currentnode]=true;
        p=verlist[currentnode].head;
        while(p!=NULL)
        {
            if(visited[p->end]==false) q.enQueue(p->end);
            p=p->next;
        }
    }
    if(visited[finish]==false) cout<<"No!";
    else cout<<"Yes!";
}
