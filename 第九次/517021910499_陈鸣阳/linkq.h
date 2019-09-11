#ifndef LINKQ_H_INCLUDED
#define LINKQ_H_INCLUDED

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

template <class elemType>
linkQueue<elemType>::linkQueue()
{
   front = rear = NULL;
}

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x)
{
    if (rear == NULL)
  	    front = rear = new node(x);
    else
	         rear = rear->next = new node(x);
}

template <class elemType>
elemType linkQueue<elemType>::deQueue()
{
    node *tmp = front;
    elemType value = front->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    delete tmp;
    return value;
}

template <class elemType>
bool linkQueue<elemType>::isEmpty() const
{
     return front == NULL;
}

template <class elemType>
elemType linkQueue<elemType>::getHead() const
{
     return front->data;
}

template <class elemType>
linkQueue<elemType>::~linkQueue()
{
	   node *tmp;
	   while (front != NULL) {
		      tmp = front;
		      front = front->next;
		      delete tmp;
	   }
}


#endif // LINKQ_H_INCLUDED
