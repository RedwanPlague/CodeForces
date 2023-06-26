#include <bits/stdc++.h>
using namespace std;
typedef struct { int bf, af; } price;
bool cmp(price a, price b)
{
   return (a.bf-a.af)<(b.bf-b.af);
}
int main()
{
   int n, i, k, cost=0;
   scanf("%d %d", &n, &k);
   price p[n];
   for(i=0; i<n; i++) scanf("%d", &p[i].bf);
   for(i=0; i<n; i++) scanf("%d", &p[i].af);
   sort(p, p+n, cmp);
   /*for(i=0; i<n; i++) printf("%d ", p[i].bf);
   putchar('\n');
   for(i=0; i<n; i++) printf("%d ", p[i].af);
   putchar('\n');*/
   for(i=0; p[i].bf-p[i].af<0 && i<n; i++, k--) cost+=p[i].bf;
   for(; k>0 && i<n; i++, k--) cost+=p[i].bf;
   for(; i<n; i++) cost+=p[i].af;
   printf("%d\n", cost);
   return 0;
}