#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, l = 0;
    string s;
    set <string> st;
    cin>>n;
    while(n--)
    {
        cin>>s;
        st.insert(s);
        if(st.size()>l)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
        l = st.size();
    }
    return 0;
}