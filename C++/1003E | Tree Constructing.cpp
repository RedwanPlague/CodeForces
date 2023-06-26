#include <bits/stdc++.h>
using namespace std;
 
#define br '\n'
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 105;
const int MOD = 1000000007;
 
struct Data {
    int node, more, hand;
};
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, d, k;
    cin>>n>>d>>k;
    vector <pii> ans;
    vector <Data> use;
 
    if(d+1>n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if((k == 1 && d > 1) || (k == 2 && n > d+1))
    {
        cout<<"NO"<<endl;
        return 0;
    }
 
    for(int i=1; i<=d; i++)
    {
        ans.pb(pii(i,i+1));
    }
 
    for(int i=2; i<=d; i++)
        use.pb({i,min(i-1,d-i+1),2});
 
    int taken = d+1, need = 3;
 
    while(taken < n && need <= k)
    {
        for(int i=0; i<use.size(); i++)
        {
            for(int j=use[i].hand; j<need && taken<n; j++)
            {
                use[i].hand++;
                ans.pb(pii(use[i].node, ++taken));
                if(use[i].more > 1)
                    use.pb({taken,use[i].more-1,1});
            }
        }
        need++;
    }
 
    if(taken < n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
 
    cout<<"YES"<<br;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].first<<' '<<ans[i].second<<br;
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 