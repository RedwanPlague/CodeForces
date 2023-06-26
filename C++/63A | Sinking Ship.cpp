#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string name, type, cap;
    vector <string> v1, v2, v3;
    cin>>n;
    while(n--)
    {
        cin>>name>>type;
        if(type=="rat")
            v1.push_back(name);
        else if(type=="woman" || type=="child")
            v2.push_back(name);
        else if(type=="man")
            v3.push_back(name);
        else 
            cap = name;
    }
    for(auto i: v1)
        cout<<i<<endl;
    for(auto i: v2)
        cout<<i<<endl;
    for(auto i: v3)
        cout<<i<<endl;
    cout<<cap<<endl;
    return 0;
}