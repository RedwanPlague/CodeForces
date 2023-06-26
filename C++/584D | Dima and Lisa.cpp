#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long 
#define M 1000000007
 
int isprime(int p)
{
    if(p<2) return 0;
    if(p==2) return 1;
    if(p%2==0) return 0;
    int i, lim = sqrt(p+1.0);
    for(i=3; i<=lim; i+=2) if(p%i==0) return 0;
    return 1;
}
 
int main()
{
    int n, k=1;
    cin>>n;
    if(isprime(n)) {
        puts("1");
        cout<<n<<endl;
        return 0;
    }
    int p1;
    for(p1=n-1; !isprime(p1); p1--) {}
    k++;
    if(isprime(n-p1)) {
        cout<<k<<endl;
        cout<<p1<<' '<<n-p1<<endl;
        return 0;
    }
    int p2;
    for(p2=2; !isprime(n-p1-p2) || !isprime(p2); p2++) {}
    k++;
    cout<<k<<endl;
    cout<<p1<<' '<<p2<<' '<<n-p1-p2<<endl;
    return 0;
}