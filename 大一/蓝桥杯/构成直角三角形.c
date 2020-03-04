#include"stdio.h"
main()
{
    int n,a,b,c;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a>b)
        {
            a=a+b;
            b=a-b;
            a=a-b;
        }
        if(a>c)
        {
            a=a+c;
            c=a-c;
            a=a-c;
        }
        if(b>c)
        {
            b=b+c;
            c=b-c;
            b=b-c;
        }
        if(a*a+b*b==c*c)
          printf("%d\n",1);
        else
         printf("%d\n",0);
    }


}
