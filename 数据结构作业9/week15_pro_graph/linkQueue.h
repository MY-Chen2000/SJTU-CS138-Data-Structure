#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include <malloc.h>
template <class elemType>
class linkQueue
{
    private:
       struct node {
          elemType  data;
	      node *next;
 	      node(const elemType &x, node *N = NULL){ data = x; next = NULL;}
	      node():next(NULL) {}
	      ~node() {}
	   };
	   node *front, *rear;
    public:
       linkQueue();
       ~linkQueue();

       bool isEmpty() const;
       void enQueue(const elemType &x);
       elemType deQueue();
       elemType getHead()const;
};


#endif // LINKQUEUE_H
