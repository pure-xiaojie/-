#include"stdio.h"
void change(char a[],int i,int k)
{
    char c;
    c=a[i];
    a[i]=a[k];
    a[k]=c;
}

void print(char a[],int k,int m)
{
    int i;
    if(k==m)
      {
        for(i=0; i<=m; i++)
         printf("%c",a[i]);
         putchar('\n');
      }
    else
        for(i=k; i<=m; i++)
        {
            change(a,k,i);
            print(a,k+1,m);
            change(a,k,i);
        }

}

main()
{
    int  n,m,i;
    char a[10000];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        getchar();
        for(i=0; i<m; i++)
            {
            scanf("%c",&a[i]);
            getchar();
            }
            print(a,0,m-1);
     putchar('\n');
    }

}
