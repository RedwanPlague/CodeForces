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
 
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vi ans;
        int cur = 1;
        while(cur <= n)
        {
            ans.push_back(n/cur);
            cur = n/(n/cur) + 1;
        }
        ans.push_back(0);
        cout << ans.size() << '\n';
        for(int i=ans.size()-1; i>=0; i--)
            cout << ans[i] << ' ';
        cout << '\n';
    }
 
    return 0;
}