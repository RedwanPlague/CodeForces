#include <iostream>
using namespace std;
int main()
{
    int n, m, b;
    cin>>n>>m;
    for(b=n/2; b>=0; b--)
    {
        if((n-b)%m==0)
            break;
    }
    if(b<0)
        cout<<b<<endl;
    else
        cout<<n-b<<endl;
    return 0;
}