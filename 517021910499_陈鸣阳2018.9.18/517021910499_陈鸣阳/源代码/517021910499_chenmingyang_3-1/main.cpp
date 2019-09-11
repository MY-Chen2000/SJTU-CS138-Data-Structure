#include <iostream>
#include<cmath>
using namespace std;


bool judge(int n)
{
    int limit;
    if(n<=1) return false;
    if(n==2) return true;
    if((n>2)&&(n%2)==0) return false;
    limit=sqrt(n)+1;
    for(int i=3;i<=limit;i+=2)
           if ((n%i)==0) return false;
           return true;
}

int main()
{
    int m;
    cout<<"enter the number(>0)";
    cin>>m;
    if(judge(m)) cout<<"yes";
    else cout<<"no";
    return 0;
}

