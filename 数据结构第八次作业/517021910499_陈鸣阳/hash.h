#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include "dst.h"
#include"lll_int.h"
#include<sstream>
#include "string.h"
#include<string>
#include<ctime>

template<class KEY,class OTHER>
class closeHashTable//:public dynamicSearchTable<KEY,OTHER>
{
private:
    struct node
    {
        SET<KEY,OTHER>data;
        int state;

        node(){state=0;}
    };


    //
    int collisionNum=0;
    //
    node *array;
    int size;
    int (closeHashTable::*key)( KEY x);
    int (closeHashTable::*Hash)(int pos );

    int slmod(string x)//n==1
    {
        string p="49999";
        string tmps=mod(x,p);

        stringstream tmpf;
        tmpf<<tmps;

        int tmp;
        tmpf>>tmp;

        return tmp;
    }

    int slshufen(string x)//n==2
    {
        string tmps;
        tmps=x.substr(1,5);

        string ff=mod(tmps,"49999");

        stringstream tmpf;
        tmpf<<ff;

        int tmp;
        tmpf>>tmp;

        return tmp;
    }

    int slsquare(string x)//n==3
    {
        string xx=multiply(x,x);
        string tmps=xx.substr(1,7);

        string ff=mod(tmps,"49999");
        stringstream tmpf;
        tmpf<<ff;

        int tmp;
        tmpf>>tmp;

        return tmp;
    }

    int slfold(string x)//n==4
    {
        int keylen=x.length();
        if(keylen==6)
        {
            string s1,s2;
            s1=x.substr(0,1);
            s2=x.substr(1,5);
            string x2=add(s1,s2);
            string tmps=mod(x2,"49999");
            stringstream tmpf;
            tmpf<<tmps;

            int tmp;
            tmpf>>tmp;

            return tmp;
        }
        if(keylen>6)
        {
            string s1,s2,s3;
            s1=x.substr(0,6);
            s2=x.substr(6,6);
            s3=x.substr(12,6);
            string tmpadd=add(s1,s2);
            string x2=add(tmpadd,s3);
            string tmps=mod(x2,"49999");
            stringstream tmpf;
            tmpf<<tmps;

            int tmp;
            tmpf>>tmp;

            return tmp;
        }
    }

    //
    int load;

    void  doubleSpace();
    bool isPrime(int n);
    int nextPrime(int n);

    int Hashx(int pos)
    {
        return (pos+1)%size;
    }

    int Hashe(int pos )
    {
        return (pos+2*(++collisionNum)-1)%size;
    }

public:
    closeHashTable(int length=101,int m=1,int n=1);
    closeHashTable( closeHashTable<KEY,OTHER> &t)
{
    selectHash=t.selectHash;
    selectsl=t.selectsl;
    load=t.load;
    collisionNum=t.collisionNum;
    size=t.size;
    array=new node [size];
    for(int i=0;i<size;i++)
    {
        array[i]=t.array[i];
    }

}

    ~closeHashTable(){delete[]array;}
    SET<KEY,OTHER>*find(const KEY &x);
    void insert(const SET<KEY,OTHER>&x);
    void remove(const KEY &x);
    //


    int selectHash;
    int selectsl;
};

template<class KEY,class OTHER>
void closeHashTable<KEY,OTHER>::doubleSpace()
{
    node *tmp=array;
    int oldsize=size;
    size=nextPrime(oldsize*2);
    load=0;

    array=new node [size];
    for(int i=0;i<oldsize;i++)
    {
        if(tmp[i].state==1)insert(tmp[i].data);
    }
    delete[] tmp;
}

template<class KEY,class OTHER>
bool closeHashTable<KEY,OTHER>::isPrime(int n)
{
    if(n==2||n==3)return true;
    if(n==1||n%2==0)return false;
    for(int i=3;i*i<n;i+=2)
        if(n%i==0)return false;
    return true;
}

template<class KEY,class OTHER>
int closeHashTable<KEY,OTHER>::nextPrime(int n)
{
    if(n%2==0)++n;
    while(!isPrime(n))n+=2;
    return n;
}


template<class KEY,class OTHER>
closeHashTable<KEY,OTHER>::closeHashTable(int length,int m,int n)
{
    size=nextPrime(length);
    array=new node [size];
    selectHash=m;
    selectsl=n;
    if(selectHash==1)Hash=&closeHashTable::Hashx;
    if(selectHash==2)Hash=&closeHashTable::Hashe;
    if(selectsl==1)key=&closeHashTable::slmod;
    if(selectsl==2)key=&closeHashTable::slshufen;
    if(selectsl==3)key=&closeHashTable::slsquare;
    if(selectsl==4)key=&closeHashTable::slfold;

    load=0;
}
//template<class KEY,class OTHER>
//closeHashTable<KEY,OTHER>::



//template<class KEY,class OTHER>
//void closeHashTable<KEY,OTHER>::sciE(int initPos,int pos,const SET<KEY,OTHER> &x)
//{
//    int collisionNum=0;
//    if(load*2>=size)doubleSpace();
//    do
//    {
//        if(array[pos].state!=1)
//        {
//            array[pos].data=x;
//            array[pos].state=1;
//            ++load;
//            return;
//        }pos=(pos+2*(++collisionNum)-1)%size;
//    }while(pos!=initPos);
//}

template<class KEY,class OTHER>
void closeHashTable<KEY,OTHER>::insert(const SET<KEY,OTHER> &x)
{
    int initPos,pos;

    if((load*2>=size)&&(selectHash==2))doubleSpace();

    initPos = pos=(this->*key)(x.key);

     do
    {
        if(array[pos].state!=1)
        {
            array[pos].data=x;
            array[pos].state=1;
            ++load;
            return;
        }
        pos=(this->*Hash)(pos);
    }while(pos != initPos);



}

//remove



template<class KEY,class OTHER>
void closeHashTable<KEY,OTHER>::remove(const KEY &x)
{
    int initPos,pos;

    initPos=pos=(this->*key)(x);
    do
    {
        if(array[pos].state==0)return;
        if(array[pos].state==1&&array[pos].data.key==x)
        {
            array[pos].state=2;
            return;
        }
        pos=(pos+1)%size;
    }while(pos!=initPos);
}


template<class KEY,class OTHER>
SET<KEY,OTHER> *closeHashTable<KEY,OTHER>::find(const KEY &x)
{
    int initPos,pos;

    initPos=pos=(this->*key)(x);
    do
    {
        if(array[pos].state==0)return NULL;
        if(array[pos].state==1&&array[pos].data.key==x)
            return(SET<KEY,OTHER> *)&array[pos];
        pos=(pos+1)%size;
    }while(pos!=initPos);
}


struct datahash
{
    string id;
    string name;
    string sex;
    int age;
    int score;
};



void test(char * filename,int longorshort,int m,int n)
{

   RandomString ranstr;


//   for(int m=1;m<=2;m++)
//   {
//       for(int n=1;n<=4;n++)
//       {

               ifstream fin(filename);

                string tmpid;

                if(!fin.is_open ())
                cout << "Open file failure" << endl;

               // vector<string> temp;

                closeHashTable<string,datahash> table(50000,m,n);
                SET<string,datahash> a;


                while(fin.eof()==0)
                {
                    fin>>tmpid;
                    a.key=tmpid;
                    a.other.id=tmpid;
                   // temp.push_back(tmpid);
                    fin>>a.other.name;
                    fin>>a.other.sex;
                    fin>>a.other.age;
                    fin>>a.other.score;
                    table.insert(a);

                }
                //random_shuffle(temp.begin(), temp.end());

                fin.close();

//               **********查找
               clock_t start,finish;
               double totaltime=0;
               start=clock();
               // ////
              for(int i=0;i<10;i++)
              {
                  for(int j=0;j<1000;j++)//查找1000个数
                  {

                      if(longorshort==0)
                      {
                            table.find(ranstr.getlong());
                      }
                      if(longorshort=1)
                      {
                          table.find(ranstr.getshort());
                      }

                  }
              }

            //  //  //
            finish=clock();
            totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
            cout<<endl<<"the time of find:m="<<table.selectHash<<"n="<<table.selectsl<<"time:"<<totaltime*100<<"ms";

            //*************插入
            totaltime=0;
               start=clock();
               // ////
              for(int i=0;i<5;i++)
              {

                ifstream fin2(filename);

                string tmpid2;

                if(!fin2.is_open ())
                cout << "Open file failure" << endl;

                closeHashTable<string,datahash> table2(50000,m,n);
                SET<string,datahash> a2;


                while(fin2.eof()==0)
                {
                    fin2>>tmpid2;
                    a2.key=tmpid2;
                    a2.other.id=tmpid2;

                    fin2>>a2.other.name;
                    fin2>>a2.other.sex;
                    fin2>>a2.other.age;
                    fin2>>a2.other.score;
                    table2.insert(a2);

                }
                fin2.close();
              }

            //  //  //
            finish=clock();
            totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
            cout<<endl<<"the time of insert:m="<<m<<"n="<<n<<"time:"<<totaltime*200<<"ms";




}

void testremove(char * filename,int longorshort,int m,int n)
{
                           // *************删除
                           RandomString ranstr;
                       ifstream fin3(filename);

                string tmpid3;

                if(!fin3.is_open ())
                cout << "fin3Open file failure" << endl;

               // vector<string> temp;

                closeHashTable<string,datahash> table3(50000,m,n),table4(50000,m,n),table5(50000,m,n),table6(50000,m,n),table7(50000,m,n);
                SET<string,datahash> a3;


                while(fin3.eof()==0)
                {
                    fin3>>tmpid3;
                    a3.key=tmpid3;
                    a3.other.id=tmpid3;
                   // temp.push_back(tmpid);
                    fin3>>a3.other.name;
                    fin3>>a3.other.sex;
                    fin3>>a3.other.age;
                    fin3>>a3.other.score;
                    table3.insert(a3);
                    table4.insert(a3);
                    table5.insert(a3);
                    table6.insert(a3);
                    table7.insert(a3);

                }
                //random_shuffle(temp.begin(), temp.end());

                fin3.close();

               clock_t start,finish;
               double totaltime=0;
               start=clock();
                ////


//                    for(int i=0;i<500;i++)
//                {
//                        tmptable2.remove(temp.at(i));
//                }

                    for(int i=0;i<500;i++)
                {
                      if(longorshort==0)
                      {
                            table3.remove(ranstr.getlong());
                      }
                      if(longorshort=1)
                      {
                          table3.remove(ranstr.getshort());
                      }
                }
                    for(int i=0;i<500;i++)
                {
                      if(longorshort==0)
                      {
                            table4.remove(ranstr.getlong());
                      }
                      if(longorshort=1)
                      {
                          table4.remove(ranstr.getshort());
                      }
                }
                                    for(int i=0;i<500;i++)
                {
                      if(longorshort==0)
                      {
                            table5.remove(ranstr.getlong());
                      }
                      if(longorshort=1)
                      {
                          table5.remove(ranstr.getshort());
                      }
                }
                                    for(int i=0;i<500;i++)
                {
                      if(longorshort==0)
                      {
                            table6.remove(ranstr.getlong());
                      }
                      if(longorshort=1)
                      {
                          table6.remove(ranstr.getshort());
                      }
                }
                                  for(int i=0;i<500;i++)
                {
                      if(longorshort==0)
                      {
                            table7.remove(ranstr.getlong());
                      }
                      if(longorshort=1)
                      {
                          table7.remove(ranstr.getshort());
                      }
                }

            //  //  //
            finish=clock();
            totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
            cout<<endl<<"the time of remove:m="<<m<<"n="<<n<<"time:"<<totaltime*200<<"ms";

//       }
//
//   }
}

#endif // HASH_H_INCLUDED
