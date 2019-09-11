#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template<class type>
class priorityQueue
{
    public:
        priorityQueue(int capacity=100);
        priorityQueue(const type data[],int size);
        ~priorityQueue();
        bool isEmpty()const;
        void enQueue(const type &x);
        type deQueue();
        type getHead()const;
    private:
        int currentsize;
        type *array;
        int maxsize;//ÈÝÁ¿

        void doubleSpace();
        void buildHeap();
        void percolateDown(int hole);
};

#endif // PRIORITYQUEUE_H
