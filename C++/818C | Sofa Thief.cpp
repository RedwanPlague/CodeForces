#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct {
   int x1, x2, y1, y2;
} sofa;
int main()
{
 int d, n, m, i,
 cl, cr, ct, cb,
 sl, sr, st, sb;
 cin>>d>>n>>m;
 sofa a[d];
 int* l = (int*)calloc(n+2,sizeof(int));
 int* r = (int*)calloc(n+2,sizeof(int));
 int* t = (int*)calloc(m+2,sizeof(int));
 int* b = (int*)calloc(m+2,sizeof(int));
 for(i=0; i<d; i++)
   {
      scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
      l[min(a[i].x1,a[i].x2)]++;
      r[max(a[i].x1,a[i].x2)]++;
      t[min(a[i].y1,a[i].y2)]++;
      b[max(a[i].y1,a[i].y2)]++;
   }
   cin>>cl>>cr>>ct>>cb;
 
   for(i=1; i<=n; i++)
      l[i] += l[i-1];
   for(i=n; i>0; i--)
      r[i] += r[i+1];
   for(i=1; i<=m; i++)
      t[i] += t[i-1];
   for(i=m; i>0; i--)
      b[i] += b[i+1];
 
   for(i=0; i<d; i++)
   {
      sl = l[max(a[i].x1,a[i].x2)-1]-(a[i].x1!=a[i].x2);
      sr = r[min(a[i].x1,a[i].x2)+1]-(a[i].x1!=a[i].x2);
      st = t[max(a[i].y1,a[i].y2)-1]-(a[i].y1!=a[i].y2);
      sb = b[min(a[i].y1,a[i].y2)+1]-(a[i].y1!=a[i].y2);
      if(sl==cl && sr==cr && st==ct && sb==cb)
      {
         cout<<i+1<<endl;
         return 0;
      }
   }
   puts("-1");
   return 0;
}