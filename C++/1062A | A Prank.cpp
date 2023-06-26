#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 35;
const int MOD = 1e9+7;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    vi v(n);
    int mx = 0, cnt;
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
 
    cnt = 1;
    for(int i=1; i<n; i++)
    {
        if(v[i] == v[i-1]+1)
            cnt++;
        else
        {
            mx = max(mx,cnt);
            cnt = 1;
        }
    }
    if(cnt)
        mx = max(mx,cnt);
 
    if(v[0] == 1)
    {
        cnt = 2;
        for(int i=1; i<n; i++)
        {
            if(v[i] == v[i-1]+1)
                cnt++;
            else
            {
                mx = max(mx,cnt);
                break;
            }
        }
    }
    if(cnt)
        mx = max(mx,cnt);
 
    if(v[n-1] == 1000)
    {
        cnt = 2;
        for(int i=n-2; i>=0; i--)
        {
            if(v[i] == v[i+1]-1)
                cnt++;
            else
            {
                mx = max(mx,cnt);
                break;
            }
        }
    }
    if(cnt)
        mx = max(mx,cnt);
 
    cout << max(0,mx - 2) << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 