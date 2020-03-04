#include"stdio.h"
main()
{
    int a[100],n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    int j,t=0,k=0;
    for(i=0;i<n-1;i++)
     {
      for(j=0;j<n-i-1;j++)
        if(a[j]>a[j+1])
        {
            int temp;
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            k++;
            t=1;
        }
        if(t==0)
         break;
     }
     printf("%d",k);
}
