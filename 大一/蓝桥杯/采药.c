#include"stdio.h"
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
main()
{
    int t,m,i,j;
    scanf("%d%d",&t,&m);
    int a[1001]= {0};
    for(i=0; i<m; i++)
    {
        int k,l;
        scanf("%d%d",&k,&l);
        for(j=t-k;j>0;j--)
         if(a[j])
          a[j+k]=max(a[j+k],a[j]+l);
        a[k]=max(a[k],l);
    }
    int s=0;
    for(i=1;i<=t;i++)
    s=max(s,a[i]);
    printf("%d",s);

}

