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
#define avg first
#define cnt second
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
    cout << setprecision(10) << fixed;
    int d;
    vector<double> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> d;
        a[i] = d;
    }
    
    stack< pair<double,int> > stk;
    for(int i=n-1; i>=0; i--)
    {
        double avg = a[i];
        int cnt = 1;
        while(!stk.empty() && stk.top().avg <= avg)
        {
            avg = (avg*cnt + stk.top().avg * stk.top().cnt) / (cnt += stk.top().cnt);
            stk.pop();
        }
        stk.push({avg,cnt});
    }
 
    while(!stk.empty())
    {
        for(int i=0; i<stk.top().cnt; i++)
            cout << stk.top().avg << '\n';
        stk.pop();
    }
 
    return 0;
}