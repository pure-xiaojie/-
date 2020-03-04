#include<stdio.h>
void main()
{
    char a[1000];
    int T,m;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%s %d",a,&m);
        int i,flag=0;
        for(i=0; i<strlen(a) ; i++)
        {
            flag = flag *10 + a[i] - '0' ;
            flag = flag % m;
        }

        if(flag==0)
            printf("YES\n");
        else
            printf("NO\n");


    }

}
