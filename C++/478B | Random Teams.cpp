#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
 
int main()
{
    ll n, m;
    cin>>n>>m;
    ll sg, lg, sn, ln;
    sg=n/m;
    ln=n%m;
    sn=m-ln;
    lg=sg+1;
    ll kmin = sn*(sg*(sg-1))/2+ln*(lg*(lg-1))/2; 
    ll kmax = ((n-m)*(n-m+1))/2;
    cout<<kmin<<' '<<kmax<<endl;
    return 0;
}