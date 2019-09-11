#ifndef ADJMATRIXGRAPH_H
#define ADJMATRIXGRAPH_H

template<class Typev,class Typee>
class adjMatrixGraph
{
    public:
        adjMatrixGraph(int vSize,const Typev d[],const Typee noEdgeFlag);
        void insert(Typev x,Typev y,Typee w);
        void remove(Typev x,Typev y);
        bool exist(Typev x,Typev y)const;
        void floyd()const;
        ~adjMatrixGraph();
    private:
        Typee **edge; //存放邻接矩阵
        Typev *ver;   //存放结点值
        Typee noedge; //邻接矩阵中的∞表示值
        int vers,edges;
        int find(Typev v)const
        {
            for(int i=0;i<vers;++i)
                if(ver[i]==v) return i;
        }
};

#endif // ADJMATRIXGRAPH_H
