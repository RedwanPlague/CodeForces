#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
 
const int MX = 30;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin>>n;
    vi a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    int mx = 1, i = 0, cnt;
    while(i<n-1)
    {
        cnt = 1;
        while(i < n-1 && a[i+1] <= 2*a[i])
        {
            cnt++;
            i++;
        }
        mx = max(mx, cnt);
        i++;
    }
 
    cout<<mx<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 