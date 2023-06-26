#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
 
typedef long long ll;
 
#define PRM 1000001
 
bool made[PRM];
vector <int> prime;
vector < vector<int> > dv(PRM);
 
void sieve()
{
   int primeNum = sqrt(PRM) + 10; //  +10 -> to get one extra prime ( 1009 )
 
   bool mark[primeNum];
   memset(mark, 0, sizeof(mark));
 
   prime.push_back(2);
   for(int i=3; i<primeNum; i+=2)
   {
      if(mark[i]) continue;
 
      prime.push_back(i);
 
      for(int j=i*i; j<primeNum; j+=2*i)
         mark[j] = 1;
   }
}
 
void make(int p)
{
   int subs = p;
   for(int i=0; i<prime.size() && prime[i]<=sqrt(subs+1); i++)
   {
      if(subs%prime[i] == 0)
      {
         dv[p].push_back(prime[i]);
         while(subs%prime[i] == 0)
            subs /= prime[i];
      }
   }
   if(subs > 1)
      dv[p].push_back(subs);
   made[p] = 1;
}
 
long long coprime(int p, long long x)
{
   long long coprm = x;
   int limit = (1 << dv[p].size());
 
   for(int mask = 1; mask < limit; mask++)
   {
      int cnt = 0;
      ll divide = 1LL;
      for(int i=0; i<dv[p].size(); i++)
      {
         if(mask&(1<<i))
         {
            cnt++;
            divide *= dv[p][i];
         }
      }
      if(cnt&1)
         coprm -= x/divide;
      else
         coprm += x/divide;
   }
 
   return coprm;
}
 
int main()
{
   int T, x, p, k;
 
   sieve();
 
   scanf("%d", &T);
   while(T--)
   {
      scanf("%d %d %d", &x, &p, &k);
      ll lo = 1LL, hi = (1LL<<60), mid;
      if(!made[p])
         make(p);
      ll check = coprime(p, x) + k;
      while(lo<hi-1)
      {
         mid = (lo+hi)>>1;
         if(coprime(p, mid) < check)
            lo = mid+1;
         else
            hi = mid;
      }
      if(coprime(p, lo) >= check)
         printf("%I64d\n", lo);
      else
         printf("%I64d\n", hi);
   }
   return 0;
}