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
 
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        vi a(n+1), ans(n+1);
        vector<bool> done(n+1,false);
        for(int i=1; i<=n; i++)
        {
            cin >> a[i];
        }
        for(int i=1; i<=n; i++)
        {
            if(!done[i])
            {
                int start = i, cur = a[i], cnt = 1;
                done[start] = true;
                vi track;
                track.push_back(start);
                while(cur != start)
                {
                    done[cur] = true;
                    cnt++;
                    track.push_back(cur);
                    cur = a[cur];
                }
                for(int j=0; j<track.size(); j++)
                    ans[track[j]] = cnt;
            }
        }
        for(int i=1; i<=n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 