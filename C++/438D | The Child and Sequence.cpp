#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 100005
#define F first
#define S second
#define br '\n'
 
class SegmentTree
{
 struct Data
 {
  ll sum;
  int mx, mxidx;
  Data() {}
  Data(ll sum, int mx, int mxidx) : sum(sum), mx(mx), mxidx(mxidx) {}
 }
 tree[4*MX];
 int N;
 
 Data merge(const Data& a, const Data& b) const  
 {
  Data ret;
  ret.sum = a.sum + b.sum;
  if(a.mx > b.mx)
  {
   ret.mx = a.mx;
   ret.mxidx = a.mxidx;
  }
  else
  {
   ret.mx = b.mx;
   ret.mxidx = b.mxidx;
  }
  return ret;
 }
 
 void build(int cur, int l, int r, int *a)
 {
  if(l == r)
  {
   tree[cur] = Data(a[l], a[l], l);
   return ;
  }
 
  int left = cur<<1;
  int right = left|1;
  int mid = (l+r)>>1;
 
  build(left, l, mid, a);
  build(right, mid+1, r, a);
 
  tree[cur] = merge(tree[left], tree[right]);
 }
 
 Data query(int cur, int l, int r, int L, int R) const 
 {
  if(R < l || r < L)
  {
   return Data(0,-1,-1);
  }
  if(L <= l && r <= R)
  {
   return tree[cur];
  }
 
  int left = cur<<1;
  int right = left|1;
  int mid = (l+r)>>1;
 
  Data ret1 = query(left, l, mid, L, R);
  Data ret2 = query(right, mid+1, r, L, R);
 
  return merge(ret1,ret2);
 }
 
 void update(int cur, int l, int r, int idx, int val)
 {
  if(idx < l || idx > r)
  {
   return ; 
  }
  if(l == r && idx == l)
  {
   tree[cur] = Data(val,val,l);
   return ;
  }
  
  int left = cur<<1;
  int right = left|1;
  int mid = (l+r)>>1;
 
  if(idx <= mid)
   update(left, l, mid, idx, val);
  else
   update(right, mid+1, r, idx, val);
 
  tree[cur] = merge(tree[left], tree[right]);
 }
 
public:
 
 SegmentTree(int N, int *a) : N(N)
 {
  build(1,1,N,a);
 }
 
 ll getsum(int L, int R) const 
 {
  return query(1,1,N,L,R).sum;
 }
 
 pii getmx(int L, int R) const
 {
  Data ret = query(1,1,N,L,R);
  return {ret.mx, ret.mxidx};
 }
 
 void update(int idx, int val)
 {
  update(1,1,N,idx,val);
#ifndef ONLINE_JUDGE
  print();
#endif
 }
 
 void print() const
 {
  for(int i=1; i<=N; i++)
  {
   cout << getsum(i,i) << ' ';
  }
  cout << br;
 }
};
 
int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
#endif
 
    int n, m;
 int a[MX];
 
 while(cin >> n >> m)
 {
  for(int i=1; i<=n; i++)
  {
   cin >> a[i];
  }
  SegmentTree segt(n,a);
#ifndef ONLINE_JUDGE
  segt.print();
#endif
 
  int type, l, r, x, k;
  pii use;
  while(m--)
  {
   cin >> type;
   switch(type)
   {
    case 1:
     cin >> l >> r;
     cout << segt.getsum(l,r) << br;
     break;
    case 2:
     cin >> l >> r >> x;
     use = segt.getmx(l,r);
     while(x <= use.F)
     {
      segt.update(use.S, use.F%x);
      use = segt.getmx(l,r);
     }
     break;
    case 3:
     cin >> k >> x;
     segt.update(k,x);
     break;
   }
  }
#ifndef ONLINE_JUDGE
  cout << "--------" << br;
#endif
 }
 
    return 0;
}
 