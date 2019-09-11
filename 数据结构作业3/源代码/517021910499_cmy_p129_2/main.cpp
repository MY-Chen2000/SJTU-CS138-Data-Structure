#include <iostream>
#include"queue2.h"
#include"time.h"
#include<ctime>
#include<stdlib.h>

using namespace std;

int main()
{
   int buslow,bushigh,vanlow,vanhigh,busnum,vannum;
   int totaltime,timer;
   int ship,shiptotal;
   double buswaittime,vanwaittime;
   linkqueue<int>busqueue,vanqueue;

   //����ģ�����
   cout<<"����������ģ���ʱ�䣨min��";
   cin>>totaltime;
   cout<<"������ͳ�����ļ��ʱ�䷶Χ������ ���ޣ���";
   cin>>buslow>>bushigh;
   cout<<"�������������ļ��ʱ�䷶Χ������ ���ޣ���";
   cin>>vanlow>>vanhigh;

   //���ɿͳ�����
   srand(time(NULL));
   timer=0;
   busnum=0;
   while(true)
   {
       timer+=rand()%(bushigh-buslow+1)+buslow;
       if(timer>totaltime)break;
       busqueue.enqueue(timer);
   }

   //���ɻ�������
   timer=0;
   vannum=0;
   while(true)
   {
       timer+=rand()%(vanhigh-vanlow+1)+vanlow;
       if(timer>totaltime)break;
       vanqueue.enqueue(timer);
   }
   cout<<endl;

   //��ʼģ��
   buswaittime=vanwaittime=0;    //�ȴ�ʱ���ֵ
   busnum=vannum=0;              //���ߵĳ����ĳ�ֵ
   shiptotal=0;
   for(timer=10;timer<=totaltime;timer+=10)   //ģ��ÿ���ֶɵ���
   {
       for(ship=0;ship<8&&!busqueue.isempty()&&busqueue.gethead()<=timer;++ship)
        {
            buswaittime+=timer-busqueue.dequeue();         //ͳ�ƿͳ��ȴ�ʱ��
            ++busnum;                                      //�ѹ����Ŀͳ���
        }

        for(;ship<10&&!vanqueue.isempty()&&vanqueue.gethead()<=timer;++ship)
        {
            vanwaittime+=timer-vanqueue.dequeue();         //ͳ�ƻ����ȴ�ʱ��
            ++vannum;                                      //�ѹ����Ļ�����
        }

        for(;ship<10&&!busqueue.isempty()&&busqueue.gethead()<=timer;++ship)
        {
            buswaittime+=timer-busqueue.dequeue();
            ++busnum;
        }
        shiptotal+=ship;
   }

   //������
   cout<<"һ������"<<shiptotal<<"������ƽ��ÿ�Ҷ�������"
   <<shiptotal/((timer-10)/10)<<"����"<<endl;

   cout<<"�ͳ�ƽ���ȴ�ʱ����"<<buswaittime/busnum<<endl;
   cout<<"����ƽ���ȴ�ʱ����"<<vanwaittime/vannum<<endl;

   for(busnum=0;!busqueue.isempty();++busnum)busqueue.dequeue();
   for(vannum=0;!vanqueue.isempty();++vannum)vanqueue.dequeue();

   cout<<"���ڵȴ��Ŀͳ����ͻ������ֱ�Ϊ"<<busnum<<"��"<<vannum<<endl;


   return 0;
}
