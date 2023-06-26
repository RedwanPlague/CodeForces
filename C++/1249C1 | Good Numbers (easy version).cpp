#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 41
#define MOD 1'000'000'007
#define set(N,pos) (N = (1LL<<(pos)))
#define clear(N,pos) (N = (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
 
ll number(ll mask)
{
    ll pw = 1, sum = 0;
    for(int pos=0; pos<=MX; pos++)
    {
        if((mask>>pos)&1)
            sum += pw;
        pw *= 3LL;
    }
    return sum;
}
 
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
        ll n;
        cin >> n;
        ll lo = 1, hi = (1LL<<MX), mid;
        while(lo < hi-1)
        {
            mid = (lo+hi)/2;
            if(number(mid) < n)
                lo = mid+1;
            else
                hi = mid;
        }
        if(number(lo) >= n)
            cout << number(lo) << '\n';
        else
            cout << number(hi) << '\n';
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 