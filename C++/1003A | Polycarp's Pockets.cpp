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
 
    int a[105];
    memset(a, 0, sizeof(a));
 
    int in, n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>in;
        a[in]++;
    }
 
    int mx = 0;
    for(int i=0; i<105; i++)
        mx = max(mx, a[i]);
 
    cout<<mx<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 