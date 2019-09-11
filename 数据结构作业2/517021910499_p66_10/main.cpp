#include <iostream>

using namespace std;


struct Node{
    char data;
    Node *next;
};

/*求链表长度的函数*/
int listlen(Node *head){
    int len=0;
    while(head->next!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

/*找出共同后缀的起始地址*/
Node* find_addr(Node *str1,Node *str2){
    int m,n;
    Node *p, *q;
    m=listlen (str1) ;  //求 strl 的长度
    n=listlen (str2) ;  //求 str2 的长度
    for (p=str1;m>n;m--) //若m>n，使p指向链表中的第m-n+1个结点
        p=p->next;
    for (q=str2;m<n;n--) //若m<n,使q指向链表中的第n-m+l个结点
        q=q->next;
    while (p->next !=NULL && p->next!=q->next) {
        //将指针 p 和 q 同步向后移动
        p=p->next;
        q=q->next;
    }//while
    return p->next; //返回共同后缀的起始地址
}

int main()
{

    return 0;
}
