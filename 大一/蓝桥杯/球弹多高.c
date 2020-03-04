/* Note:Your choice is C IDE */
#include <stdio.h>  
int main()  
{  
    int i,j,n,t;  
    float h,height,sum;  
    scanf("%d",&t);  
    for(j=0; j<t; j++)  
    {  
        scanf("%f %d",&h,&n);  
        height=h;  
        sum=h;  
        for(i=1; i<=n; i++)  
        {  
            height=height*0.5;  
            sum=sum+2.0*height;  
        }  
        sum=sum-2.0*height;  
        printf("%.2f %.2f\n",sum,height);  
    }  
    return 0;  
  
}  