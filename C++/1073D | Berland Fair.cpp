#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 105;
const int MOD = 1e9+7;
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    int n;
    ll T;
    cin >> n >> T;
    vector<ll> a(n);
    priority_queue <ll> que;
    ll sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        sum += a[i];
        que.push(a[i]);
    }
 
    ll candy = 0;
    while(!que.empty())
    {
        while(!que.empty() && que.top() > T)
        {
            sum -= que.top();
            que.pop();
        }
        if(sum == 0)
            break;
        if(T < sum)
        {
            for(int i=0; i<n; i++)
            {
                if(a[i] <= T)
                {
                    T -= a[i];
                    candy++;
                }
            }
            continue;
        }
        candy += (ll)que.size()*(T/sum);
        T %= sum;
    }
 
    cout << candy << endl;
 
    return 0;
}