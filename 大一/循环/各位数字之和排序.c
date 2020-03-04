/* Note:Your choice is C IDE */
#include<stdio.h>
int main()
{ 
	long int n,a[65536],b[65535],i,j,k,t;
	 while(scanf("%d",&n),n) 
	 { 
	 	for(i=0;i<n;i++) 
	 	 scanf("%d",&b[i]); 
	 	
	 	 
	 	 
	 	 for(k=0;k<i;k++) 
	 	  for(;b[k];)
	 		{a[k]+=b[k]%10;b[k]/=10;}
	 			
	 		  
	 	 
	 	 
	 	 
	 	for(k=1;k<=i;k++) 
	 	 {for(j=0;j<(i-k);j++)
	 		  if(a[j]>a[j+1]) 
	 			{ t=b[j]; b[j]=b[j+1]; b[j+1]=t; } 
	 		  
	 	 }
	 		for(j=0;j<i-1;j++) 
	 		printf("%d ",b[j]);  
	 		printf("%d\n",b[j]); 
	 } 
return 0;
}