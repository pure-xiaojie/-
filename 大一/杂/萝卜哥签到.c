#include<stdio.h>
void main()
{
    int b[101],i=0,n;

    while(scanf("%d",&b[i++])!=EOF)
    {
        if(getchar()=='\n')
        {
            for( ; i>0 ; i--)
                printf("%d ",b[i-1]);

            printf("\n");
        }
    }
return 0;
}
