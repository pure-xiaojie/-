#include<stdio.h>
int  main()
{
    int n,A,B;
    while(scanf("%d",&n)!=EOF)
    {
        A=((1+n)*n))/2;
        while( n>1 )
    {
        scanf("%d",&B);
            A-=B;
            n--;
        }
        printf("%d\n",A);
    }
    return 0;
}
