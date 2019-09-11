#include <iostream>
#include"stack2.h"


using namespace std;

int main()
{
    int n;
    seqstack<int> s;

    cout<<"请输入十进制数";
    cin>>n;

    while(n!=0)
    {
        s.push(n%2);
        n=n/2;
    }

    while(!s.isempty())
    {
        cout<<s.pop();
    }

    return 0;
}
