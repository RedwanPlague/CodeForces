#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    long long p, q, b;
    cin>>n;
    while(n--)
    {
        cin>>p>>q>>b;
        q /= __gcd(p,q);
        while(__gcd(b,q) > 1)
        {
            b = __gcd(b,q);
            q = q / __gcd(b,q);
        }
        if(q > 1)
            cout<<"Infinite"<<'\n';
        else
            cout<<"Finite"<<'\n';
    }
    
    return 0;
}