#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
 
#define MX 30
#define MOD 1000000007
#define pb push_back
#define br '\n'
 
bool ispow(ll n, int k)
{
    while(n%k == 0)
        n /= k;
    return (n==1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    int n;
    cin>>n;
    vector <ll> a(200);
    for(int i=0; i<n; i++)
        cin>>a[i];
 
    for(int k=0; k<n; k++) {
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i]%a[j] == 0 && ispow(a[i]/a[j], 3))
                swap(a[i], a[j]);
            else if(a[j]%a[i] == 0 && ispow(a[j]/a[i], 2))
                swap(a[i], a[j]);
        }
    } }
 
    /*bool mark[200];
    memset(mark, 0, sizeof(mark));
 
    vector <int> v;
 
    v.pb(a[0]);*/
 
 
    for(int i=n-1; i>=0; i--)
        cout<<a[i]<<' ';
    cout<<br;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 