#ifndef DISJOINTSET_H
#define DISJOINTSET_H


class disjointSet
{
    private:
        int size;
        int *parent;
    public:
        disjointSet(int s);
        ~disjointSet(){delete []parent;}
        void Union(int root1,int root2);
        int Find(int x);
};

#endif // DISJOINTSET_H
