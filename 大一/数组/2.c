/* Note:Your choice is C IDE */
#include "stdio.h"
void print1(int a[][5],int n)
 {   int i,j=0;;
 	 for(i=0;i<n;i++)
 	  {for(j=0;j<5;j++)
       printf("%d ",a[i][j]);
       printf("\n");}	       
 }
 
 
 void print2(int a[][5],int n)
 {   int i,j=0;
 	for(i=0;i<n;i++)
      {for(j=0;j<5;j++) 
      	printf("%d ",a[i][j]*2);
        printf("\n");}
 }
 
void main()
{int a[2][5],i,n;
  
 for(i=0;i<2;i++)
  for(n=0;n<5;n++)
  scanf("%d",&a[i][n]);
  print1(a,2);
  print2(a,2);
  
 return 0;    
}
