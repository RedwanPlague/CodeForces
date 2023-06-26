#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
typedef pair<int,int> ii;
 
bool possible(const int& k, const vector<ii>& detail, int T)
{
   int start = upper_bound(detail.begin(), detail.end(), make_pair(k,0)) - detail.begin();
   //cout<<"start = "<<start<<endl;
 
   if(detail.size()-start < k)
      return false;
 
   vector <int> time;
   for(; start<detail.size(); start++)
      time.push_back(detail[start].second);
   sort(time.begin(), time.end());
 
   //cout<<"here "<<endl;
 
   for(int i=0; i<time.size(); i++)
   {
      T -= time[i];
      if(T < 0)
      {
         if(i >= k)
            return true;
         return false;
      }
   }
   //cout<<"end "<<endl;
   return true;
}
 
void whom(const int& k, const vector<ii>& real, int T)
{
   vector <ii> take;
   for(int i=0; i<real.size(); i++)
   {
      if(real[i].first >= k && real[i].second <= T)
         take.push_back(make_pair(real[i].second, i+1));
   }
   sort(take.begin(), take.end());
   for(int i=0; i<take.size() && i<k; i++)
   {
      T -= take[i].first;
      if(T < 0)
         return;
      cout<<take[i].second<<' ';
   }
   return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int n, T;
   cin>>n>>T;
   vector <ii> detail(n);
 
   for(int i=0; i<n; i++)
   {
      cin>>detail[i].first>>detail[i].second;
   }
 
   vector <ii> real(detail);
 
   sort(detail.begin(), detail.end());
 
   //cout<<real[0].first<<detail[0].first<<endl;
 
   int lo = 0, hi = n, mid;
 
   while(lo<hi-1)
   {
      mid = (lo+hi)>>1;
      if(possible(mid, detail, T))
         lo = mid;
      else
         hi = mid-1;
   }
   if(possible(hi, detail, T))
   {
      cout<<hi<<'\n'<<hi<<endl;
      whom(hi, real, T);
   }
   else
   {
      cout<<lo<<'\n'<<lo<<endl;
      whom(lo, real, T);
   }
 
   return 0;
}