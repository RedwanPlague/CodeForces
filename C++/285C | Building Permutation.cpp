#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
int main() 
{
    ll N, a;
    
    cin >> N;
    vector <bool> mark(N+1,0);
    vector <ll> change;
    
    for(int i=0; i<N; i++)
    {
        cin >> a;
        if(a >= 1 && a <= N && !mark[a])
        {
            mark[a] = 1;
        }
        else
        {
            change.push_back(a);
        }
    }
    
    sort(change.begin(), change.end());
    
    ll ans = 0;
    for(int i=1, j=0; i<=N; i++)
    {
        if(!mark[i])
        {
            ans += abs(i-change[j++]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 