#include <stdio.h>
#include <string.h>
int main()
{
    int i,j=1,n,m,s,num,abs[100];
    scanf("%d",&n);
    while(n)
    {
        s=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&abs[i]);
            s+=abs[i];
        }
        s/=n;
        num=0;
        for(i=0; i<n; i++)
            if(abs[i]>s)
                num+=abs[i]-s;
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",j++,num);
        scanf("%d",&n);
    }

}
