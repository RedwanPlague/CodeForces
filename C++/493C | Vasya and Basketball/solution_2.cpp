#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false);
   vector < pair <int,int> > v;
   int n, d;
   cin>>n;
   int m1 = 3*n;
   while(n--)
   {
      cin>>d;
      v.push_back(make_pair(d,1));
   }
   cin>>n;
   int m2 = 3*n;
   while(n--)
   {
      cin>>d;
      v.push_back(make_pair(d,2));
   }
   sort(v.begin(),v.end());
   int p1 = m1, p2 = m2;
   for(auto i: v)
   {
      if(i.second==1)
         p1--;
      else
         p2--;
      if((p1-p2)>(m1-m2))
      {
         m1 = p1;
         m2 = p2;
      }
   }
   cout<<m1<<':'<<m2<<endl;
   return 0;
}