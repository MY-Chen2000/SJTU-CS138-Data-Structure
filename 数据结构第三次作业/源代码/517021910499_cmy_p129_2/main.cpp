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

   //输入模拟参数
   cout<<"请输入所需模拟的时间（min）";
   cin>>totaltime;
   cout<<"请输入客车到达的间隔时间范围（下限 上限）：";
   cin>>buslow>>bushigh;
   cout<<"请输入货车到达的间隔时间范围（下限 上限）：";
   cin>>vanlow>>vanhigh;

   //生成客车队列
   srand(time(NULL));
   timer=0;
   busnum=0;
   while(true)
   {
       timer+=rand()%(bushigh-buslow+1)+buslow;
       if(timer>totaltime)break;
       busqueue.enqueue(timer);
   }

   //生成货车队列
   timer=0;
   vannum=0;
   while(true)
   {
       timer+=rand()%(vanhigh-vanlow+1)+vanlow;
       if(timer>totaltime)break;
       vanqueue.enqueue(timer);
   }
   cout<<endl;

   //开始模拟
   buswaittime=vanwaittime=0;    //等待时间初值
   busnum=vannum=0;              //运走的车数的初值
   shiptotal=0;
   for(timer=10;timer<=totaltime;timer+=10)   //模拟每艘轮渡到达
   {
       for(ship=0;ship<8&&!busqueue.isempty()&&busqueue.gethead()<=timer;++ship)
        {
            buswaittime+=timer-busqueue.dequeue();         //统计客车等待时间
            ++busnum;                                      //已过江的客车数
        }

        for(;ship<10&&!vanqueue.isempty()&&vanqueue.gethead()<=timer;++ship)
        {
            vanwaittime+=timer-vanqueue.dequeue();         //统计货车等待时间
            ++vannum;                                      //已过江的货车数
        }

        for(;ship<10&&!busqueue.isempty()&&busqueue.gethead()<=timer;++ship)
        {
            buswaittime+=timer-busqueue.dequeue();
            ++busnum;
        }
        shiptotal+=ship;
   }

   //输出结果
   cout<<"一共运走"<<shiptotal<<"辆车，平均每艘渡轮上有"
   <<shiptotal/((timer-10)/10)<<"辆车"<<endl;

   cout<<"客车平均等待时间是"<<buswaittime/busnum<<endl;
   cout<<"货车平均等待时间是"<<vanwaittime/vannum<<endl;

   for(busnum=0;!busqueue.isempty();++busnum)busqueue.dequeue();
   for(vannum=0;!vanqueue.isempty();++vannum)vanqueue.dequeue();

   cout<<"还在等待的客车数和货车数分别为"<<busnum<<"和"<<vannum<<endl;


   return 0;
}
