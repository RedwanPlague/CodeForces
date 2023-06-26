#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
   int n, x, a, moves = 0;
   cin>>n>>x;
   vector <int> v;
   for(int i=0; i<n; i++)
   {
      cin>>a;
      if(a==x)
         moves++;
      else
         v.pb(a);
   }
   v.pb(x);
   sort(v.begin(), v.end());
   moves += x-(find(v.begin(), v.end(), x)-v.begin());
   cout<<moves<<endl;
   return 0;
}