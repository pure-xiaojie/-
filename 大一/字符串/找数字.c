/* Note:Your choice is C IDE */
#include "stdio.h"
#include "string.h"
int main()
{
    char a[655365],b[65536];
    int i,n=1,s,j=0,t;
    while(scanf("%s",a)!=EOF)
    {
        printf("Case #%d:\n",n);
        int k = 0;
        for(i=0,j=0; i<strlen(a); i++)
            if (a[i] >= '0' && a[i] <= '9')
            {
                b[j++]=a[i];
                k = 1;
            }
            else if(k == 1)
            {
                b[j++] = ' ';
                k = 0;
            }

        b[j]=='\0';
        for(t=0; b[t]=='0'; t++);
        int s = 0;
        for(i=t; i<j;)
        {
            putchar(b[i]);
            if(b[i] == ' ')
                for(t=i+1; b[t]=='0'&&b[t+1] == '0'
                ||b[t]=='0'&&b[t+1] >= '0'&&b[t+1] <= '9'; t++)
                    s = 1;
            if(s == 1)
            {
                i=t;
                s=0;

            }
            else
                i++;
        }

        putchar('\n');
        n++;
    }
}
