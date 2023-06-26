#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 100005
#define MOD 1'000'000'007
#define set(N,pos) (N = (1LL<<(pos)))
#define clear(N,pos) (N = (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define INF (1LL<<60)
 
vi prime;
vector<bool> mark(MX,0);
 
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
 
ll get_pow(ll p, ll n)
{
    ll pw = 0, divide = p;
    while(n/divide)
    {
        pw += n/divide;
        if(divide > INF/p)
            break;
        divide *= p;
    }
    //cout << pw << endl;
    return bigMod(p,pw);
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    sieve();
 
    ll x, n;
    cin >> x >> n;
 
    ll ans = 1;
 
    for(int i=0; i<prime.size(); i++)
    {
        if(x%prime[i] == 0)
        {
            while(x%prime[i] == 0)
                x /= prime[i];
            ans = (ans*get_pow(prime[i],n))%MOD;
        }
    }
 
    if(x > 1)
        ans = (ans*get_pow(x,n))%MOD;
 
    cout << ans << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 