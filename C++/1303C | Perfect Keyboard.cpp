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
 
    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        char key[100];
        int mark[50];
        memset(mark,0,sizeof(mark));
        memset(key,0,sizeof(key));
        int l = 50, r = 50;
        int cur = 50;
        key[cur] = s[0];
        mark[s[0]-'a'] = cur;
        bool ok = true;
        for(int i=1; i<s.size(); i++)
        {
            //cout << cur << ' ';
            if(s[i] == key[cur-1])
                cur--;
            else if(s[i] == key[cur+1])
                cur++;
            else if(key[cur-1] == 0)
            {
                cur--;
                key[cur] = s[i];
                if(mark[s[i]-'a'] == 0)
                    mark[s[i]-'a'] = cur;
                else
                {
                    if(mark[s[i]-'a'] != cur)
                    {
                        ok = false;
                        break;
                    }
                }
            }
            else if(key[cur+1] == 0)
            {
                cur++;
                key[cur] = s[i];
                if(mark[s[i]-'a'] == 0)
                    mark[s[i]-'a'] = cur;
                else
                {
                    if(mark[s[i]-'a'] != cur)
                    {
                        ok = false;
                        break;
                    }
                }
            }
            else
            {
                ok = false;
                break;
            }
            l = min(l,cur);
            r = max(r,cur);
        }
        if(!ok)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(int i=l; i<=r; i++)
            {
                cout << key[i];
                mark[key[i]-'a'] = 1;
            }
            for(int i=0; i<26; i++)
            {
                if(mark[i] == 0)
                    cout << char(i+'a');
            }
            cout << '\n';
        }
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 