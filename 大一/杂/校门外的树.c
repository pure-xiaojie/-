#include"stdio.h"
main()
{
    int a[10001]={0},m,l,i,j;
    scanf("%d%d",&l,&m);
    while(m--)
    {
        scanf("%d%d",&i,&j);
        for(;i<=j;i++)
            a[i]=1;

    }
    int sum=0;
    for(i=0;i<=l;i++)
        if(a[i]==0)
          sum++;
    printf("%d\n",sum);


}
