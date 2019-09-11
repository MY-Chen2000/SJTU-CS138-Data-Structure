#include <iostream>

using namespace std;
int n;
int main()
{
   cout<<"enter the number";
   cin>>n;

   if((n%2)==0) cout<<n/2;
   else cout<<n-n/2;

   return 0;
}
