#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 31;
const int MOD = 1000000007;
 
#define pb push_back
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
 
    set <int> st;
 
    int n, a;
 
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        if(a)
            st.insert(a);
    }
 
    cout<<st.size()<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 