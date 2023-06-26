#include <iostream>
#include <vector>
using namespace std;
 
typedef vector<int> vi;
 
void prefix_func(const vi& a, vi &pi)
{
    pi.resize(a.size());
    pi[0] = 0;
    for(int i=1; i<a.size(); i++)
    {
        int j = pi[i-1];
        while(j && a[i] != a[j])
            j = pi[j-1];
        if(a[i] == a[j])
            j++;
        pi[i] = j;
    }
}
 
int count_match(const vi &v, const vi &a, const vi& pi)
{
    int cnt = 0;
    for(int i=0, j=0; i<v.size(); i++)
    {
        while(j && v[i] != a[j])
            j = pi[j-1];
        if(v[i] == a[j])
        {
            j++;
            if(j == a.size())
            {
                cnt++;
                j = pi[j-1];
            }
        }
    }
    return cnt;
}
 
int main() 
{
 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
 int N, M;
 cin >> N >> M;
 
 if(N < M)
 {
     cout << 0 << endl;
     return 0;
 }
 if(M == 1)
 {
     cout << N << endl;
     return 0;
 }
 
 vi a(N), b(M);
 for(int i=0; i<N; i++)
     cin >> a[i];
 for(int i=0; i<M; i++)
     cin >> b[i];
 
 vi adiff(N-1), bdiff(M-1);
 for(int i=0; i<adiff.size(); i++)
     adiff[i] = a[i+1] - a[i];
 for(int i=0; i<bdiff.size(); i++)
     bdiff[i] = b[i+1] - b[i];
     
 vi pi;
 prefix_func(bdiff,pi);
 
 cout << count_match(adiff,bdiff,pi) << endl;
 
 return 0;
}