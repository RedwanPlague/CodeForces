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
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int Q;
    cin >> Q;
    while(Q--)
    {
        int n;
        cin >> n;
        vi a(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        sort(all(a));
        int ans = 1;
        for(int i=1; i<n; i++)
        {
            if(a[i]-a[i-1] == 1)
            {
                ans++;
                break;
            }
        }
        cout << ans << '\n';
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 