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
 
ll bigmod(ll base, ll pw)
{
    base %= MOD;
    pw = (pw + MOD - 1) % (MOD - 1);
    ll ret = 1;
    while(pw)
    {
        if(pw&1)
            ret = (ret*base)%MOD;
        base = (base*base)%MOD;
        pw >>= 1;
    }
    return ret;
}
 
vi prime;
vector<bool> isp(MX,true);
void sieve()
{
    int limit = sqrt(MX+.0);
    isp[0] = isp[1] = false;
    prime.push_back(2);
    for(int i=4; i<MX; i+=2)
        isp[i] = false;
    for(int i=3; i<MX; i+=2)
    {
        if(isp[i])
        {
            prime.push_back(i);
            if(i < limit)
            {
                for(int j=i*i; j<MX; j+=2*i)
                    isp[j] = false;
            }
        }
    }
}
 
 
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
    int event;
    vi mark(1000005,0);
    int day = 1, cnt = 0;
    bool ans = true;
    vi ar;
    ll sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> event;
        sum += event;
        if(event > 0)
        {
            if(mark[event] == day)
            {
                ans = false;
                break;
            }
            else
                mark[event] = day;
        }
        else
        {
            event = abs(event);
            if(mark[event] != day)
            {
                ans = false;
                break;
            }
        }
        cnt++;
        if(sum == 0)
        {
            ar.push_back(cnt);
            cnt = 0;
            day++;
        }
    }
 
    if(!ans || sum)
        cout << -1 << endl;
    else
    {
        cout << ar.size() << endl;
        for(int x : ar)
            cout << x << ' ' ;
        cout << endl;
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 