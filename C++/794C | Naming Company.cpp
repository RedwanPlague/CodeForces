#include <bits/stdc++.h>
using namespace std;
int main()
{
   string aa, bb, s="", c="";
   cin>>aa>>bb;
   unsigned i, n = aa.length();
   sort(aa.begin(),aa.end());
   sort(bb.begin(),bb.end());
   reverse(bb.begin(),bb.end());
   list <char> a, b;
   for(i=0; i<(n+1)/2; i++) a.push_back(aa[i]);
   for(i=0; i<n/2; i++) b.push_back(bb[i]);
   for(i=0; i<n; i++) {
      if(i%2) {
         if(a.front()<b.front()) {
            s+=b.front();
            b.pop_front();
         }
         else {
            c+=b.back();
            b.pop_back();
         }
      }
      else {
         if(a.front()<b.front()) {
            s+=a.front();
            a.pop_front();
      }
         else {
            c+=a.back();
            a.pop_back();
         }
      }
   }
   reverse(c.begin(),c.end());
   s+=c;
   cout<<s<<endl;
   return 0;
}