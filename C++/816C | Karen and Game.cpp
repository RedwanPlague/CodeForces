#include <stdio.h>
int main()
{
   int n, m, i, j, mn, f=0;
   scanf("%d %d", &n, &m);
   int a[n][m], b[n][m];
   for(i=0; i<n; i++) for(j=0; j<m; j++) {
      scanf("%d", &a[i][j]);
      b[i][j]=a[i][j];
   }
   if(n<=m) for(i=0; i<n; i++) {
      mn=501;
      for(j=0; j<m; j++) if(mn>b[i][j]) mn=b[i][j];
      for(j=0; j<mn; j++,f++) {}
      for(j=0; j<m; j++) b[i][j]-=mn;
   }
   for(i=0; i<m; i++) {
      mn=501;
      for(j=0; j<n; j++) if(mn>b[j][i]) mn=b[j][i];
      for(j=0; j<mn; j++,f++) {}
      for(j=0; j<n; j++) b[j][i]-=mn;
   }
   if(n>m) for(i=0; i<n; i++) {
      mn=501;
      for(j=0; j<m; j++) if(mn>b[i][j]) mn=b[i][j];
      for(j=0; j<mn; j++,f++) {}
      for(j=0; j<m; j++) b[i][j]-=mn;
   }
   for(i=0; i<n; i++) for(j=0; j<m; j++) if(b[i][j]!=0) { printf("-1"); return 0; }
   printf("%d\n", f);
   if(n<=m) for(i=0; i<n; i++) {
      mn=501;
      for(j=0; j<m; j++) if(mn>a[i][j]) mn=a[i][j];
      for(j=0; j<mn; j++) printf("row %d\n", i+1);
      for(j=0; j<m; j++) a[i][j]-=mn;
   }
   for(i=0; i<m; i++) {
      mn=501;
      for(j=0; j<n; j++) if(mn>a[j][i]) mn=a[j][i];
      for(j=0; j<mn; j++) printf("col %d\n", i+1);
      for(j=0; j<n; j++) a[j][i]-=mn;
   }
   if(n>m) for(i=0; i<n; i++) {
      mn=501;
      for(j=0; j<m; j++) if(mn>a[i][j]) mn=a[i][j];
      for(j=0; j<mn; j++) printf("row %d\n", i+1);
      for(j=0; j<m; j++) a[i][j]-=mn;
   }
   return 0;
}