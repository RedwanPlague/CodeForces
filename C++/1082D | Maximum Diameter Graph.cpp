#include <iostream>
#include <algorithm>
#include <vector>
 
#define F first
#define S second
 
using namespace std;
 
typedef pair<int,int> pii;
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
 
    if(n == 1)
    {
        cout << "YES 0\n0\n";
        return 0;
    }
    if(n == 2)
    {
        cout << "YES 1\n1\n1 2\n";
        return 0;
    }
 
    int sum = 0;
    vector<pii> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i].F ;
        sum += a[i].F;
        a[i].S = i+1;
    }
 
    if(sum < 2*(n-1))
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES ";
 
    sort(a.begin(), a.end());
 
    int start = 0;
    while(a[start].F == 1)
        start++;
 
    int one = start;
    int diam = n - 1; // diameter
    if(one > 2)
        diam -= one - 2; // only 2 ones can be used to form the chain, the rest are not counted
 
    cout << diam << '\n' << n-1 << '\n';
 
    if(!start)
        start++;
    for(int i=start; i<n; i++)
    {
        cout << a[i-1].S << ' ' << a[i].S << '\n';
        a[i-1].F--;
        a[i].F--;
    }
 
    int limit = start-1;
    int cur_use = n-1;
    for(int i=0; i<limit; i++)
    {
        while(!a[cur_use].F)
            cur_use--;
        cout << a[i].S << ' ' << a[cur_use].S << '\n';
        a[cur_use].F--;
    }
 
    return 0;
}