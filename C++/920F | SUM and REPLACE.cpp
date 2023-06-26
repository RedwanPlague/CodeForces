#include <bits/stdc++.h>
using namespace std;
 
#define MAX 300002
#define PRM 1000003
 
int ar[MAX];
int divi[PRM];
vector <int> prime;
 
struct Tree {
   long long sum;
   int mx;
} tree[4*MAX];
 
void sieve()
{
   int primeNum = sqrt(PRM) + 10; //  +10 -> to get one extra prime ( 1007 or 1009 )
 
   bool mark[primeNum];
   memset(mark, 0, sizeof(mark));
 
   divi[1] = 1;
   prime.push_back(2);
   divi[2] = 2;
 
   for(int i=3; i<primeNum; i+=2)
   {
      if(mark[i]) continue;
 
      prime.push_back(i);
      divi[i] = 2;
 
      for(int j=i*i; j<primeNum; j+=2*i)
         mark[j] = 1;
   }
}
 
void makeDiv()
{
   for(int i=4; i<PRM; i++)
   {
      if(divi[i]) continue;
      divi[i] = 1;
      int n = i;
      for(int j=0; j<prime.size() && n>1; j++)
      {
         if(n % prime[j]) continue;
         int cnt = 0;
         while(n%prime[j] == 0)
         {
            n /= prime[j];
            cnt++;
         }
         divi[i] *= (cnt+1);
      }
      if(n != 1)
         divi[i] *= 2;
   }
}
 
void initialize(int node, int b, int e)
{
   if(b == e) // leaf node
   {
      tree[node].sum = ar[b];
      tree[node].mx = ar[b];
      return;
   }
 
   int left = node<<1;
   int right = left+1;
   int mid = (b+e)>>1;
 
   initialize(left, b, mid);
   initialize(right, mid+1, e);
 
   tree[node].sum = tree[left].sum + tree[right].sum;
   tree[node].mx = max(tree[left].mx, tree[right].mx);
}
 
void update(int node, int b, int e, int l, int r)
{
   if(e<l || r<b) // irrelevant segment
      return;
   if(l<=b && e<=r) // completely relevant segment
   {
      if(tree[node].mx <= 2)
         return;
   }
   if(b == e) // leaf node
   {
      tree[node].sum = divi[tree[node].sum];
      tree[node].mx = tree[node].sum;
      return;
   }
 
   int left = node<<1;
   int right = left+1;
   int mid = (b+e)>>1;
 
   update(left, b, mid, l, r);
   update(right, mid+1, e, l, r);
 
   tree[node].sum = tree[left].sum + tree[right].sum;
   tree[node].mx = max(tree[left].mx, tree[right].mx);
}
 
long long query(int node, int b, int e, int l, int r)
{
   if(e<l || r<b) // irrelevant segment
      return 0;
   if(l<=b && e<=r) // completely relevant segment
      return tree[node].sum;
 
   int left = node<<1;
   int right = left+1;
   int mid = (b+e)>>1;
 
   return ( query(left, b, mid, l, r) + query(right, mid+1, e, l, r) );
}
 
int main()
{
   int N, Q, cmd, l, r;
 
   sieve();
   //puts("sieve");
   makeDiv();
   //puts("makeDiv");
   /*for(int i=0; i<prime.size(); i++)
      printf("%d ", prime[i]);*/
 
   scanf("%d %d", &N, &Q);
 
   for(int i=1; i<=N; i++)
      scanf("%d", &ar[i]);
 
   initialize(1, 1, N);
   //puts("initialize");
 
   while(Q--)
   {
      scanf("%d %d %d", &cmd, &l, &r);
      if(cmd == 1)
      {
         update(1, 1, N, l, r);
      }
      else
      {
         printf("%I64d\n", query(1, 1, N, l, r));
      }
   }
 
   return 0;
}