#include"stdio.h"
main()
{
    int n,i,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
    int m,s=1;
    scanf("%d",&m);
    for(i=0;i<n;i++)
    if(m<a[i])
      s++;
    printf("%d",s);
}
