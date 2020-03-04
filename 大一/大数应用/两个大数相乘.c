#include"stdio.h"
#include"string.h"
main()
{
    long b,d;
    int i,i1,i2,j,k,n,n1,n2,a[256]={0};
    char s1[256],s2[256];
    gets(s1);
    gets(s2);
    n1=strlen(s1);
    n2=strlen(s2);
    d=0;
    for(i1=0,k=n1-1;i1<n1;i1++,k--)
    {
        for(i2=0,j=n2-1;i2<n2;i2++,j--)
        {
            i=i1+i2;
            b=a[i]+(s1[k]-'0')*(s2[j]-'0')+d;
            a[i]=b%10;
            d=b/10;
        }
       while(d>0)
        {
            i++;
            a[i]=a[i]+d%10;
            d=d/10;
        }
        n=i;
    }
    printf("%s * %s= ",s1,s2);
    for(i=n;i>=0;i--)
        printf("%d",a[i]);
    printf("\n");

return 0;

}
