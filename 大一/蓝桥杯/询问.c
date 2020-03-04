#include"stdio.h"
#include"string.h"
struct peop
{
    char a[50];
    char b;
}peo[100];
 main()
{
    int  n,sum,i;
    scanf("%d",&sum);
    while(sum--)
    {
        scanf("%d",&n);
        getchar();
        for(i=0; i<n; i++)
            {
            scanf("%s %c",peo[i].a,&peo[i].b);
            getchar();
            }
        int ask,j,s;
        char c[100];
        scanf("%d",&ask);
        getchar();
        for(i=0; i<ask; i++)
        {
            scanf("%s",c);
            for(j=0; j<n; j++)
            if(!strcmp(peo[j].a,c))
            {
                if(peo[j].b=='K')
                    s=5;
                else
                    if(peo[j].b=='L')
                     s=3;
                    else
                      if(peo[j].b=='R')
                        s=4;
                printf("%d\n",s);
                break;
            }

           if(j==n)
            printf("none\n");
      }
    }
}
