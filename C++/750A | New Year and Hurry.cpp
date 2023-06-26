#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long 
#define M 1000000007
 
int main()
{
    int n, k;
    cin>>n>>k;
    int time=240-k, solve=1;
    while(solve<=n) {
        if(time-5*solve<0) break;
        time-=5*solve;
        solve++;
    }
    cout<<solve-1<<endl;
    return 0;
}