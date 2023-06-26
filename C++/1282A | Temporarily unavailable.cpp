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
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        if(a > b)
            swap(a,b);
        if(a <= c && c <= b)
        {
            cout << max(c-r,a) - a + b - min(c+r,b) << '\n';
        }
        else if(c < a)
        {
            cout << max(0,b - max(c+r,a)) << '\n';
        }
        else
        {
            cout << max(0,min(c-r,b) - a) << '\n';
        }
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 