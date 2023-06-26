#include <bits/stdc++.h>
using namespace std;
void print(int i) 
{
    if(i==1) puts("Vanya");
    else if(i==2) puts("Vova");
    else puts("Both");
}
int main()
{
    vector <int> v;
    v.push_back(-1);
    int i, n, hit;
    double x, y, tx, ty;
    cin>>n>>x>>y;
    int cx=0, cy=0;
    while(cx<x && cy<y) {
        tx=(cx+1)/x;
        ty=(cy+1)/y;
        if(tx<ty) {
            v.push_back(1);
            cx++;
        }
        else if(tx>ty) {
            v.push_back(2);
            cy++;
        }
        else {
            v.push_back(0);
            v.push_back(0);
            cx++; cy++;
        }
    }
    while(n--) {
        cin>>hit;
        print(v[hit%(int)(x+y)]);
    }
    return 0;
}