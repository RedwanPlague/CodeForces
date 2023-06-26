#include <bits/stdc++.h>
using namespace std;
typedef struct {
   int ind;
   unsigned long long cost;
} souv;
int k, S, n;
bool cmp(souv a, souv b)
{
   return (a.cost+a.ind*k)<(b.cost+b.ind*k);
}
unsigned long long total(souv *a)
{
   sort(a,a+n,cmp);
   int i;
   unsigned long long C=0;
   for(i=0; i<k; i++) {
      C+=a[i].cost+a[i].ind*k;
   }
   return C;
}
int main()
{
   int i;
   scanf("%d %d", &n, &S);
   souv a[n];
   for(i=0; i<n; i++) {
      a[i].ind=i+1;
      scanf("%llu", &a[i].cost);
   }
   int lo=0, hi=n+1;
   while(lo<hi-1) {
      k=(lo+hi)/2;
      if(total(a)<=S) lo=k;
      else hi=k;
   }
   k=lo;
   printf("%d %llu", k, total(a));
   return 0;
}