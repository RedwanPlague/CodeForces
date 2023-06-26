#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
typedef pair<int,int> pii;
 
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pii> pr(n);
        for(int i=0; i<n; i++)
            cin >> pr[i].F >> pr[i].S;
        sort(all(pr));
        
        string path;
        pii cur = {0,0};
        bool ok = true;
        int r, u;
        for(pii &p: pr)
        {
            if(p.S < cur.S)
            {
                ok = false;
                break;
            }
            r = p.F - cur.F;
            u = p.S - cur.S;
            for(int i=0; i<r; i++)
                path += 'R';
            for(int i=0; i<u; i++)
                path += 'U';
            cur = p;
        }
        if(ok)
            cout << "YES\n" << path << '\n';
        else 
            cout << "NO\n";
    }
    
    return 0;
}