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
 
    int t;
    cin >> t;
    while(t--)
    {
        map<int,int> me, mh;
        set<int> time;
        ll n, T, a, b;
        cin >> n >> T >> a >> b;
        vi cost(n);
        int t, h;
        for(int i=0; i<n; i++)
        {
            cin >> cost[i];
        }
        for(int i=0; i<n; i++)
        {
            cin >> t;
            time.insert(t);
            if(cost[i])
                mh[t]++;
            else
                me[t]++;
        }
        vector<ll> times;
        for(auto t: time)
        {
            times.push_back(t);
        }
        vector<ll> cnte(time.size()), cnth(time.size());
        cnte.back() = me[times.back()];
        cnth.back() = mh[times.back()];
        for(int i=times.size()-2; i>=0; i--)
        {
            cnte[i] = cnte[i+1] + me[times[i]];
            cnth[i] = cnth[i+1] + mh[times[i]];
        }
 
        ll ge = 0, gh = 0, ne, nh;
        int score = 0;
        for(int i=0; i<times.size(); ge += me[times[i]], gh += mh[times[i]], i++)
        {
            ll avail = times[i]-1-ge*a-gh*b;
            if(avail < 0)
                continue;
 
            ne = cnte[i];
            nh = cnth[i];
 
            //cout << "> " << avail << ' ' << ne << ' ' << nh << endl;
 
            int nsc = ge+gh;
            if(avail >= ne*a)
            {
                nsc += ne;
                nsc += min((avail-ne*a)/b,nh);
            }
            else
            {
                nsc += min(avail/a,ne);
            }
 
            score = max(score,nsc);
        }
 
        if(ge*a+gh*b <= T)
            score = n;
 
        cout << score << '\n';
    }
 
 
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 