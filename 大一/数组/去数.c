#include"stdio.h"
#include"math.h"
main()
{
    int n,m,a[101],i,j;
    while(~scanf("%d%d",&n,&m))
    {
        int s=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
          for(j=i+1;j<n;j++)
          {
            int t=a[i]-a[j];
            if(abs(t)>m&&a[j])
              {
                s++;
                if(t>0)
                  break;
                else
                  a[j]=0;
              }
          }
     printf("%d",s);
    }
return 0;
}
