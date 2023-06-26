#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    int push = 0;
    while(m>n)
    {
        if(m%2)
            m++;
        else
            m /= 2;
        push++;
    }
    push += (n-m);
    cout<<push<<endl;
    return 0;
}