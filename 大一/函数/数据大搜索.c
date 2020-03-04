/* Note:Your choice is C IDE */
#include <stdio.h>
void conversionDigit(char str[]);
int main()
{
    char a[1000];
    int t;
    scanf("%d", &t);
    getchar();
    
    while (t--)
    {
        scanf("%s",a);
        conversionDigit(a);
    }  
   
}

void conversionDigit(char str[])
{ int c,j,i;
        c=0;
        j=0;
        for (i=0;str[i]!='\0';i++)
        {
            if (str[i]>='0'&&str[i]<='9')
             {
              c=c*10+(str[i]-'0');
              j=1;
              } 
              else
            {
                if (j)
                {
                    printf("%d ",c);
                    c=0;
                    j=0;
                }
            }
        }
        if(j)
        {
            printf("%d ",c);
        }
        printf("\n");
     
     
}