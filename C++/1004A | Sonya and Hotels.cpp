#include <bits/stdc++.h>
 
#define br '\n'
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 105;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, d;
    int a[MX];
    cin>>n>>d;
    for(int i=0; i<n; i++)
        cin>>a[i];
 
    sort(a, a+n);
 
    int cnt = 0;
    for(int i=0; i<n-1; i++)
    {
        int dis1 = a[i] + d;
        int dis2 = a[i+1] - d;
        if(dis1 == dis2)
            cnt++;
        else if(dis1 < dis2)
            cnt+=2;
    }
 
    cout<<cnt+2<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 