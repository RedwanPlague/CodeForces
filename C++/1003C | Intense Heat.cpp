#include <bits/stdc++.h>
using namespace std;
 
#define br '\n'
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 105;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, k;
    cin>>n>>k;
    int a[5005];
    a[0] = 0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i] += a[i-1];
    }
 
    double mx = 0.0;
 
    for(int l=1; l<=n; l++)
    {
        for(int r=l+k-1; r<=n; r++)
        {
            mx = max(mx, (a[r]-a[l-1]+0.0)/(r-l+1));
        }
    }
 
    cout<<fixed<<setprecision(10)<<mx<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 