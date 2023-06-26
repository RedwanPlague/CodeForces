#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin>>n>>k;
    if((n/k)%2)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}