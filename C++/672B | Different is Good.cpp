#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l;
    string s;
    cin>>l;
    cin>>s;
    if(l>26)
    {
        puts("-1");
        return 0;
    }
    int i, dis = 0;
    int *a = (int*)calloc(26,sizeof(int));
    for(i=0; i<l; i++)
    {
        a[s[i]-'a']++;
    }
    for(i=0; i<26; i++)
        if(a[i])
            dis++;
    cout<<l-dis<<endl;
}