#include<stdio.h>

main()
{
    int i,N,sum=0,high,r,d,k;
    char c;
    scanf("%d %c",&N,&c);
    for(i=1; sum<=N; i++)
     sum=2*i*i-1;

    high=i-2;
    sum=2*high*high-1;

    r=N-sum;
    for(d=high; d>0; d--)
    {
        if(d<high)
        for(k=high-d; k>0; k--)
        printf(" ");


        for(i=2*d-1; i>0; i--)
         printf("%c",c);

        printf("\n");

    }
    for(d=2; d<=high; d++)
    {
        if(d<high)
        for(k=high-d; k>0; k--)
         printf(" ");


        for(i=2*d-1; i>0; i--)
            printf("%c",c);

        printf("\n");
    }


}
