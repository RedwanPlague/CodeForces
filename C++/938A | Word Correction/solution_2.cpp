#include <cstdio>
 
#define is_vowel(c) (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y')
 
int main()
{
   int n;
   scanf("%d", &n);
   char prev = 'b', read;
   getchar();
   for(int i=0; i<n; i++)
   {
      read = getchar();
      if(is_vowel(prev))
      {
         if(!is_vowel(read))
         {
            putchar(read);
            prev = read;
         }
      }
      else
      {
         putchar(read);
         prev = read;
      }
   }
   putchar('\n');
   return 0;
}