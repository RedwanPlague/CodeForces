#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 35
#define MOD 1'000'000'007
#define set(N,pos) (N = (1LL<<(pos)))
#define clear(N,pos) (N = (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
 
int main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int l, r;
    cin >> l >> r;
 
    int x;
    int ar[5];
    for(int i1=0; i1<10; i1++)
    {
        ar[0] = i1;
        do{
            int x = ar[0];
            if(l<=x && x<=r)
            {
                cout << x << endl;
                return 0;
            }
        }
        while(next_permutation(ar,ar+1));
        for(int i2=i1+1; i2<10; i2++)
        {
            ar[0] = i1; ar[1] = i2;
            do{
                int x = ar[0]*10+ar[1];
                if(l<=x && x<=r)
                {
                    cout << x << endl;
                    return 0;
                }
            }
            while(next_permutation(ar,ar+2));
            for(int i3=i2+1; i3<10; i3++)
            {
                ar[0] = i1; ar[1] = i2; ar[2] = i3;
                do{
                    int x = ar[0]*100+ar[1]*10+ar[2];
                    if(l<=x && x<=r)
                    {
                        cout << x << endl;
                        return 0;
                    }
                }
                while(next_permutation(ar,ar+3));
                for(int i4=i3+1; i4<10; i4++)
                {
                    ar[0] = i1; ar[1] = i2; ar[2] = i3; ar[3] = i4;
                    do{
                        int x = ar[0]*1000+ar[1]*100+ar[2]*10+ar[3];
                        if(l<=x && x<=r)
                        {
                            cout << x << endl;
                            return 0;
                        }
                    }
                    while(next_permutation(ar,ar+4));
                    for(int i5=i4+1; i5<10; i5++)
                    {
                        ar[0] = i1; ar[1] = i2; ar[2] = i3; ar[3] = i4; ar[4] = i5;
                        do{
                            int x = ar[0]*10000+ar[1]*1000+ar[2]*100+ar[3]*10+ar[4];
                            if(l<=x && x<=r)
                            {
                                cout << x << endl;
                                return 0;
                            }
                        }
                        while(next_permutation(ar,ar+5));
                    }
                }
            }
        }
    }
 
    cout << -1 << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 