#include <stdio.h>
#include <string.h>
main()
{
    char wr[101], i, l;
    scanf("%s", &wr);
    l=strlen(wr);
    for(i=0; i<l; i++) {
        if(wr[i]!='a' && wr[i]!='e' && wr[i]!='i' && wr[i]!='o' && wr[i]!='u' && wr[i]!='y' && wr[i]!='A' && wr[i]!='E' && wr[i]!='I' && wr[i]!='O' && wr[i]!='U' && wr[i]!='Y') {
            if(wr[i]>='A' && wr[i]<='Z')
                wr[i]+='a'-'A';
            printf(".%c", wr[i]);
        }
    }
    printf("\n");
}