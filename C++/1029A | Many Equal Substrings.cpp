#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
 
const int MX = 30;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, k;
    cin>>n>>k;
    string t;
    cin>>t;
 
    int idx = 0;
 
    for(int i=n-2; i>=0; i--)
    {
        bool match = true;
        for(int j=0, k=n-(i+1); j<=i; j++,k++)
        {
            if(t[j] != t[k])
            {
                match = false;
                break;
            }
        }
        if(match)
        {
            idx = i+1;
            break;
        }
    }
 
    string s = "";
    while(idx<n)
    {
        s += t[idx++];
    }
 
    for(int i=1; i<k; i++)
        t += s;
 
    cout<<t<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 