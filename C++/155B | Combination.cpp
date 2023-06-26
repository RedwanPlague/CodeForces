#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long 
typedef struct {
    ll a;
    ll b;
} card;
bool cmp(card one, card two)
{
    if(one.b==two.b) return one.a>two.a;
    return one.b>two.b;
}
int main()
{
    int playable=1, n, i, points=0;
    cin>>n;
    card play[n];
    for(i=0; i<n; i++) cin>>play[i].a>>play[i].b;
    sort(play,play+n,cmp);
    for(i=0; i<n && playable; i++) {
        points+=play[i].a;
        playable+=play[i].b-1;
    }
    cout<<points<<endl;
    return 0;
}