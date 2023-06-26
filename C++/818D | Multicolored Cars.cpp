#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int color[1000001], take[1000001];
int main()
{
   //freopen("input.txt", "r", stdin);
   int n, a;
   cin>>n>>a;
   vector <int> v;
   vector <int> :: iterator it;
   int i, car[n];
   for(i=0; i<n; i++) {
      scanf("%d", &car[i]);
   }
   for(i=0; i<n && car[i]!=a; i++) {
      if(take[car[i]]!=1) v.push_back(car[i]);
      take[car[i]]=1;
   }
   for(i=0; i<n; i++) {
      color[car[i]]++;
      if(car[i]==a) break;
   }
   for(i++; i<n; i++) {
      color[car[i]]++;
      if(car[i]==a) {
      for(it=v.begin(); it<v.end(); ) {
         if(color[*it]<color[a]) {
            v.erase(it);
         }
         else it++;
      }
      /*for(it=v.begin(); it<v.end(); it++) printf("%d ", *it);
      putchar('\n');*/
      }
   }
   if(v.empty()) {
      puts("-1");
      return 0;
   }
   cout<<*v.begin()<<endl;
   return 0;
}