#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   int n, m;
   cin>>n>>m;
   char s[1001], t[1001];
   scanf("%s", s);
   scanf("%s", t);
   int i, j, dif, mnd=1000000, pos=0;
   for(i=0; i<=(m-n); i++) {
      dif=0;
      for(j=0; j<n; j++) {
         if(s[j]!=t[i+j]) dif++;
      }
      if(dif<mnd) {
         mnd=dif;
         pos=i;
      }
   }
   cout<<mnd<<endl;
   for(j=0; j<n; j++) if(s[j]!=t[pos+j]) printf("%d ", j+1);
   cout<<endl;
   return 0;
}