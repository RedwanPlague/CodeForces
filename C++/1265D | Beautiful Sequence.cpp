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
 
    int d0, d1, d2, d3;
    cin >> d0 >> d1 >> d2 >> d3;
 
    if(d0 == d1+1 && d2 == 0 && d3 == 0)
    {
        cout << "YES\n";
        for(int i=0; i<d1; i++)
            cout << "0 1 ";
        cout << "0 ";
        return 0;
    }
 
    if(d3 == d2+1 && d0 == 0 && d1 == 0)
    {
        cout << "YES\n";
        for(int i=0; i<d2; i++)
            cout << "3 2 ";
        cout << "3 ";
        return 0;
    }
 
    int l1 = d1 - d0;
    int l2 = d2 - d3;
    if(l1 < 0 || l2 < 0)
    {
        cout << "NO" << endl;
        return 0;
    }
 
    if(abs(l1 - l2) > 1)
    {
        cout << "NO" << endl;
        return 0;
    }
 
    cout << "YES" << endl;
    if(l1 == l2+1)
        cout << "1 ";
    for(int i=0; i<d0; i++)
        cout << "0 1 ";
    for(int i=0; i<min(l1,l2); i++)
        cout << "2 1 ";
    for(int i=0; i<d3; i++)
        cout << "2 3 ";
    if(l2 == l1+1)
        cout << "2 ";
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 