#include <bits/stdc++.h>
using namespace std;
map <string,string> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    bool f;
    cin>>q;
    string s, t;
    while(q--)
    {
        cin>>s>>t;
        f = false;
        for(auto& i: mp)
        {
            if(i.second==s)
            {
                i.second = t;
                f = true;
                break;
            }
        }
        if(!f) 
            mp[s] = t;
    }
    cout<<mp.size()<<endl;
    for(auto i: mp)
        cout<<i.first<<' '<<i.second<<endl;
    return 0;
}