#include <bits/stdc++.h>
 
using namespace std;
 
#define br '\n'
#define inv(ch) ((ch == '+') ? '*' : '+')
 
string invstr(const string &s)
{
 string ret;
 for(int i=0; i<s.size(); i++)
  ret += inv(s[i]);
 return ret;
}
 
bool ortho(const string &s1, const string &s2)
{
 if(s1.size() != s2.size())
  return false;
 int dot = 0;
 for(int i=0; i<s1.size(); i++)
 {
  dot += (s1[i] == s2[i] ? +1 : -1);
 }
 return (dot == 0);
}
 
bool check(const vector<string> &v)
{
 for(int i=0; i<v.size(); i++)
 {
  for(int j=i+1; j<v.size(); j++)
  {
   if(!ortho(v[i],v[j]))
    return false;
  }
 }
 return true;
}
 
int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
#endif
 
 int k;
 while(cin >> k)
 {
  vector<string> v;
  v.push_back("+");
  for(int i=0; i<k; i++)
  {
   int sz = v.size();
   for(int j=0; j<sz; j++)
    v.push_back(v[j]);
   for(int j=0; j<sz; j++)
    v[j] += v[j];
   for(int j=0; j<sz; j++)
    v[j+sz] += invstr(v[j+sz]);
  }
  // cout << check(v) << br;
  for(auto &s: v)
   cout << s << br;
 }
}