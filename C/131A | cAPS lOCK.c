#include <stdio.h>
#include <string.h>
int main()
{
    int i, l;
    char s[101];
    scanf("%s", &s);
    l=strlen(s);
      for(i=1; i<l; i++)
        if(s[i]>='a' && s[i]<='z')
          break;
      if(i<l)
        printf("%s", s);
      else {
        if(s[0]>='a' && s[0]<='z')
          s[0]+='A'-'a';
        else
          s[0]+='a'-'A';
      printf("%c", s[0]);
      for(i=1; i<l; i++) {
        printf("%c", s[i]-'A'+'a');
      }
      }
    return 0;
}