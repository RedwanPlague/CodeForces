#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
 
struct Each {
   string str;
   int s, h;
   Each() { s = h = 0; str = ""; }
};
 
int main()
{
   int n;
   char c = ' ';
   scanf("%d", &n);
   getchar();
   Each ar[n];
   for(int i=0; i<n; i++)
   {
      while(true)
      {
         c = getchar();
         if(c == '\n')
            break;
         if(c == 's')
            ar[i].s++;
         else if(c == 'h')
            ar[i].h++;
         ar[i].str += c;
      }
      //for(int j=0; j<ar[i].str.length(); j++)
      //   putchar(ar[i].str[j]);
   }
 
   sort(ar, ar+n, [](Each& a, Each& b) { return ((long long)a.s*b.h > (long long)b.s*a.h); });
 
   int s = 0;
   long long ans = 0;
 
   for(int i=0; i<n; i++)
   {
      for(int j=0; j<ar[i].str.length(); j++)
      {
         if(ar[i].str[j] == 's')
            s++;
         else
            ans += s;
         //putchar(ar[i].str[j]);
      }
      //putchar('\n');
   }
 
   printf("%I64d\n", ans);
 
   return 0;
}