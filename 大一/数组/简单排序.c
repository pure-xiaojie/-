/* Note:Your choice is C IDE */
#include "stdio.h"
int main()
{
    int n,x[1000],i,j,k,m;
    scanf("%d",&m);
    while(m--)
    {
        
        scanf("%d",&n);
            
        for(i=0;i<n;i++)
         scanf("%d",&x[i]);
         
        for(i=0;i<n;i++)
        { for(k=i,j=k+1;j<n;j++)
            if(x[k]>x[j]) k=j;
            if(k!=i)
             {
                j=x[k];
                x[k]=x[i];
                x[i]=j;
             }
            
        }
        for(i=0;i<n;i++)
        printf("%d ",x[i]);
        printf("\n");
    }
    return 0;
}