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
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n, k;
    string s;
 
    while(cin >> n >> k)
    {
        cin >> s;
 
        if(s.size() == 1)
        {
            if(k)
                s[0] = '0';
        }
        else
        {
            if(s[0] != '1' && k)
            {
                s[0] = '1';
                k--;
            }
            for(int i=1; i<n && k; i++)
            {
                if(s[i] != '0')
                {
                    s[i] = '0';
                    k--;
                }
            }
        }
 
        cout << s << endl;
    }
 
    return 0;
}