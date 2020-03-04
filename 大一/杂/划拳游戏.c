#include"stdio.h"
main()
{
    int m;
    while(~scanf("%d",&m))
    {
        int i,n,a=0,b=0,c=0,s=0;
        for(i=0;i<m;i++)
        {
         scanf("%d",&n);
         if(n==0)
           a++;
         else if(n==2)
               b++;
              else
               c++;
        }
        if(a&&b&&c||a==m||b==m||c==m)
          s=m;
        else
          if(a==0&&b&&c)
            s=c;
          else
             if(b==0&&a&&c)
              s=a;
             else
              if(c==0&&a&&b)
                s=b;

     printf("%d\n",s);
    }

}
