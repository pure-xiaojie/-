#include"stdio.h"
#include"string.h"
main()
{
    char a[1000];
    int i,j,k=0,b;
    long long max=0,m=0;
    gets(a);
    for(i=0,j=0;i<strlen(a);i++,j=i)
    {
        int n=0;
      while(a[j]>='0'&&a[j]<='9')
       {
        n++;
        m=m*10+a[j]-'0';
        j++;
        i=j-1;

       }
       if(max<m)
       {
         max=m;
         b=j-n+1;
       }

    }

    printf("%d",b);


}
