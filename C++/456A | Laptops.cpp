#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long 
#define MOD 1000000007
typedef struct {
    int a, b;
} laptop;
 
bool cmp(laptop one, laptop two)
{
    return one.a<two.a;
}
 
int main()
{
   int i, n;
   cin>>n;
   laptop ar[n];
   for(i=0; i<n; i++) cin>>ar[i].a>>ar[i].b;
   sort(ar,ar+n,cmp);
   for(i=1; i<n; i++) if(ar[i-1].b>ar[i].b) {
       cout<<"Happy Alex"<<endl;
       return 0;
   }
   cout<<"Poor Alex"<<endl;
   return 0;
}