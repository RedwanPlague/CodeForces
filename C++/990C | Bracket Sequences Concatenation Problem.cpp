#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 15;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
 
    int n;
    cin>>n;
 
    map <int,ll> mp;
 
    string s;
 
    for(int i=0; i<n; i++)
    {
        cin>>s;
        int cntl = 0, cntr = 0;
        bool l = false, r = false;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(')
                cntl++;
            else
                cntl--;
            if(cntl < 0)
                l = true;
        }
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i] == '(')
                cntr++;
            else
                cntr--;
            if(cntr > 0)
                r = true;
        }
        if(!(l && r))
            mp[cntl]++;
    }
 
    ll sum = 0;
 
    for(map <int,ll> :: iterator it = mp.begin(); it != mp.end() && it->first <= 0; it++)
    {
        sum += (it->second)*mp[-(it->first)];
        //cout<<it->first<<' ';
    }
 
    cout<<sum<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 