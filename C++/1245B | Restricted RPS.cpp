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
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int T;
    cin >> T;
    while(T--)
    {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        string bob;
        cin >> bob;
        int r = 0, p = 0, s = 0;
        for(auto ch: bob)
        {
            if(ch == 'R')
                r++;
            else if(ch == 'P')
                p++;
            else
                s++;
        }
        int win = min(a,s)+min(b,r)+min(c,p);
        if(win >= (n-1)/2+1)
        {
            cout << "YES\n";
            string ans = "";
            for(auto ch: bob)
            {
                if(ch == 'R' && b)
                {
                    ans += 'P';
                    b--;
                }
                else if(ch == 'P' && c)
                {
                    ans += 'S';
                    c--;
                }
                else if(ch == 'S' && a)
                {
                    ans += 'R';
                    a--;
                }
                else
                    ans += 'X';
            }
            for(auto &ch: ans)
            {
                if(ch == 'X')
                {
                    if(a)
                    {
                        ch = 'R';
                        a--;
                    }
                    else if(b)
                    {
                        ch = 'P';
                        b--;
                    }
                    else
                    {
                        ch = 'S';
                        c--;
                    }
                }
            }
            cout << ans << '\n';
        }
        else
            cout << "NO\n";
    }
 
    return 0;
}