/* Note:Your choice is C IDE */
#include <stdio.h>
#include <string.h>
int main()
{   char CH[3001],k,s,b;
    int i=0,f;
    gets(CH);
    scanf("%c %c",&k,&s);
        if(k>s)
        {b=k;k=s;s=b;}
    while(CH[i]!='\0')
    {
        while(CH[i]<k||CH[i]>s)

            i++;
        if(CH[i]>=k&&CH[i]<=s)
        {
            f=i;
            f++;
            while(CH[f]!='\0')
            {if(CH[f]>=k&&CH[f]<=s)
                if(CH[f]>CH[i])
                 b=CH[i],CH[i]=CH[f],CH[f]=b;
             f++;
            }
        }
        i++;
    }

    puts(CH);
return 0;
}
