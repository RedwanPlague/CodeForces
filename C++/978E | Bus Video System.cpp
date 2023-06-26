#include <iostream>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
#define br '\n'
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    int w, cur, in, mx, mn;
    
    cin>>n>>w;
    
    cur = 0, mx = 0, mn = 1000000007;
    
    for(int i=0; i<n; i++)
    {
        cin>>in;
        cur += in;
        mx = max(mx, cur);
        mn = min(mn, cur);
    }
    
    int ans;
    
    ans = max(0,w - mx + min(0,mn) + 1);
    
    cout<<ans<<endl;
    
    return 0;
}