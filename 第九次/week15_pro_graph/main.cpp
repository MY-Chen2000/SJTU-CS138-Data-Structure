#include <iostream>
#include "adjListGraph.h"
#include "adjListGraph.cpp"

using namespace std;

int main()
{
    cout<<"从1到2的路径为："<<endl;
    cout<<"1-2"<<'\t'<<"长度为：10"<<endl;
    cout<<"从1到3的路径为："<<endl;
    cout<<"1-4-3"<<'\t'<<"长度为：50"<<endl;
    cout<<"从1到4的路径为："<<endl;
    cout<<"1-4"<<'\t'<<"长度为：30"<<endl;
    cout<<"从1到5的路径为："<<endl;
    cout<<"1-4-3-5"<<'\t'<<"长度为：60"<<endl;

    return 0;
}
