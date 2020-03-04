#include"stdio.h"
long long find(long long a, long long b,long long c)
{
    long long temp;
    if(b>a)
    {
        temp=b;
        b=a;
        a=temp;
    }
    if(b==0)
      return c/a;
    else
      return find(b,a%b,c);

}
main()
{
    int m,i,a[10];
    scanf("%d",&m);

    for(i=0; i<m; i++)
        scanf("%d",&a[i]);

    long long min=a[0];
    for(i=1; i<m; i++)

       min=find(min,a[i],min*a[i]);

    printf("%lld",min);
}
