#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max(a,b) ((a>b)?a:b)
int main()
{
    int n, k, m, elig=0;
    cin>>n>>k;
    k=5-k;
    while(n--) {
        cin>>m;
        if(m<=k) elig++;
    }
    int ans = elig/3;
    cout<<ans<<endl;
    return 0;
}