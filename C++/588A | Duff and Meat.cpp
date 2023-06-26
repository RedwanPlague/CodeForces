#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a, p;
    int minPrice = (1<<30);
    long long Cost = 0;
    for(int i=0; i<n; i++)
    {
        cin>>a>>p;
        minPrice = min(minPrice,p);
        Cost += (a*minPrice);
    }
    cout<<Cost<<endl;
    return 0;
}