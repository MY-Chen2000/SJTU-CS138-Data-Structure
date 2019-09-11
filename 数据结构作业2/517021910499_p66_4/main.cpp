#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    int n,k;
    list<int> jsph;
    list<int>::myitr itr;

    //输入人数
    cout<<"please input the number of people";
    cin>>n;

    //创建约瑟夫环
    for(k=0,itr=jsph.begin();k<n;++k)
        jsph.insert(itr,k);

    //模拟报数过程

    for(itr=jsph.begin(),k=1;k<n;++k)
    {
        ++itr;
        ++itr;
        cout<<"delete"<<*itr<<endl;
        jsph.erase(itr);
    }

    cout<<"remain"<<*itr<<endl;

    return 0;
}
