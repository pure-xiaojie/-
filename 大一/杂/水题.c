#include"stdio.h"
main()
{
  long n,m;
  int i,a[1000];
  while(~scanf("%ld%ld",&n,&m))
  {
       for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++)
    {
    if(m>a[i])
      if(i==n-1)
       printf("yes\n");
      else ;
    else
      {printf("no\n"); break;}


    }

  }

}
