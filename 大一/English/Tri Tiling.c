#include <stdio.h>
int main()
{
    int m;
    int f[31];
    scanf("%d",&m);
    f[0]=1;
    f[2]=3;
    int i;
    for(i=1;i<=30;i=i+2)
        f[i]=0;
    for (i=4;i<=30;i=i+2)
        f[i]=f[i-2]*4-f[i-4];
    while (m!=-1)
    {
       printf("%d\n",f[m]);
       scanf("%d",&m);
    }

    return 0;
}
