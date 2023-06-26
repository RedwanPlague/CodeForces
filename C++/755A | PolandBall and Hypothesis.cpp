#include <iostream>
#include <cmath>
using namespace std;
#define MX 1000007
int prime[MX];
void sieve()
{
    int limit = sqrt(MX);
    prime[1] = 1;
    for(int i=4; i<MX; i+=2)
        prime[i] = 1;
    for(int i=3; i<MX; i+=2)
    {
        if(!prime[i])
        {
            if(i<limit)
            for(int j=i*i; j<MX; j += 2*i)
                prime[j] = 1;
        }
    }
}
int main()
{
    sieve();
    int n, m;
    cin>>n;
    for(m=1; m<=1000; m++)
        if(prime[n*m+1])
            break;
    cout<<m<<endl;
    return 0;
}