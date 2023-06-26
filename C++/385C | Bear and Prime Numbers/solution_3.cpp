#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
 
#define MX 10000020
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, x;
    cin >> n;
    vector<int> cnt(MX,0);
    for(int i=0; i<n; i++)
    {
        cin >> x;
        cnt[x]++;
    }
 
    vector<bool> mark(MX,0);
    vector<ll> sum(MX,0);
    for(int i=2; i<MX; i+=2)
        sum[2] += cnt[i];
 
    for(int i=3; i<MX; i+=2)
    {
        if(!mark[i])
        {
            for(int j=i; j<MX; j+=i)
            {
                sum[i] += cnt[j];
                mark[j] = 1;
            }
        }
    }
 
    for(int i=1; i<MX; i++)
        sum[i] += sum[i-1];
 
    int m, l, r;
    cin >> m;
    while(m--)
    {
        cin >> l >> r;
        if(l >= MX)
            l = MX-1;
        if(r >= MX)
            r = MX-1;
        cout << sum[r] - sum[l-1] << '\n';
    }
 
    return 0;
}