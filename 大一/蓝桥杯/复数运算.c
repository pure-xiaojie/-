#include"stdio.h"
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a1,b1,a2,b2;
        char c;
        scanf("%d %d",&a1,&b1);
        getchar();
        scanf("%c",&c);
        getchar();
        scanf("%d %d",&a2,&b2);

        float a3,b3;
          if(c=='+')
           {a3=a1+a2;b3=b1+b2;}
          else if(c=='-')
           {a3=a1-a2;b3=b1-b2;}
          else if(c=='*')
           {a3=a1*a2;b3=b1*b2;}
          else if(c=='/')
           {a3=a1/a2;b3=b1/b2;}



    if(a3==0.0&&b3==0.0)printf("0.0\n");
    if(b3==1.0)printf("i\n");
    if(a3==0&&b3!=0&&b3!=1.0)printf("%.1fi\n",b3);
    if(a3!=0&&b3==0)printf("%.1f\n",a3);
    if(a3!=0&&b3>0)printf("%.1f%c%.1fi\n",a3,c,b3);
    if(a3!=0&&b3<0)printf("%.1f%c%.1fi\n",a3,c,b3);
    }
}
