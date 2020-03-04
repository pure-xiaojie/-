#include<stdio.h>
main()
{
    char a[4];
    int t;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        int i,flag=0;


        if(a[0]==a[1]&&a[1]==a[2]||a[3]==a[1]&&a[1]==a[2])
            if(a[0]==a[3])
               flag+=6;
            else
                flag+=3;
        if((a[0]==a[1]-1&&a[0]==a[2]-2&&a[0]==a[3]-3)||(a[0]==a[1]+1&&a[0]==a[2]+2&&a[0]==a[3]+3))
            flag+=5;

        if(a[0]==a[1]&&a[2]==a[3]||a[0]==a[2]&&a[1]==a[3])
            if(a[0]==a[3]&&a[0]==a[1]&&a[0]==a[2])
               flag+=2;
            else
                flag+=1;
        for(i=0;i<4;i++)
            if(a[i]=='6'||a[i]=='8'||a[i]=='9')
              flag++;
            printf("%d\n",flag);


    }
}

