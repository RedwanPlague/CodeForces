#include <iostream>
#include <vector>
 
using namespace std;
 
bool allsame(const vector<int> &v)
{
 for(int i=1; i<v.size(); i++)
  if(v[i] != v[i-1])
   return false;
 return true;
}
 
int sameindex(const vector<int> &v)
{
 for(int i=1; i<v.size(); i++)
  if(v[i] == v[i-1])
   return i;
 return -1;
}
 
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 
 int T;
 cin >> T;
 while(T--)
 {
  int n;
  cin >> n;
  vector<int> type(n);
  for(int i=0; i<n; i++)
   cin >> type[i];
  if(allsame(type))
  {
   cout << "1\n";
   for(int i=0; i<n; i++)
    cout << "1 ";
   cout << '\n';
  }
  else 
  {
   if(n % 2 == 0 || type[0] == type.back())
   {
    cout << "2\n";
    for(int i=0, color=1; i<n; i++, color = 3-color)
     cout << color << ' ';
    cout << '\n';
   }
   else
   {
    int idx = sameindex(type);
    if(idx != -1)
    {
     cout << "2\n";
     int color = 1;
     for(int i=0; i<idx; i++, color = 3-color)
      cout << color << ' ';
     color = 3 - color;
     for(int i=idx; i<n; i++, color = 3-color)
      cout << color << ' ';
     cout << '\n';
    }
    else
    {
     cout << "3\n3";
     for(int i=1, color=1; i<n; i++, color = 3-color)
      cout << ' ' << color;
     cout << '\n'; 
    }
   }
  }
 }
 
 return 0;
}