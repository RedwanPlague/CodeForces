#include <stdio.h>
int a[26][1502]={0};
int main()
{
   int n, i, j, r;
   scanf("%d", &n); getchar();
   char s[n];
   for(i=0; i<n; i++) s[i]=(getchar()-'a');
   char c;
   for(c=0; c<26; c++) {
      for(i=0; i<n; i++) {
         r=0;
         for(j=i; j<n; j++) {
            if(s[j]!=c) r++;
            if(j-i+1>a[c][r]) a[c][r]=j-i+1;
         }
      }
      for(i=1; i<1502; i++) if(a[c][i]==0) break;
      for(; i<1502; i++) a[c][i]=a[c][i-1];
   }
   int q, m;
   scanf("%d", &q);
   while(q--) {
      scanf("%d %c", &m, &c);
      printf("%d\n", a[c-'a'][m]);
   }
   return 0;
}