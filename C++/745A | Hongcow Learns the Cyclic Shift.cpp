#include <bits/stdc++.h>
using namespace std;
map <string, int> mp;
int l;
void shift(string &t)
{
    char ch = t[l-1];
    for(int i=l-1; i>0; i--)
        t[i] = t[i-1];
    t[0] = ch;
}
int main()
{
    string s;
    cin>>s;
    l =  s.length();
    for(int i=0; i<l; i++)
    {
        shift(s);
        mp[s] = 1;
    }
    cout<<mp.size()<<endl;
    return 0;
}