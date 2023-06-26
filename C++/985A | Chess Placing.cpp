#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 30
#define MOD 1000000007
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    scanf("%d", &n);
    n /= 2;
 
    int a[105], w[105], b[105];
    memset(a, 0, sizeof(a));
    memset(w, 0, sizeof(w));
    memset(b, 0, sizeof(b));
 
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        w[i] = 2*i;
        b[i] = 2*i-1;
    }
 
    sort(a+1, a+n+1);
 
    int ans1 = 0, ans2 = 0;
 
    for(int i=1; i<=n; i++)
    {
        ans1 += abs(w[i] - a[i]);
        ans2 += abs(b[i] - a[i]);
        //cout<<a[i]<<' '<<w[i]<<' '<<b[i]<<endl;
    }
 
    cout<<min(ans1, ans2)<<endl;
 
    return 0;
}