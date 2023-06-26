#include <bits/stdc++.h>
using namespace std;
void add(string& s, int carry)
{
    int l = s.length();
    for(int i=l-1; i>=0; i--)
    {
        s[i] += carry;
        if(s[i]>'z')
        {
            s[i] = 'a';
            carry = 1;
        }
        else carry = 0;
    }
}
int main()
{
    string s, t;
    cin>>s>>t;
    add(s,1);
    if(s<t)
        cout<<s<<endl;
    else
        cout<<"No such string"<<endl;
 return 0;
}