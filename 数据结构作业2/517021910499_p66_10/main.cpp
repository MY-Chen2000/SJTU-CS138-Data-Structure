#include <iostream>

using namespace std;


struct Node{
    char data;
    Node *next;
};

/*�������ȵĺ���*/
int listlen(Node *head){
    int len=0;
    while(head->next!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

/*�ҳ���ͬ��׺����ʼ��ַ*/
Node* find_addr(Node *str1,Node *str2){
    int m,n;
    Node *p, *q;
    m=listlen (str1) ;  //�� strl �ĳ���
    n=listlen (str2) ;  //�� str2 �ĳ���
    for (p=str1;m>n;m--) //��m>n��ʹpָ�������еĵ�m-n+1�����
        p=p->next;
    for (q=str2;m<n;n--) //��m<n,ʹqָ�������еĵ�n-m+l�����
        q=q->next;
    while (p->next !=NULL && p->next!=q->next) {
        //��ָ�� p �� q ͬ������ƶ�
        p=p->next;
        q=q->next;
    }//while
    return p->next; //���ع�ͬ��׺����ʼ��ַ
}

int main()
{

    return 0;
}
