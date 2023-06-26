#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 401
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
string s, t;
 
short dp[MX][MX][MX];
char vis[MX][MX][MX], mark;
 
short can_make(int i, int j, int k)
{
    if(k >= t.size() && (j >= t.size() || i >= s.size()))
        return j;
    if(i >= s.size() && k < t.size())
        return -2;
    if(vis[i][j][k] == mark)
        return dp[i][j][k];
 
    vis[i][j][k] = mark;
    short can = can_make(i+1,j,k);
    if(j < t.size() && s[i] == t[j])
        can = max(can,can_make(i+1,j+1,k));
    if(k < t.size() && s[i] == t[k])
        can = max(can,can_make(i+1,j,k+1));
    return (dp[i][j][k] = can);
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
        cin >> s >> t;
        mark++;
        bool can = false;
        for(int i=0; i<=t.size(); i++)
        {
            short mj = can_make(0,0,i);
            //cout << i << " " << mj << endl;
            if(mj >= i)
            {
                can = true;
                break;
            }
        }
        if(can)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 