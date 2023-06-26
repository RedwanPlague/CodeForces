#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 1000000007
 
struct Node {
   int idx, l, r;
   bool operator<(const Node& other)
   {
      if(l == other.l)
         return r < other.r;
      return l > other.l;
   }
};
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int n;
   cin>>n;
   vector <Node> v(n);
 
   for(int i=0; i<n; i++)
   {
      cin>>v[i].l>>v[i].r;
      v[i].idx = i+1;
   }
 
   sort(v.begin(), v.end());
 
   int idx1 = v[0].idx, idx2 = -1, minr = v[0].r;
 
   for(int i=1; i<n; i++)
   {
      if(v[i].r >= minr)
      {
         idx2 = v[i].idx;
         break;
      }
 
      if(v[i].r < minr)
      {
         minr = v[i].r;
         idx1 = v[i].idx;
      }
 
   }
 
   if(idx2 == -1)
      idx1 = -1;
   cout<<idx1<<' '<<idx2<<endl;
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 