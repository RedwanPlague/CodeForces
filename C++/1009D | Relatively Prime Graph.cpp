#include <bits/stdc++.h>
 
#define br '\n'
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin>>n>>m;
    
    if(m < n-1)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
 
    int sum = 0;
 
    vector < pair<int,int> > ans;
 
    for(int i=2; i<=n && sum < m; i++)
    {
        ans.push_back(make_pair(1,i));
        sum++;
    }
 
    for(int i=2; i<=n && sum < m; i++)
    {
        for(int j=2; j<i && sum < m; j++)
        {
            if(__gcd(i,j) == 1)
            {
                ans.push_back(make_pair(i,j));
                sum++;
            }
        }
    }
 
    if(sum < m)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
 
    cout<<"Possible\n";
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i].first<<' '<<ans[i].second<<br;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 