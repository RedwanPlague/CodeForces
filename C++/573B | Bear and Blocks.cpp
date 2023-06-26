#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
 int n;
 cin >> n;
 vector<int> a(n+2), min_moves(n+2);
 int max_moves = 0;
 
 for(int i=1; i<=n; i++)
     cin >> a[i];
 
 a[0] = a[n+1] = 0;
 min_moves[0] = a[0];
 for(int i=1; i<=n+1; i++)
 {
     min_moves[i] = min(min_moves[i-1]+1,a[i]);
 }
 
 min_moves[n+1] = min(min_moves[n+1],a[n+1]);
 for(int i=n; i>=0; i--)
 {
     min_moves[i] = min(min_moves[i+1]+1,min_moves[i]);
 }
 
 for(int i=0; i<n+2; i++)
     max_moves = max(max_moves, min_moves[i]);
 
 cout << max_moves << endl;
 
 return 0;
}