#include <bits/stdc++.h>
using namespace std;
 
#define br '\n'
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 105;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int a, b, x;
    cin>>a>>b>>x;
 
    if(x&1)
    {
        string s = "0";
        a--;
        for(int i=1; i<=x; i++)
        {
            if(i&1)
            {
                s += "1";
                b--;
            }
            else
            {
                s += "0";
                a--;
            }
        }
        while(a--)
        {
            s = "0" + s;
        }
        while(b--)
        {
            s += "1";
        }
        cout<<s<<endl;
    }
    else
    {
        string s = "";
        for(int i=0; i<x/2; i++)
            s += "10";
        a -= x/2;
        b -= x/2;
        if(a > 0)
        {
            while(b--)
                s = "1" + s;
            while(a--)
                s = "0" + s;
        }
        else
        {
            while(a--)
                s += "0";
            while(b--)
                s += "1";
        }
        cout<<s<<endl;
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 