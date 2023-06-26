#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MOD 107
#define MAX 30
 
int main()
{
   set <int> st;
   int n, a;
   cin>>n;
   for(int i=0; i<n; i++)
   {
      cin>>a;
      st.insert(a);
   }
   int cnt = 0;
   for(int x: st)
   {
      if(x != 0)
         cnt++;
   }
   cout<<cnt<<endl;
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 