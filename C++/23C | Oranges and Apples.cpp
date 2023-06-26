#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
struct Data
{
 ll a, o, id;
 
 bool operator < (const Data &rhs) const
 {
  return ( a < rhs.a );
 }
};
 
int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
#endif
 
 int T;
 cin >> T;
 while(T--)
 {
  int n;
  cin >> n;
  int N = 2*n - 1;
 
  vector<Data> val(N);
  ll suma = 0, sumo = 0;
  for(int i=0; i<N; i++)
  {
   cin >> val[i].a >> val[i].o;
   suma += val[i].a;
   sumo += val[i].o;
   val[i].id = i+1;
  }
  sort(val.rbegin(),val.rend());
 
  vi idx1(n), idx2(n);
  idx1[0] = idx2[0] = 0;
  for(int i=1; i<n; i++)
   idx2[i] = (idx1[i] = 2*i) - 1;
  
  ll cura = 0, curo = 0;
  for(auto i: idx1)
  {
   cura += val[i].a;
   curo += val[i].o;
  }
  cout << "YES\n";
  if(2*cura >= suma && 2*curo >= sumo)
  {
   for(auto i: idx1)
    cout << val[i].id << ' ';
  }
  else
  {
   for(auto i: idx2)
    cout << val[i].id << ' ';
  }
  cout << '\n';
 }
 
 return 0;
}