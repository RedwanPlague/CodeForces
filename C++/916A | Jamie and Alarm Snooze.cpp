#include <iostream>
using namespace std;
 
bool check(int n)
{
    return (n%10 == 7 || n/10 == 7);
}
 
int main()
{
    int x, h, m, y;
    cin>>x>>h>>m;
    for(y=0; y<2401; y++)
    {
        if(check(h) || check(m)) break;
 
        if(m<x)
        {
            m = (m+60-x)%60;
            h = (h+23)%24;
        }
        else
        {
            m -= x;
        }
    }
    cout<<y<<endl;
    return 0;
}