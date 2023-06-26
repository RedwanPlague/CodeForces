#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
 
#define MX 200005
#define MOD 1000000007
#define pb push_back
#define br '\n'
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    int n;
    int a[MX];
    map <int, int> mp;
 
    cin>>n;
    int ans = 0, last = -1;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        mp[a[i]] = mp[a[i]-1] + 1;
        if(mp[a[i]] > ans)
        {
            ans = mp[a[i]];
            last = a[i];
        }
    }
 
    cout<<ans<<endl;
 
    vector <int> v;
 
    for(int i=n; i>0; i--)
    {
        if(a[i] == last)
        {
            v.push_back(i);
            last--;
        }
    }
 
    for(int i=v.size()-1; i>=0; i--)
        cout<<v[i]<<' ';
 
    cout<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 