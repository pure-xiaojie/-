#include<stdio.h>
#define MAX 10000
int a[MAX+10];
int main()
{
    int n,j,g,jw=0;
    while(scanf("%d",&n)!=EOF)
    {
        int s=0;
        memset(a,0,sizeof(a));
        a[0]=1;
        int t,i;
       for(t=1;t<=n;t++)
        {
            for(i=0;i<MAX;i++)
           {
                g=a[i];
                a[i]=(g*t+jw)%10;
                jw=(g*t+jw)/10;
            }
        }
        for(j=MAX;j>=0&&a[j]==0;j--);

        for(i=0;i<=j;i++)
          if(a[i]==0)
            s++;
          else break;
       printf("%d\n",s);
   }
   return 0;
}
