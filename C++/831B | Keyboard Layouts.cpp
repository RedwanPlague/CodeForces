#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
 char a[26], A[26], ch, s1[30], s2[30], s[1005];
 int i;
 scanf("%s", s1);
 scanf("%s", s2);
 for(i=0; i<26; i++)
   {
      a[s1[i]-'a']=s2[i];
      A[s1[i]-'a']=s2[i]-'a'+'A';
   }
   scanf("%s", s);
   int l = strlen(s);
   for(i=0; i<l; i++)
   {
      if(s[i]>='a' && s[i]<='z')
         s[i] = a[s[i]-'a'];
      else if(s[i]>='A' && s[i]<='Z')
         s[i] = A[s[i]-'A'];
   }
   puts(s);
 return 0;
}