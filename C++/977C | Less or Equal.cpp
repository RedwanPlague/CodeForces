#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
 
#define MX 30
#define MOD 1000000007
#define pb push_back
#define br '\n'
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    int n, k;
    cin>>n>>k;
    int *a = new int[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n);
 
    if(k == 0)
    {
        if(a[0] > 1)
            cout<<a[0]-1<<br;
        else
            cout<<-1<<br;
        return 0;
    }
 
    if(k == n)
    {
        if(a[n-1] <= 1000000000)
            cout<<1000000000<<br;
        else
            cout<<-1<<br;
        return 0;
    }
 
    if(a[k-1] < a[k])
        cout<<a[k-1]<<br;
    else
        cout<<-1<<br;
 
    delete[] a;
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 