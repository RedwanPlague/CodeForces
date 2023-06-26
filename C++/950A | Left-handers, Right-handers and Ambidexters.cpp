#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int l, r, a;
    int team;
    cin>>l>>r>>a;
    team = min(l,r) + min(a,max(l,r)-min(l,r));
    a = max(0,a-max(l,r)+min(l,r));
    team += a/2;
    cout<<2*team<<endl;
    return 0;
}