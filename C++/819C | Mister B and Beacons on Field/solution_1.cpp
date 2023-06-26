/**   http://codeforces.com/problemset/problem/819/C   */
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
 
const int MX = 1010;
 
vector <int> prime;
 
void sieve()
{
    vector <bool> mark(MX,0);
    int limit = sqrt(MX + 1);
    prime.push_back(2);
    for(int i=3; i<MX; i+=2)
    {
        if(!mark[i])
        {
            prime.push_back(i);
            if(i<=limit)
                for(int j=i*i; j<MX; j+=2*i)
                    mark[j] = 1;
        }
    }
}
 
ll power(ll base, int pow)
{
    ll ans = 1LL;
    while(pow > 0)
    {
        if(pow&1)
            ans *= base;
        pow >>= 1;
        base *= base;
    }
    return ans;
}
 
void input(ll &N, vector<ii> &v)
{
    N = 1LL;
    ll a;
    int cnt;
    map <int,int> mp;
    for(int i=0; i<3; i++)
    {
        cin >> a;
        N *= a;
        for(int i=0; i<prime.size() && prime[i]*prime[i] <= a; i++)
        {
            if(a%prime[i] == 0)
            {
                cnt = 0;
                while(a%prime[i] == 0)
                {
                    a /= prime[i];
                    cnt++;
                }
                mp[prime[i]] += cnt;
            }
        }
        if(a > 1)
            mp[a]++;
    }
    for(map<int,int> :: iterator it = mp.begin(); it != mp.end(); it++)
        v.push_back(ii(it->first, it->second));
}
 
int count_div(const ll &N, const ll made, const int idx, const vector<ii> &v)
{
    if(idx >= v.size())
        return 1;
    int ret = 0;
    ll pr = 1LL, pow = v[idx].second;
    for(int i=0; i<=pow && pr <= N/made; i++)
    {
        ret += count_div(N, made*pr, idx+1, v);
        pr *= v[idx].first;
    }
    return ret;
}
 
ll gcd_div(const vector<ii> &Sm, const vector<ii> &Nm, const ll &M)
{
    vector <ll> pdiv;
    int i = 0, j = 0;
    while(i<Sm.size())
    {
        while(j < Nm.size() && Nm[j].first < Sm[i].first)
            pdiv.push_back(Nm[j++].first);  // because S does not have these numbers, so they can't be in k
        if(j < Nm.size() && Nm[j].first == Sm[i].first)
        {
            if(Nm[j].second > Sm[i].second)
                pdiv.push_back(power(Nm[j].first,Sm[i].second+1)); // because S has these less than N, they can not be more in k than they are in S.
            j++;
        }
        i++;
    }
    while(j<Nm.size())
        pdiv.push_back(Nm[j++].first);
    ll ans = M, vag;
    int limit = (1<<pdiv.size());
    for(int mask=1, cnt; mask<limit; mask++)
    {
        cnt = 0;
        vag = 1LL;
        for(int pos = 0; pos < pdiv.size(); pos++)
        {
            if(mask&(1<<pos))
            {
                cnt++;
                vag *= pdiv[pos];
            }
        }
        if(cnt&1)
            ans -= M/vag;
        else
            ans += M/vag;
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int T;
    cin >> T;
    while(T--)
    {
        ll N, M = 1LL, S, a;
        vector<ii> Nm, Sm;
        input(N,Nm);
        for(int i=0; i<3; i++)
        {
            cin >> a;
            M *= a;
        }
        input(S,Sm);
        S <<= 1;
        if(Sm[0].first == 2)
            Sm[0].second++;
        else
            Sm.insert(Sm.begin(),ii(2,1));
 
        cout << count_div(N, 1LL, 0, Sm) + gcd_div(Sm, Nm, M) << '\n';
 
    }
 
    return 0;
}