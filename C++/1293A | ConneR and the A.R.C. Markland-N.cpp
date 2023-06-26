#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
 
using namespace std;
 
#define all(v) (v).begin(),(v).end()
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, s, k, l;
        cin >> n >> s >> k;
        set<int> off;
        for(int i=0; i<k; i++)
        {
            cin >> l;
            off.insert(l);
        }
        int ans = -1;
        for(int i=s; i<=n; i++)
        {
            if(!off.count(i))
            {
                ans = i-s;
                break;
            }
        }
        for(int i=s; i>0; i--)
        {
            if(!off.count(i))
            {
                if(ans == -1)
                    ans = s-i;
                else 
                    ans = min(ans,s-i);
                break;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}