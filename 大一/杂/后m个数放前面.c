/* Note:Your choice is C IDE */
#include <stdio.h>
int main()
{    
	int m,n,a[1001],i,k,j;    
	scanf("%d%d",&n,&m);    
	
	for (i=0; i<n; i++) 
	  scanf("%d",&a[i]);    
	
	for(i=m;i>0;i--)
       {
        j=a[n-1];
        for(k=n-1;k>=1;k--)
        a[k]=a[k-1];
        a[0]=j;
       }

    for(i=0;i<n;i++)        
    printf("%d ",a[i]);
    printf("\n");
return 0;
}