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
 
ll bigMod(ll base, ll pw)
{
    ll ret = 1, mul = base;
    while(pw)
    {
        if(pw&1)
            ret = (ret*mul)%MOD;
        mul = (mul*mul)%MOD;
        pw >>= 1;
    }
    return ret;
}
 
vi prime;
vector<bool> mark(MX,0);
void sieve()
{
    int limit = sqrt(MX+1);
    prime.push_back(2);
    for(int i=3; i<MX; i+=2)
    {
        if(!mark[i])
        {
            prime.push_back(i);
            if(i < limit)
            {
                for(int j=i*i; j<MX; j+=2*i)
                    mark[j] = 1;
            }
        }
    }
}
 
ll C[MX][MX];
void binom()
{
    for(int i=0; i<MX; i++)
        C[i][0] = 1LL;
    for(int i=1; i<MX; i++)
        for(int j=1; j<MX; j++)
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%MOD;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int a[4];
    int sum = 0;
    for(int i=0; i<4; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if(sum&1)
    {
        cout << "NO" << endl;
        return 0;
    }
 
    for(int i=0; i<4; i++)
    {
        if(a[i] == sum/2)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
 
    for(int i=0; i<4; i++)
    {
        for(int j=i+1; j<4; j++)
        {
            if(a[i]+a[j] == sum/2)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
 
    cout << "NO" << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 