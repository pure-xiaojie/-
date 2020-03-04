/* Note:Your choice is C IDE */
#include<stdio.h>
int main()
{
 double a[65536],max,min;
 int j,b,t,n,i;
 scanf("%d",&n);
 for(i=0;i<n;i++) 
  
  scanf("%lf",&a[i]);
  
 max=a[0];
 min=a[0]; 
 for(i=0;i<n;i++)
 {
 if(a[i]>=max) 
     
    max=a[i]; 
   
 if(a[i]<=min) 
    
    min=a[i];
       
 }
 

 

  printf("%.2lf ",max-min);
 
 return 0;
}
 
