#include"stdio.h"
#include"math.h"
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a[5],i;
        float average=0,cha=0,sum=0;
        for(i=0;i<5;i++)
        {

           scanf("%d",&a[i]);
           sum+=a[i];
        }

        average=sum/5;
        for(i=0;i<5;i++)
         cha+=(a[i]-average)*(a[i]-average);
        printf("%.3f %.3f\n",average,sqrt((cha/5)));


    }
}


