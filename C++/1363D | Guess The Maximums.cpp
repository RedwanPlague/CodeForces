#include <bits/stdc++.h>
 
using namespace std;
 
#define MX 35
#define MOD 1'000'000'007
#define F first
#define S second
#define invmod(x) bigmod(x,MOD-2)
#define br '\n'
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
 
int make_query(int l, int r, int ex, const vvi& piles)
{
    int total = 0;
    for(int i=l; i<=r; i++)
    {
        if(i != ex)
            total += piles[i].size();
    }
 
    if(total == 0)
        return -1;
 
    cout << "? " << total;
    for(int i=l; i<=r; i++)
    {
        if(i != ex)
            for(int pi: piles[i])
                cout << ' ' << pi;
    }
    cout << endl;
 
    int x;
    cin >> x;
    return x;
}
 
void solve()
{
    int n, k;
    cin >> n >> k;
 
    vvi piles(k + 1);
    vector<bool> mark(n+1);
    for(int i=0; i<k; i++)
    {
        int c;
        cin >> c;
        piles[i].resize(c);
        for (int &pi : piles[i])
        {
            cin >> pi;
            mark[pi] = true;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(!mark[i])
            piles.back().push_back(i);
    }
 
    int mx = make_query(0, k, -1, piles);
    int lo = 0, hi = k;
    while(lo < hi)
    {
        int mid = (lo+hi)/2;
        if(make_query(lo, mid, -1, piles) == mx)
            hi = mid;
        else
            lo = mid+1;
    }
 
    int mx0 = make_query(0, k, lo, piles);
 
    cout << "!";
    for(int i=0; i<k; i++)
    {
        cout << ' ' << ( i == lo ? mx0 : mx );
    }
    cout << endl;
 
    string s;
    cin >> s;
    assert(s == "Correct");
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
 
    return 0;
}