#include <bits/stdc++.h>
using namespace std;
 
struct Student {
   int l, r, idx;
   Student (int l, int r, int idx)
   {
      this->l = l; this->r = r; this->idx = idx;
   }
};
 
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
   int T, n, l, r, time;
   int when[1001];
   vector<Student> lr;
   cin>>T;
   while(T--)
   {
      cin>>n;
      for(int i=0; i<n; i++)
      {
         cin>>l>>r;
         lr.push_back(Student(l,r,i));
      }
      time = 0;
      while(!lr.empty())
      {
         time++;
         if(time >= lr.front().l)
         {
            when[lr.front().idx] = time;
            lr.erase(lr.begin());
         }
         for(int i=0; i<lr.size(); i++)
         {
            if(time == lr[i].r)
            {
               when[lr[i].idx] = 0;
               lr.erase(lr.begin() + (i--));
            }
         }
      }
      for(int i=0; i<n; i++)
         cout<<when[i]<<' ';
      cout<<'\n';
   }
 
   return 0;
}
 