#include <iostream>
 
#define br '\n'
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin>>n;
    int *a = new int[n];
 
    for(int i=0; i<n; i++)
        cin>>a[i];
 
    int i = 0, j = n-1;
    long long si = 0, sj = 0, ans = 0;
 
    while(i <= j)
    {
        si += a[i++];
        while(sj < si && i <= j)
            sj += a[j--];
        if(si == sj)
            ans = si;
        //cout<<si<<' '<<sj<<' '<<i<<' '<<j<<br;
    }
 
    cout<<ans<<endl;
 
    delete[] a;
    return 0;
}