#ifndef ADJLISTGRAPH_H
#define ADJLISTGRAPH_H
#include <cstddef>

template<class Typev,class Typee>
class adjListGraph
{
    public:
        adjListGraph(int vSize,const Typev d[]);
        void insert(Typev x,Typev y,Typee w);
        void remove(Typev x,Typev y);
        bool exist(Typev x,Typev y)const;
        void dfs()const;
        void bfs()const;
        void kruskal()const;
        void prim(Typee noEdge)const;
        void printPath(int start,int end,int prev[])const;
        void dijkstra(Typev start,Typee noEdge)const;
        void ifhavedfs(int start,int finish);
        void ifhavebfs(int start,int finish);
        ~adjListGraph();
    private:
        int vers,edges;
        struct edgenode
        {
            int end;
            Typee weight;
            edgenode *next;

            edgenode(int e,Typee w,edgenode *n=NULL)
            {end=e;weight=w;next=n;}
        };

        struct vernode
        {
            Typev ver;
            edgenode *head;

            vernode(edgenode *h=NULL){head=h;}
        };

        struct edge
        {
            int beg,end;
            Typee w;
            bool operator<(const edge &rp)const{return w<rp.w;}
        };

        vernode *verlist;
        int find(Typev v)const
        {
            for(int i=0;i<vers;++i)
                if(verlist[i].ver==v) return i;
        }

        void dfs(int start,bool visited[]) const;
        bool ifhavedfs(int start,int finish,bool visited[])const;
};

#endif // ADJLISTGRAPH_H
