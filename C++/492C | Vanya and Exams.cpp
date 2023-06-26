#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long 
typedef struct {
    ll a;
    ll b;
} mark;
bool cmp(mark one, mark two) 
{
    return one.b<two.b;
}
int main()
{
    ll i, n, r, avg, essay=0, diff;
    cin>>n>>r>>avg;
    mark gr[n];
    ll S=0;
    for(i=0; i<n; i++) {
        cin>>gr[i].a>>gr[i].b;
        S+=gr[i].a;
    }
    sort(gr,gr+n,cmp);
    for(i=0; i<n && S<n*avg; i++) {
        diff=min(n*avg-S,r-gr[i].a);
        essay+=diff*gr[i].b;
        S+=diff;
    }
    cout<<essay<<endl;
    return 0;
}