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
    ll a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    ll table = min((a[0]+a[1]+a[2])/3,(a[0]+a[1]));
    cout<<table<<endl;
    return 0;
}