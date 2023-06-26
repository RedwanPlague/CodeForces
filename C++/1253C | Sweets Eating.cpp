#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 105
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
 
    sort(all(a));
 
    for(int i=0; i<m; i++)
    {
        for(int j=i+m; j<n; j+=m)
            a[j] += a[j-m];
    }
 
    cout << a[0] << ' ';
    for(int i=1; i<n; i++)
    {
        a[i] += a[i-1];
        cout << a[i] << ' ';
    }
    cout << endl;
 
    return 0;
}