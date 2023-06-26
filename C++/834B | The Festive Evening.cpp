#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
 int n, k, i;
 string s;
 cin>>n>>k>>s;
 int *S = (int*)calloc(n+1,sizeof(int));
 int a[26];
 memset(a,0,sizeof(a));
 for(i=0; i<n; i++)
   {
      if(!a[s[i]-'A'])
      {
         a[s[i]-'A'] = 1;
         S[i]++;
      }
   }
   memset(a,0,sizeof(a));
   for(i=n-1; i>=0; i--)
   {
      if(!a[s[i]-'A'])
      {
         a[s[i]-'A'] = 1;
         S[i+1]--;
      }
   }
   int gate = 0;
   for(i=0; i<=n; i++)
   {
      gate += S[i];
      if(gate>k)
      {
         puts("YES");
         return 0;
      }
   }
   puts("NO");
 return 0;
}