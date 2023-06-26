#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false); cout.tie(false);
    
    int n;
    cin>>n;
    int *a = new int[n];
    
    int gcd = 0;
    
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        gcd = __gcd(gcd, a[i]);
    }
    
    if(gcd != a[0])
    {
        cout<<-1<<endl;
        return 0;
    }
    
    cout<<2*n-1<<endl;
    for(int i=0; i<n-1; i++)
        cout<<a[i]<<' '<<a[0]<<' ';
    cout<<a[n-1]<<endl;
    
    delete[] a;
    
    return 0;
}