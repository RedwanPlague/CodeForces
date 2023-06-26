#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef vector<int> vi;
 
int lis(vi &v)
{
 if (v.size() == 0)
  return 0;
 
 vi tail;
 
 tail.push_back(v[0]);
 for (size_t i = 1; i < v.size(); i++) {
 
  if (v[i] < tail[0])
        {
            tail[0] = v[i];
        }
        else if (v[i] > tail.back())
        {
            tail.push_back(v[i]);
        }
  else
        {
            auto it = upper_bound(tail.begin(), tail.end(), v[i]);
            *it = v[i];
        }
 }
 
 return tail.size();
}
 
int main()
{
 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
 int n;
 cin >> n;
 
 vi a(n);
 
 for(int i=0; i<n; i++)
        cin >> a[i];
 
    cout << lis(a) << endl;
 
 return 0;
}