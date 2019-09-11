#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
template<class T>
class list
{
private:
    struct node
    {
        T data;
        node *prev,*next;

        node(const T &x,node *p=NULL,node *n=NULL)
        {
            data=x;
            next=n;
            prev=p;
        }
        node():next(NULL),prev(NULL){}
        ~node(){}
    };

    node *head;

public:
    list():head(NULL){};
    ~list()
    {
        node *p=head,*q;
        while(p!=head)//删除所有节点
        {
            q=p->next;
            delete p;
            p=q;
        }
    }

     class myitr
     {
         friend list;
     private:
        node *cur;

     public:
        myitr(node *p=NULL):cur(p){}

        T &operator*()
        {
            return cur->data;
        }

        myitr operator++()
        {

         return   cur=cur->next;

        }

           myitr operator++(int x)
        {
            myitr tmp=*this;
            cur=cur->next;
            return tmp;
        }

         myitr operator--()
        {

         return   cur=cur->prev;

        }

           myitr operator--(int x)
        {
            myitr tmp=*this;
            cur=cur->prev;
            return tmp;
        }

        bool operator ==(const myitr &a)
        {
            return cur==a.cur;
        }

        bool operator !=(const myitr &a)
        {
            return cur!=a.cur;
        }

        bool isnull()
        {
            return cur==NULL;
        }
     };


     myitr begin()const
     {
         return head;
     }

     void insert(myitr &p,const T&a)
     {
         if(p.cur==NULL)
         {
             head=p.cur=new node(a);
             head->next=head;
             head->prev=head;
         }

         else
         {
             p.cur->next=p.cur->next->prev=new node(a,p.cur,p.cur->next);
             p.cur=p.cur->next;
         }
     }

     //删除迭代器指向的元素，迭代器指向被删元素的后一结点
     void erase(myitr &p)
     {
         if(p.cur==NULL)return;
         if(p.cur->next==p.cur)
         {
             delete p.cur;
             head=p.cur=NULL;
         }
         else
         {
             node *q;
             q=p.cur;
             q->next->prev=q->prev;
             q->prev->next=q->next;
             p.cur=q->next;
             if(q==head)head=q->next;
             delete q;
         }
     }

     myitr search(const T &a)
     {
         node *p=head;

         if (p==NULL)return NULL;
         do
         {
             if(a==p->data)return p;
             p=p->next;
         }while(p!=head);

         return NULL;
     }

};

#endif // LIST_H_INCLUDED
