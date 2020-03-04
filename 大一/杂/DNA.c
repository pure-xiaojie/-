#include<stdio.h>
int main()
{
    int a,b,N,i,j,again;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&a,&b);
        for(again=0; again<b; again++)
          for(i=0; i<a-1; i++)
             {
                for(j=0; j<a; j++)
                  if(i==j||i+j==a-1)
                    printf("X");
                  else
                    printf(" ");
                printf("\n");
             }
        for(i=0,j=0; j<a; j++)
            if(i==j||i+j==a-1)
                printf("X");
            else
                printf(" ");
        printf("\n\n");
    }
    return 0;
}
