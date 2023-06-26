#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int a;
    string s;
    cin >> a >> s;
 
    vector<ll> sum(1+s.size());
    sum[0] = 0;
    for(int i=0; i<s.size(); i++)
    {
        sum[i+1] = sum[i] + (s[i]-'0');
    }
 
    vector<ll> cnt(40000,0);
    for(int l=1; l<=s.size(); l++)
    {
        for(int r=l; r<=s.size(); r++)
        {
            cnt[ sum[r]-sum[l-1] ]++;
        }
    }
 
    ll segs = 0;
    for(int i=1; i<cnt.size(); i++)
    {
        if(a % i == 0 && a/i < cnt.size())
        {
            segs += cnt[i]*cnt[a/i];
        }
    }
 
    if(a == 0)
    {
        segs <<= 1; // as i = 0 was never taken
        segs += cnt[0]*cnt[0];
    }
 
    cout << segs << endl;
 
    return 0;
}