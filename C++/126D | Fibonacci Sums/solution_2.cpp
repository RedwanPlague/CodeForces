#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
#define br '\n'
 
const ll mx = round(1e18); // round needed for floating point error :3
const int limit = 85; // fib[86] is > 1e18
 
ll fib[100];
 
void make()
{
    fib[0] = 1;
    fib[1] = 2;
    for(int i = 2; i <= limit; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        //cout<<fib[i]<<' ';
    }
}
 
void decompose(ll N, vector<int> &v)
{
    int cnt = -100;
    for(int i = limit; i >= 0; i--)
    {
        if(fib[i] <= N)
        {
            N -= fib[i];
            if(cnt > 0)
                v.push_back(cnt);
            cnt = 1;
        }
        else
            cnt++;
    }
    if(cnt > 0)
        v.push_back(cnt);
    /*for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<br;*/
    v.push_back(0); // dummy data, to make the vector 1 indexed
    reverse(v.begin(), v.end());
}
 
ll ways(const ll &N)
{
    vector <int> v;
    decompose(N, v);
    int k = v.size() - 1; // there are k 1-bits in N, subtracting 1 because of that dummy data
    vector <ll> dp1(v.size(), 0), dp2(v.size(), 0);
    dp1[0] = 1;
    dp2[0] = 0;
    for(int i=1; i<v.size(); i++)
    {
        dp1[i] = dp1[i-1] + dp2[i-1];
        dp2[i] = ((v[i]-1)/2) * dp1[i-1] + (v[i]/2) * dp2[i-1];
    }
    return dp1[k] + dp2[k];
}
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
    make();
 
    int T;
    ll N;
 
    cin>>T;
 
    while(T--)
    {
        cin>>N;
        cout<<ways(N)<<br;
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 