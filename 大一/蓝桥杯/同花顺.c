#include <stdio.h>
main()
{
    char a[5][2];
    while(~scanf("%s %s %s %s %s",a[0],a[1],a[2],a[3],a[4]))
    {

        int i,j,b[5]={0},flag=1;
        for(i=0;i<5;i++)
          {
           if(a[i][0]>'2'&&a[i][0]<='9')
              b[i]=a[i][0]-'0';

            else if(a[i][0]=='J')
              b[i]=11;
            else if(a[i][0]=='Q')
              b[i]=12;
            else if(a[i][0]=='K')
              b[i]=13;
            else if(a[i][0]=='A')
              b[i]=14;
            else
              b[i]=10;
          }

       for(i=0;i<4;i++)
        for(j=i+1;j<5;j++)
        if(b[i]>b[j])
       {
           int temp=b[i];
           b[i]=b[j];
           b[j]=temp;
       }

       if((b[0]+1==b[1])&&(b[1]+1==b[2])&&(b[2]+1==b[3])&&(b[3]+1==b[4]))
         printf("Yes\n");
       else
         printf("No\n");
       getchar();
    }

}
