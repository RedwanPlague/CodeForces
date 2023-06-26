#include <bits/stdc++.h>
using namespace std;
map <string, int> mp;
comp(const pair<string,int> &p1, const pair<string,int> &p2)
{
    return p1.second < p2.second; 
}
int main()
{
    int n;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s;
        mp[s]++;
    }
    auto i = max_element(mp.begin(), mp.end(), comp);
    cout<<i->first<<endl;
    return 0;
}