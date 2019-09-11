#include "disjointSet.h"

disjointSet::disjointSet(int s)
{
    size=s;
    parent=new int[size];
    for(int i=0;i<s;++i) parent[i]=-1;
}

int disjointSet::Find(int x)
{
    if(parent[x]<0) return x;
    return parent[x]=Find(parent[x]);
}

void disjointSet::Union(int root1,int root2)
{
    if(root1==root2) return;
    if(parent[root1]>parent[root2])
    {
        parent[root2]+=parent[root1];
        parent[root1]=root2;
    }
    else
    {
        parent[root1]+=parent[root2];
        parent[root2]=root1;
    }
}
