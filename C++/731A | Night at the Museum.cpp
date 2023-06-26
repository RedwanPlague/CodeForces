#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l = s.length(),
    i, dis, rot = 0;
    char ptr = 'a';
    for(i=0; i<l; i++)
    {
        dis = abs(s[i]-ptr);
        rot += min(dis, 26-dis);
        ptr = s[i];
    }
    cout<<rot<<endl;
    return 0;
}