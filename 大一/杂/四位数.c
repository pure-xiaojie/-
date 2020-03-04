#include"stdio.h"
main()
{
    char a[4];
    while(~scanf("%s",a))
    {   int i,s=0;
        for(i=0;i<4;i++)
           {
            s+=a[i]-'0';
           printf("%c ",a[i]);
           }
        putchar('\n');
        if(s%2==0)
         printf("YES\n");
        else
         printf("NO\n");

    }
}
