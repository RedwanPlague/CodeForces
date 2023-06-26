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
 
int pw(ll n)
{
    for(int i=0; i<32; i++)
        if(n&(1LL<<i))
            return i;
}
 
ll sum(const vi &a, int id)
{
    ll ret = 0;
    for(int i=0; i<=id; i++)
        ret += (1LL<<i)*a[i];
    return ret;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int T;
    cin >> T;
    while(T--)
    {
        ll n, b;
        int m;
        cin >> n >> m;
        vi a(32,0);
        for(int i=0; i<m; i++)
        {
            cin >> b;
            a[pw(b)]++;
        }
        if(sum(a,31) < n)
        {
            cout << -1 << endl;
            continue;
        }
        int i = 30;
        int dv = 0;
        while(n > 0)
        {
            while(a[i] && (1LL<<i) <= n)
            {
                n -= (1LL<<i);
                a[i]--;
            }
            while(a[i] && sum(a,i-1) < n)
            {
                a[i]--;
                a[i-1] += 2;
                dv++;
            }
            i--;
        }
        cout << dv << endl;
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 