#include"stdio.h"
#include"string.h"
 main()
{
    int t,i,k=1;
    scanf("%d",&t);
    while(t--)
    {
        char a[1000];
        scanf("%s",a);
        int n=strlen(a),s1=0,s2=0;
        for(i=0;i<n;i++)
            {
              if(i%2==0)
                s1+=a[n-1-i]-'0';
              else
                s2+=a[n-1-i]-'0';
            }
            printf("Case %d: ",k++);
            if((s1+s2)%3==0)
              printf("yes ");
            else
              printf("no ");

            if((s1-s2)%11==0)
              printf("yes\n");
            else
              printf("no\n");
      }

}
