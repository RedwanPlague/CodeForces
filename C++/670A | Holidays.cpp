#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int minans = 2*(n/7) + (n%7>5);
   int maxans = 2*(n/7) + min(2,(n%7));
   cout<<minans<<" "<<maxans<<endl;
   return 0;
}