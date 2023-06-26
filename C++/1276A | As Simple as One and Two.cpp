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
 
string s;
 
bool match(int idx, string t)
{
    if(idx+t.size() > s.size())
        return false;
    for(int i=idx,j=0; j<t.size(); i++,j++)
    {
        if(s[i] != t[j])
            return false;
    }
    return true;
}
 
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
        cin >> s;
        int i = 0;
        vi ans;
        while(i<s.size())
        {
            if(match(i,"twone"))
            {
                ans.push_back(i+2+1);
                i += 5;
            }
            else if(match(i,"two") || match(i,"one"))
            {
                ans.push_back(i+1+1);
                i += 2;
            }
            else
                i++;
        }
        cout << ans.size() << '\n';
        for(int i=0; i<ans.size(); i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
 
    return 0;
}