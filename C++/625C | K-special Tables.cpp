#include <bits/stdc++.h>
 
using namespace std;
 
#define MX 35
#define MOD 1000000007
#define F first
#define S second
#define invmod(x) bigmod(x,MOD-2)
#define br '\n'
#define all(v) (v).begin(),(v).end()
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
 int n, k;
 while(cin >> n >> k)
 {
  vector<vi> grid(n,vi(n));
  int use = n*n;
  k--;
  int sum = 0;
  for(int i=n-1; i>=0; i--)
  {
   for(int j=n-1; j>k; j--)
   {
    grid[i][j] = use--;
   }
   sum += use;
   grid[i][k] = use--;
  }
  for(int i=n-1; i>=0; i--)
  {
   for(int j=k-1; j>=0; j--)
   {
    grid[i][j] = use--;
   }
  }
  cout << sum << br;
  for(int i=0; i<n; i++)
  {
   for(int j=0; j<n; j++)
   {
    cout << grid[i][j] << ' ';
   }
   cout << br;
  }
 }
 
 return 0;
}