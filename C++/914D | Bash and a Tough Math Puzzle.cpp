#include <iostream>
using namespace std;
 
#define MAX 500001
 
int a[MAX], tree[3*MAX];
 
int gcd(int a, int b)
{
   if(a%b==0)
      return b;
   return gcd(b, a%b);
}
 
void initialize(int cur, int b, int e)
{
   if(b==e)
   {
      tree[cur] = a[b];
      return;
   }
 
   int left = 2*cur;
   int right = 2*cur+1;
   int mid = (b+e)/2;
 
   initialize(left, b, mid);
   initialize(right, mid+1, e);
 
   tree[cur] = gcd(tree[left], tree[right]);
}
 
void update(int cur, int b, int e, int node, int val)
{
   if(node<b || node>e)
      return;
   if(b==e)
   {
      tree[cur] = val;
      return;
   }
 
   int left = 2*cur;
   int right = 2*cur+1;
   int mid = (b+e)/2;
 
   update(left, b, mid, node, val);
   update(right, mid+1, e, node, val);
 
   tree[cur] = gcd(tree[left], tree[right]);
}
 
int query(int cur, int b, int e, int l, int r, int x)
{
   if(e<l || b>r) // irrelevant nodes
      return 0;
   if(b==e)       // leaf node
   {
      if(tree[cur]%x == 0)
         return 0;
      return 1;
   }
   if(l<=b && e<=r)   // completely relevant nodes
   {
      if(tree[cur]%x == 0)
         return 0;
 
      int left = 2*cur;
      int right = left+1;
 
      if(tree[left]%x != 0 && tree[right]%x != 0)
         return 2;
 
      int mid = (b+e)/2;
 
      if(tree[left]%x != 0)
         return query(left, b, mid, l, r, x);
      if(tree[right]%x != 0)
         return query(right, mid+1, e, l, r, x);
   }
 
   int mid = (b+e)/2;
 
   return ( query(2*cur, b, mid, l, r, x) + query(2*cur+1, mid+1, e, l, r, x) );
}
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int N, Q, command, l, r, x;
   cin>>N;
   for(int i=1; i<=N; i++)
   {
      cin>>a[i];
   }
   initialize(1,1,N);
   cin>>Q;
   for(int i=0; i<Q; i++)
   {
      cin>>command;
      if(command == 1)
      {
         cin>>l>>r>>x;
         if(query(1, 1, N, l, r, x) > 1)
            cout<<"NO\n";
         else
            cout<<"YES\n";
         //cout<<query(1, 1, N, l, r, x)<<'\n';
      }
      else
      {
         cin>>l>>x;
         update(1, 1, N, l, x);
      }
   }
 
   return 0;
}