// http://codeforces.com/problemset/problem/1174/C
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 35
#define MOD 1'000'000'007
#define set(N,pos) (N = (1LL<<(pos)))
#define clear(N,pos) (N = (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n, cnt = 0;
    cin >> n;
    vi col(n+1,0);
 
    for(int i=2; i<=n; i++)
    {
        if(!col[i])
        {
            cnt++;
            for(int j=i; j<=n; j+=i)
                col[j] = cnt;
        }
    }
 
    for(int i=2; i<=n; i++)
        cout << col[i] << ' ';
    cout << endl;
 
    return 0;
}