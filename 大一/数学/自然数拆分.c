#include"stdio.h"

int a[1000],b[1000],n;

int find(int m,int start,int k)
  {
       int j , i;
      for(i=start; i<=m/2; i++) 
         {
          a[k]=m-i;
           b[k]=i;
           printf("%d=" ,n);   
           for (j=1;j<=k;j++)    
            printf("%d+" ,b[k]);   
          printf("%d\n" ,a[k]);  
          find(a[k],i,k+1);  
        } 
         return ; 
      
 } 
    int main() 
    {
         
         printf ("Please input N:" );
          scanf("%d" ,&n);
          find(n,1,1);
           
        return 0;
         
    }
