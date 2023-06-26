#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
 
#define MX 10000020
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
vi prime;
 
void sieve()
{
    int limit = sqrt(MX+1);
    vector<bool> mark(MX,0);
    prime.push_back(2);
    for(int i=3; i<MX; i+=2)
    {
        if(!mark[i])
        {
            prime.push_back(i);
            if(i < limit)
                for(int j=i*i; j<MX; j+=(i<<1))
                    mark[j] = 1;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    sieve();
 
    int n, x, temp;
    cin >> n;
 
    vector<ll> sum(prime.size()+1,0);
 
    for(int i=0; i<n; i++)
    {
        cin >> x;
        temp = x;
        for(int i=0; prime[i]*prime[i]<=temp; i++)
        {
            if(temp % prime[i] == 0)
            {
                sum[i+1]++;
                while(temp % prime[i] == 0)
                    temp /= prime[i];
            }
        }
        if(temp>1)
        {
            int idx = lower_bound(prime.begin(), prime.end(), temp) - prime.begin();
            sum[idx+1]++;
        }
    }
 
    for(int i=1; i<sum.size(); i++)
        sum[i] += sum[i-1];
 
    int m, l, r;
    cin >> m;
    while(m--)
    {
        cin >> l >> r;
        int l1 = lower_bound(prime.begin(), prime.end(), l) - prime.begin();
        int r1 = upper_bound(prime.begin(), prime.end(), r) - prime.begin();
        cout << sum[r1] - sum[l1] << '\n';
    }
 
    return 0;
}