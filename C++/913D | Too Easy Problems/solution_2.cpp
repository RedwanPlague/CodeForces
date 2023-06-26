#include <iostream>
#include <algorithm>
using namespace std;
 
struct Exam {
   int atleast, time, serial;
};
 
void decide(int& ans, const int& two, const int& n, const int& Total, const Exam exam[])
{
   int taken = 0;
   for(int i=0, time=0; i<n && (time+exam[i].time)<=Total && taken<ans+two; i++)
   {
      if(exam[i].atleast >= ans + two)
      {
         time += exam[i].time;
         taken++;
         if(!two)
            cout<<exam[i].serial<<' ';
      }
   }
   if(taken == ans + two)
      ans += two;
}
 
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
   int n, Total, two, ans = 0;
   cin>>n>>Total;
   Exam exam[n];
   for(int i=0; i<n; i++)
   {
      cin>>exam[i].atleast>>exam[i].time;
      exam[i].serial = i+1;
   }
 
   sort(exam, exam+n, [](Exam& a, Exam& b) { return a.time<b.time; }); // sort ascending by time
 
   two = (1<<17);
   while(two>n) two >>= 1;
 
   for(; two; two >>= 1) decide(ans, two, n, Total, exam);
 
   cout<<ans<<'\n'<<ans<<'\n';
 
   decide(ans, two, n, Total, exam);
 
   cout<<endl;
 
   return 0;
}
 
 
 
 
 
 
 