#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    long long A, B, x, y, z;
    cin>>A>>B>>x>>y>>z;
    cout<<max(0LL,2*x+y-A)+max(0LL,y+3*z-B)<<endl;
    return 0;
}