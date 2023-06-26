#include <bits/stdc++.h>
 
using namespace std;
 
#define MX 35
#define MOD 1000000007
#define F first
#define S second
#define FOR(i,n) for(int i=0; i<n; i++)
#define all(v) (v).begin(),(v).end()
 
int right(int n)
{
    int pos = 20;
    while(!(n&(1<<pos)))
        pos--;
    while(pos>=0 && n&(1<<pos))
        pos--;
    return pos+1;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int x, pos, baad = 0;
    cin >> x;
    if(x%2 == 0)
        baad = -1;
    vector<int> ans;
    while((pos = right(x)) > 0)
    {
        //cout << "pos = " << pos << ", x = " << x << endl;
        ans.push_back(pos);
        x ^= (1<<pos)-1;
        if(right(x))
            x++;
    }
    cout << 2*ans.size()+baad << endl;
    FOR(i,ans.size())
        cout << ans[i] << ' ';
    cout << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 