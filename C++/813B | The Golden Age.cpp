#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
 
ull Pow(ull x, ull n)
{
   if(n==0) return 1;
   ull a=Pow(x,n/2);
   a = a*a;
   if(n%2==1) a=x*a;
   return a;
}
int main()
{
   ull x, y, l, r, a, i, j;
   cin>>x>>y>>l>>r;
   set <ull> st;
   set <ull> :: iterator it;
   for(i=0; i<=log(r)/log(x); i++)
   for(j=0; j<=log(r)/log(y); j++) {
      a=Pow(x,i)+Pow(y,j);
      if(a>=l && a<=r) st.insert(a);
   }
   a=st.size();
   ull ar[a+2];
   ar[0]=l-1; ar[a+1]=r+1;
   for(i=1, it=st.begin(); it!=st.end(); i++, it++) ar[i]=*it;
   //for(i=0; i<a+2; i++) cout<<ar[i]<<' ';
   ull mx=0;
   for(i=1; i<a+2; i++) {
      if(mx<ar[i]-ar[i-1]) mx=ar[i]-ar[i-1];
   }
   cout<<mx-1<<endl;
   return 0;
}