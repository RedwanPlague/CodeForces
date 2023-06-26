#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
 
#define MX 30
#define MOD 1000000007
#define pb push_back
#define br '\n'
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    int n;
    string s, ans = "--";
    int maxS = 0;
    cin>>n>>s;
 
    for(int i=0; i<n-1; i++)
    {
        int cnt = 0;
        for(int j=i; j<n-1; j++)
            if(s[j] == s[i] && s[j+1] == s[i+1])
                cnt++;
        //cout<<cnt<<' ';
        if(cnt > maxS)
        {
            ans[0] = s[i];
            ans[1] = s[i+1];
            maxS = cnt;
        }
    }
 
    cout<<ans<<br;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 