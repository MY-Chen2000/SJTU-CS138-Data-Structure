#include <iostream>
#include "linear_list.h"
#include<cstdio>
#include <sstream>
#include <fstream>
#include <string>
#include<time.h>
#include<windows.h>
#include<ctime>
#include<cstdlib>

using namespace std;

void seqlistReadint(int j)
{

    int temp,i=0;
       seqlist<int> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

     stringstream stream;

   	string line;
ifstream fin;


fin.open("int.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;

QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

        while(!fin.eof()&&i<j)
{

getline(fin,line);


  stream.clear(); //在进行多次转换前，必须清除stream

stream << line;


    stream >>temp;
    a.insert(i,temp);
    i++;

}
QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the time of seqlist ("<<j<<"):"<<endl<<Time*1000<<"ms"<<endl;

}

void slinklistReadint(int j)
{

    int temp,i=0;
       slinklist<int> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

     stringstream stream;

   	string line;
ifstream fin;


fin.open("int.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;

QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

        while(!fin.eof()&&i<j)
{

getline(fin,line);


  stream.clear(); //在进行多次转换前，必须清除stream

stream << line;


    stream >>temp;
    a.insert(i,temp);
    i++;

}
QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the time of slinklist ("<<j<<"):"<<endl<<Time*1000<<"ms"<<endl;
}

void dlinklistReadint(int j)
{

    int temp,i=0;
       dlinklist<int> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

     stringstream stream;

   	string line;
ifstream fin;


fin.open("int.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;

QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

        while(!fin.eof()&&i<j)
{

getline(fin,line);


  stream.clear(); //在进行多次转换前，必须清除stream

stream << line;


    stream >>temp;
    a.insert(i,temp);
    i++;

}
QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the time of dlinklist ("<<j<<"):"<<endl<<Time*1000<<"ms"<<endl;

}

void myvectorReadint(int j)
{

    int temp,i=0;
       myvector<int> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

     stringstream stream;

   	string line;
ifstream fin;


fin.open("int.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;

QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

        while(!fin.eof()&&i<j)
{

getline(fin,line);


  stream.clear(); //在进行多次转换前，必须清除stream

stream << line;


    stream >>temp;
    a.insert(i,temp);
    i++;

}
QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the time of myvector ("<<j<<"):"<<endl<<Time*1000<<"ms"<<endl;

}


void seqlistReaddouble(int j)
{

    double temp;
       seqlist<double> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fin;


fin.open("double.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;

QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时


for(int i=0;;i++){
fin>>temp;
a.insert(i,temp);
if(fin.eof()==0&&i<j) ;
    else break;
}


QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the time of seqlist(double) ("<<j<<"):"<<endl<<Time*1000<<"ms"<<endl;


}

void slinklistReaddouble(int j)
{

    double temp;
       slinklist<double> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fin;


fin.open("double.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;

QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时


for(int i=0;;i++){
fin>>temp;
a.insert(i,temp);
if(fin.eof()==0&&i<j) ;
    else break;
}


QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the time of slinklist(double) ("<<j<<"):"<<endl<<Time*1000<<"ms"<<endl;


}

void dlinklistReaddouble(int j)
{

    double temp;
       dlinklist<double> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fin;


fin.open("double.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;

QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时


for(int i=0;;i++){
fin>>temp;
a.insert(i,temp);
if(fin.eof()==0&&i<j) ;
    else break;
}


QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the time of dlinklist(double) ("<<j<<"):"<<endl<<Time*1000<<"ms"<<endl;


}

void myvectorReaddouble(int j)
{

    double temp;
       myvector<double> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fin;


fin.open("double.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;

QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时


for(int i=0;;i++){
fin>>temp;
a.insert(i,temp);
if(fin.eof()==0&&i<j) ;
    else break;
}


QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the time of myvector(double) ("<<j<<"):"<<endl<<Time*1000<<"ms"<<endl;


}

void readdouble()//测量插入前1000, 5000,10000,25000,50000个double数据的时间开销
{
    //seqlist double seqlist double seqlist double seqlist double seqlist double seqlist double seqlist double seqlist double
seqlistReaddouble(1000);
seqlistReaddouble(5000);
seqlistReaddouble(10000);
seqlistReaddouble(25000);
seqlistReaddouble(50000);

//slinklist double slinklist double slinklist double slinklist double slinklist double slinklist double slinklist double
slinklistReaddouble(1000);
slinklistReaddouble(5000);
slinklistReaddouble(10000);
slinklistReaddouble(25000);
slinklistReaddouble(50000);

//dlinklist double dlinklist double dlinklist double dlinklist double dlinklist double dlinklist double dlinklist double
dlinklistReaddouble(1000);
dlinklistReaddouble(5000);
dlinklistReaddouble(10000);
dlinklistReaddouble(25000);
dlinklistReaddouble(50000);

//myvector double myvector double myvector double myvector double myvector double myvector double myvector double myvector double myvector double
myvectorReaddouble(1000);
myvectorReaddouble(5000);
myvectorReaddouble(10000);
myvectorReaddouble(25000);
myvectorReaddouble(50000);
}

void readint()//测量插入前1000, 5000,10000,25000,50000个int数据的时间开销
{
    //seqlist seqlist seqlist seqlist seqlist seqlist seqlist seqlist seqlist seqlist seqlist
seqlistReadint(1000);
seqlistReadint(5000);
seqlistReadint(10000);
seqlistReadint(25000);
seqlistReadint(50000);


//danlianbiaoslinklistslinklistslinklistslinklistslinklistslinklistslinklistslinklistslinklistslinklistslinklistslinklist

slinklistReadint(1000);
slinklistReadint(5000);
slinklistReadint(10000);
slinklistReadint(25000);
slinklistReadint(50000);


//dlinklist dlinklist dlinklist dlinklist dlinklist dlinklist dlinklist dlinklist dlinklist dlinklist dlinklist
dlinklistReadint(1000);
dlinklistReadint(5000);
dlinklistReadint(10000);
dlinklistReadint(25000);
dlinklistReadint(50000);

//myvector myvector myvector myvector myvector myvector myvector myvector myvector myvector myvector myvector myvector
myvectorReadint(1000);
myvectorReadint(5000);
myvectorReadint(10000);
myvectorReadint(25000);
myvectorReadint(50000);
}

int prorandom(int j)//产生从0到j-1的随机数
{

    return rand()*j/(RAND_MAX+1);

}

//************************//
//***************************//
void seqlistvisitint()
{
   int temp,i=0;
       seqlist<int> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

     stringstream stream;

   	string line;
ifstream fin;


fin.open("int.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;



        while(!fin.eof()&&i<50000)
{

getline(fin,line);


  stream.clear(); //在进行多次转换前，必须清除stream

stream << line;


    stream >>temp;
    a.insert(i,temp);
    i++;

}

srand(time(NULL));
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

for(int k=1000;k>0;k--)
{
    a.visit(prorandom(1000));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the visit time of seqlist (int)(1000):"<<endl<<Time*1000<<"ms"<<endl;



}

void slinklistvisitint()
{
   int temp,i=0;
       slinklist<int> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

     stringstream stream;

   	string line;
ifstream fin;


fin.open("int.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;



        while(!fin.eof()&&i<50000)
{

getline(fin,line);


  stream.clear(); //在进行多次转换前，必须清除stream

stream << line;


    stream >>temp;
    a.insert(i,temp);
    i++;

}

srand(time(NULL));
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

for(int k=1000;k>0;k--)
{
    a.visit(prorandom(1000));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the visit time of slinklist (int)(1000):"<<endl<<Time*1000<<"ms"<<endl;
}

void dlinklistvisitint()
{
   int temp,i=0;
       dlinklist<int> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

     stringstream stream;

   	string line;
ifstream fin;


fin.open("int.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;



        while(!fin.eof()&&i<50000)
{

getline(fin,line);


  stream.clear(); //在进行多次转换前，必须清除stream

stream << line;


    stream >>temp;
    a.insert(i,temp);
    i++;

}

srand(time(NULL));
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

for(int k=1000;k>0;k--)
{
    a.visit(prorandom(1000));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the visit time of dlinklist (int)(1000):"<<endl<<Time*1000<<"ms"<<endl;



}

void myvectorvisitint()
{
   int temp,i=0;
       myvector<int> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

     stringstream stream;

   	string line;
ifstream fin;


fin.open("int.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;



        while(!fin.eof()&&i<50000)
{

getline(fin,line);


  stream.clear(); //在进行多次转换前，必须清除stream

stream << line;


    stream >>temp;
    a.insert(i,temp);
    i++;

}

srand(time(NULL));
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

for(int k=1000;k>0;k--)
{
    a.visit(prorandom(1000));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the visit time of myvector(int) (1000):"<<endl<<Time*1000<<"ms"<<endl;



}


void seqlistvisitdouble()
{

    double temp;
       seqlist<double> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fin;


fin.open("double.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;


for(int i=0;;i++){
fin>>temp;
a.insert(i,temp);
if(fin.eof()==0&&i<50000) ;
    else break;
}
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.visit(prorandom(1000));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the visit time of seqlist(double) (1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void slinklistvisitdouble()
{

    double temp;
       slinklist<double> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fin;


fin.open("double.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;


for(int i=0;;i++){
fin>>temp;
a.insert(i,temp);
if(fin.eof()==0&&i<50000) ;
    else break;
}
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.visit(prorandom(1000));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the visit time of slinklist(double) (1000):"<<endl<<Time*1000<<"ms"<<endl;
}

void dlinklistvisitdouble()
{

    double temp;
    dlinklist<double> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fin;


fin.open("double.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;


for(int i=0;;i++){
fin>>temp;
a.insert(i,temp);
if(fin.eof()==0&&i<50000) ;
    else break;
}
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.visit(prorandom(1000));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the visit time of dlinklist(double) (1000):"<<endl<<Time*1000<<"ms"<<endl;
}

void myvectorvisitdouble()
{

    double temp;
       myvector<double> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fin;


fin.open("double.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;


for(int i=0;;i++){
fin>>temp;
a.insert(i,temp);
if(fin.eof()==0&&i<50000) ;
    else break;
}
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.visit(prorandom(1000));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the visit time of myvector(double) (1000):"<<endl<<Time*1000<<"ms"<<endl;
}


void seqlistvisituser()
{

    user temp;
    int k=0,i=0;
       seqlist<user> a;

 string str;
       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fsseqv;


fsseqv.open("user.txt");
if(!fsseqv.is_open ())
        cout << "Open file failure" << endl;
while(!fsseqv.eof()&&k<50000)
{

getline(fsseqv,str);
stringstream ss(str);
ss>>temp.name>>temp.gender>>temp.age>>temp.score;

a.insert(i,temp);
i++;
k++;
}


QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.visit(prorandom(1000));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the visit time of seqlist(user) (1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void slinklistvisituser()
{

    user temp;
    int k=0,i=0;
       slinklist<user> a;

 string str;
       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fssliv;


fssliv.open("user.txt");
if(!fssliv.is_open ())
        cout << "Open file failure" << endl;
while(!fssliv.eof()&&k<50000)
{

getline(fssliv,str);
stringstream ss(str);
ss>>temp.name>>temp.gender>>temp.age>>temp.score;

a.insert(i,temp);
i++;
k++;
}


QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.visit(prorandom(1000));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the visit time of slinklist(user) (1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void dlinklistvisituser()
{

    user temp;
    int k=0,i=0;
       dlinklist<user> a;

 string str;
       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fsdv;


fsdv.open("user.txt");
if(!fsdv.is_open ())
        cout << "Open file failure" << endl;
while(!fsdv.eof()&&k<50000)
{

getline(fsdv,str);
stringstream ss(str);
ss>>temp.name>>temp.gender>>temp.age>>temp.score;

a.insert(i,temp);
i++;
k++;
}


QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.visit(prorandom(1000));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the visit time of dlinklist(user) (1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void myvectorvisituser()
{

    user temp;
    int k=0,i=0;
       myvector<user> a;

 string str;
       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fsmv;


fsmv.open("user.txt");
if(!fsmv.is_open ())
        cout << "Open file failure" << endl;
while(!fsmv.eof()&&k<50000)
{

getline(fsmv,str);
stringstream ss(str);
ss>>temp.name>>temp.gender>>temp.age>>temp.score;

a.insert(i,temp);
i++;
k++;
}


QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.visit(prorandom(1000));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the visit time of myvector(user) (1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void visit()
{
    seqlistvisitint();
    slinklistvisitint();
    dlinklistvisitint();
    myvectorvisitint();

    seqlistvisitdouble();
    slinklistvisitdouble();
    dlinklistvisitdouble();
    myvectorvisitdouble();

    seqlistvisituser();
    slinklistvisituser();
    dlinklistvisituser();
    myvectorvisituser();

}
//*******************************//
//**********************************//
void seqlistreaduser(int j)
{
    int i=0,k=0;
    seqlist<user> a;
    user temp;
     double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;
    ifstream fs("user.txt");
 string str;
 QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
while(!fs.eof()&&k<j)
{

getline(fs,str);
stringstream ss(str);
ss>>temp.name>>temp.gender>>temp.age>>temp.score;

a.insert(i,temp);
i++;
k++;
}
QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the insert time of seqlist(user)("<<j<<"):"<<endl<<Time*1000<<"ms"<<endl;

}

void slinklistreaduser(int j)
{
    int i=0,k=0;
    slinklist<user> a;
    user temp;
     double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;
    ifstream fs("user.txt");
 string str;
 QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
while(!fs.eof()&&k<j)
{

getline(fs,str);
stringstream ss(str);
ss>>temp.name>>temp.gender>>temp.age>>temp.score;

a.insert(i,temp);
i++;
k++;
}
QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the insert time of slinklist(user)("<<j<<"):"<<endl<<Time*1000<<"ms"<<endl;
}

void dlinklistreaduser(int j)
{
    int i=0,k=0;
    dlinklist<user> a;
    user temp;
     double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;
    ifstream fs("user.txt");
 string str;
 QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
while(!fs.eof()&&k<j)
{

getline(fs,str);
stringstream ss(str);
ss>>temp.name>>temp.gender>>temp.age>>temp.score;

a.insert(i,temp);
i++;
k++;
}
QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the insert time of dlinklist(user)("<<j<<"):"<<endl<<Time*1000<<"ms"<<endl;
}

void myvectorreaduser(int j)
{
    int i=0,k=0;
    myvector<user> a;
    user temp;
     double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;
    ifstream fs("user.txt");
 string str;
 QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
while(!fs.eof()&&k<j)
{
getline(fs,str);
stringstream ss(str);
ss>>temp.name>>temp.gender>>temp.age>>temp.score;

a.insert(i,temp);
i++;
k++;
}
QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the insert time of myvector(user)("<<j<<"):"<<endl<<Time*1000<<"ms"<<endl;
}
void readuser()//测量插入前1000, 5000,10000,25000,50000个user数据的时间开销
{
    seqlistreaduser(1000);
    seqlistreaduser(5000);
    seqlistreaduser(10000);
    seqlistreaduser(25000);
    seqlistreaduser(50000);

    slinklistreaduser(1000);
    slinklistreaduser(5000);
    slinklistreaduser(10000);
    slinklistreaduser(25000);
    slinklistreaduser(50000);

    dlinklistreaduser(1000);
    dlinklistreaduser(5000);
    dlinklistreaduser(10000);
    dlinklistreaduser(25000);
    dlinklistreaduser(50000);

    myvectorreaduser(1000);
    myvectorreaduser(5000);
    myvectorreaduser(10000);
    myvectorreaduser(25000);
    myvectorreaduser(50000);
}


//***************************//
//**************************************.//
void seqlistremoveint()
{
   int temp,i=0;
       seqlist<int> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

     stringstream stream;

   	string line;
ifstream fin;


fin.open("int.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;



        while(!fin.eof()&&i<50000)
{

getline(fin,line);


  stream.clear(); //在进行多次转换前，必须清除stream

stream << line;


    stream >>temp;
    a.insert(i,temp);
    i++;

}

srand(time(NULL));
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

for(int k=1000;k>0;k--)
{
    a.remove(prorandom(k));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the remove time of seqlist (int)(1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void slinklistremoveint()
{
   int temp,i=0;
       slinklist<int> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

     stringstream stream;

   	string line;
ifstream fin;


fin.open("int.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;



        while(!fin.eof()&&i<50000)
{

getline(fin,line);


  stream.clear(); //在进行多次转换前，必须清除stream

stream << line;


    stream >>temp;
    a.insert(i,temp);
    i++;

}

srand(time(NULL));
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

for(int k=1000;k>0;k--)
{
    a.remove(prorandom(k));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the remove time of slinklist (int)(1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void dlinklistremoveint()
{
   int temp,i=0;
       dlinklist<int> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

     stringstream stream;

   	string line;
ifstream fin;


fin.open("int.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;



        while(!fin.eof()&&i<50000)
{

getline(fin,line);


  stream.clear(); //在进行多次转换前，必须清除stream

stream << line;


    stream >>temp;
    a.insert(i,temp);
    i++;

}

srand(time(NULL));
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

for(int k=1000;k>0;k--)
{
    a.remove(prorandom(k));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the remove time of dlinklist (int)(1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void myvectorremoveint()
{
   int temp,i=0;
       myvector<int> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

     stringstream stream;

   	string line;
ifstream fin;


fin.open("int.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;



        while(!fin.eof()&&i<50000)
{

getline(fin,line);


  stream.clear(); //在进行多次转换前，必须清除stream

stream << line;


    stream >>temp;
    a.insert(i,temp);
    i++;

}

srand(time(NULL));
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时

for(int k=1000;k>0;k--)
{
    a.remove(prorandom(k));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the remove time of myvector (int)(1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void seqlistremovedouble()
{

    double temp;
       seqlist<double> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fin;


fin.open("double.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;


for(int i=0;;i++){
fin>>temp;
a.insert(i,temp);
if(fin.eof()==0&&i<50000) ;
    else break;
}
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.remove(prorandom(k));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the remove time of seqlist(double) (1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void slinklistremovedouble()
{

    double temp;
       slinklist<double> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fin;


fin.open("double.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;


for(int i=0;;i++){
fin>>temp;
a.insert(i,temp);
if(fin.eof()==0&&i<50000) ;
    else break;
}
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.remove(prorandom(k));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the remove time of slinklist(double) (1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void dlinklistremovedouble()
{

    double temp;
       dlinklist<double> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fin;


fin.open("double.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;


for(int i=0;;i++){
fin>>temp;
a.insert(i,temp);
if(fin.eof()==0&&i<50000) ;
    else break;
}
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.remove(prorandom(k));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the remove time of dlinklist(double) (1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void myvectorremovedouble()
{

    double temp;
       myvector<double> a;

       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fin;


fin.open("double.txt");
if(!fin.is_open ())
        cout << "Open file failure" << endl;


for(int i=0;;i++){
fin>>temp;
a.insert(i,temp);
if(fin.eof()==0&&i<50000) ;
    else break;
}
QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.remove(prorandom(k));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the remove time of myvector(double) (1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void seqlistremoveuser()
{

    user temp;
    int k=0,i=0;
       seqlist<user> a;

 string str;
       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fsseqv;


fsseqv.open("user.txt");
if(!fsseqv.is_open ())
        cout << "Open file failure" << endl;
while(!fsseqv.eof()&&k<50000)
{

getline(fsseqv,str);
stringstream ss(str);
ss>>temp.name>>temp.gender>>temp.age>>temp.score;

a.insert(i,temp);
i++;
k++;
}


QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.remove(prorandom(k));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the remove time of seqlist(user) (1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void slinklistremoveuser()
{

    user temp;
    int k=0,i=0;
       slinklist<user> a;

 string str;
       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fsseqv;


fsseqv.open("user.txt");
if(!fsseqv.is_open ())
        cout << "Open file failure" << endl;
while(!fsseqv.eof()&&k<50000)
{

getline(fsseqv,str);
stringstream ss(str);
ss>>temp.name>>temp.gender>>temp.age>>temp.score;

a.insert(i,temp);
i++;
k++;
}


QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.remove(prorandom(k));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the remove time of slinklist(user) (1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void dlinklistremoveuser()
{

    user temp;
    int k=0,i=0;
       dlinklist<user> a;

 string str;
       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fsseqv;


fsseqv.open("user.txt");
if(!fsseqv.is_open ())
        cout << "Open file failure" << endl;
while(!fsseqv.eof()&&k<50000)
{

getline(fsseqv,str);
stringstream ss(str);
ss>>temp.name>>temp.gender>>temp.age>>temp.score;

a.insert(i,temp);
i++;
k++;
}


QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.remove(prorandom(k));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the remove time of dlinklist(user) (1000):"<<endl<<Time*1000<<"ms"<<endl;


}

void myvectorremoveuser()
{

    user temp;
    int k=0,i=0;
       myvector<user> a;

 string str;
       double Time=0;
       double counts=0;
       LARGE_INTEGER nFreq;
       LARGE_INTEGER nBeginTime;
       LARGE_INTEGER nEndTime;

ifstream fsseqv;


fsseqv.open("user.txt");
if(!fsseqv.is_open ())
        cout << "Open file failure" << endl;
while(!fsseqv.eof()&&k<50000)
{

getline(fsseqv,str);
stringstream ss(str);
ss>>temp.name>>temp.gender>>temp.age>>temp.score;

a.insert(i,temp);
i++;
k++;
}


QueryPerformanceFrequency(&nFreq);
QueryPerformanceCounter(&nBeginTime);//开始计时
for(int k=1000;k>0;k--)
{
    a.remove(prorandom(k));
}

QueryPerformanceCounter(&nEndTime);//停止计时
Time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
cout<<endl<<"the remove time of myvector(user) (1000):"<<endl<<Time*1000<<"ms"<<endl;


}


void remove()
{
    seqlistremoveint();
    slinklistremoveint();
    dlinklistremoveint();
    myvectorremoveint();

    seqlistremovedouble();
    slinklistremovedouble();
    dlinklistremovedouble();
    myvectorremovedouble();

    seqlistremoveuser();
    slinklistremoveuser();
    dlinklistremoveuser();
    myvectorremoveuser();
}



int main()
{

    remove();

    return 0;
}

//for(int k=1000;k>0;k--)
//{
//    a.visit(prorandom(k));
//}




















