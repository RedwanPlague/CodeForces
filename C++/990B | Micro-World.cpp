#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 15;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
 
    int n, K, a;
    cin>>n>>K;
 
    vector <int> v;
    map <int,int> mp;
 
    for(int i=0; i<n; i++)
    {
        cin>>a;
        if(mp.count(a) == 0)
        {
            v.push_back(a);
        }
        mp[a]++;
    }
 
    sort(v.begin(), v.end());
 
    int eat = 0;
 
    for(int i=1; i<v.size(); i++)
    {
        if(v[i] > v[i-1] && v[i] <= v[i-1] + K)
            eat += mp[v[i-1]];
    }
 
    cout<<n-eat<<endl;
 
    return 0;
}