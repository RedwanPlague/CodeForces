#include <bits/stdc++.h>
using namespace std;
map <char, int> mp;
int main()
{
    int k;
    string s;
    cin>>k>>s;
    int i, l = s.length();
    for(i=0; i<l; i++)
        mp[s[i]]++;
    s = "";
    for(auto i: mp)
    {
        if(i.second%k==0)
        {
            i.second /= k;
            while(i.second--)
                s += i.first;
        }
        else
        {
            puts("-1");
            return 0;
        }
    }
    while(k--)
        cout<<s;
    cout<<endl;
    return 0;
}