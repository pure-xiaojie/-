#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
    int a[1010]={0},n,N,i,num=0;

    scanf("%d",&N);
    getchar();

    for(i=0;i<N;i++)
        {scanf("%d",&n);
         a[n]++;
        }

    for(i=1; i<1001; i++)
        if(a[i])
        {
            num++;
        }

    printf("%d\n",num);

    for(i=1; i<1001; i++)
        if(a[i])
            printf("%d ",i);

}
