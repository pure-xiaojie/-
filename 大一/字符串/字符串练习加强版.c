/* Note:Your choice is C IDE */
#include<stdio.h>
void main()
{
    char str[99];
    int flag,i,k[4];
  
    while(gets(str)!=NULL)
    {
        for(i = 0; i < 4; i++)
            k[i]=0;
        i = 0;
        flag = 1;
        while(str[i]!='\0')
        {
            if(flag)
            {
                k[0]++;
                flag=0;
            }
            if(str[i]==' '&&str[i+1]!=' ')
                flag=1;
  
            if(str[i] >= 'A' && str[i] <= 'Z')
                k[1]++;
  
            if(str[i] >= 'a' && str[i] <= 'z')
                k[2]++;
  
            if(str[i] >= '0' && str[i] <= '9')
                k[3]++;
  
            i++;
        }
        for(i=0; i<4; i++)
            printf("%d ",k[i]);
        printf("\n");

    }
return 0;
}