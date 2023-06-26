#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 200005
#define MOD 1000000007
 
struct Horse
{
    ll hp, dmg;
    bool operator<(const Horse& other) const
    {
        return ((hp-dmg) > (other.hp-other.dmg));
    }
    ll get()
    {
        return (hp > dmg) ? hp : dmg;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
    ll n, a, b;
    cin>>n>>a>>b;
    vector <Horse> v(n);
 
    for(int i=0; i<n; i++)
    {
        cin>>v[i].hp>>v[i].dmg;
    }
 
    sort(v.begin(), v.end());
 
    ll sum = 0;
    for(int i=0; i<n; i++)
    {
        if(i < b)
            sum += v[i].get();
        else
            sum += v[i].dmg;
    }
 
    if(b == 0)
    {
        cout<<sum<<endl;
        return 0;
    }
 
    ll ans = sum;
 
    for(int i=0; i<n; i++)
    {
        ll temp = sum;
        if(i < b)
        {
            temp -= v[i].get();
            temp += (v[i].hp << a);
            ans = max(ans, temp);
        }
        else
        {
            temp -= v[i].dmg;
            temp += (v[i].hp << a);
            temp -= v[b-1].get();
            temp += v[b-1].dmg;
            ans = max(ans, temp);
        }
    }
 
    cout<<ans<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 