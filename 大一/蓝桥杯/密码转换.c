/* Note:Your choice is C IDE */
#include "stdio.h"
#include "string.h"
int main()
{char a[101];
    int t,i,n,j,k=0,m,b[101];
    scanf("%d",&t);
    while(t--)
    {k=0;
     scanf("%s",a);
     n=strlen(a);
       for(i=0;i<n;i++)
       b[k++]=(int)a[i];
        for(i=0;i<6;i++)
        {
        k=0;
        for(j=i;j<n;j+=6)
        {
         k+=b[j];                
        }
        if(k==0)
        printf("0");
        else
        {
        m=k%9;
        if(m==0)
        printf("9");
        else
        printf("%d",m);
        }
        }
        printf("\n");
    }
 
    return 0;
}
