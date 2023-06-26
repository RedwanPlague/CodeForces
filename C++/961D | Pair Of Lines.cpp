#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
class Frac {
   ll p, q;
public:
   Frac()
   {
      p = q = 0;
   }
   Frac(ll x1, ll y1, ll x2, ll y2)
   {
      p = y2 - y1;
      q = x2 - x1;
   }
   bool operator==(const Frac& other) const
   {
      return (p*other.q == q*other.p);
   }
   bool operator!=(const Frac& other) const
   {
      return (p*other.q != q*other.p);
   }
   bool operator<(const Frac& other) const
   {
      return (p*other.q < q*other.p);
   }
};
 
int n;
ll x[100001], y[100001];
 
bool check(int a, int b, int c)
{
   //cout<<a<<b<<c;
   Frac slope(x[a], y[a], x[b], y[b]);
   bool mark[n];
   memset(mark, 0, sizeof(mark));
   mark[a] = mark[b] = 1;
   int d = -1;
   for(int i=0, cnt = 0; i<n; i++)
   {
      if(i == a || i == b || i == c)
         continue;
      if(Frac(x[a], y[a], x[i], y[i]) == slope)
         mark[i] = 1;
      else if(cnt == 0)
      {
         d = i;
         cnt++;
      }
   }
 
   //cout<<d<<endl;
 
   if(d == -1)
      return 1;
 
   slope = Frac(x[c], y[c], x[d], y[d]);
   for(int i=0; i<n; i++)
   {
      if(!mark[i] && slope != Frac(x[c], y[c], x[i], y[i]))
         return 0;
   }
   return 1;
}
 
int main()
{
   ios_base::sync_with_stdio(0);
 
   cin>>n;
 
   if(n <= 4)
   {
      cout<<"YES"<<endl;
      return 0;
   }
 
   for(int i=0; i<n; i++)
      cin>>x[i]>>y[i];
 
   Frac slope(x[0], y[0], x[1], y[1]);
   int no = -1;
   for(int i=2; i<n; i++) // finding a point that is not co linear with point 0 and point 1
   {
      if(Frac(x[0], y[0], x[i], y[i]) != slope)
      {
         no = i;
         break;
      }
   } // now we have 3 non co linear points
 
   if(no == -1)
   {
      cout<<"YES"<<endl;
      return 0;
   }
 
   if(check(0,1,no) || check(1,no,0) || check(no,0,1))
      cout<<"YES"<<endl;
   else
      cout<<"NO"<<endl;
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 