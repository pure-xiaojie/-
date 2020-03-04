/* Note:Your choice is C IDE */
#include<stdio.h>
 int main () 
 { double num1,num2; 
 	char n; 
 	while(1) 
 	{ 
 		 n=getchar();
 		
 		   if(n=='q') { printf("Bye!\n"); return 0; }
 		    
 		     scanf("%lf%lf",&num1,&num2);
 		   
 		    
 		     
 		      switch(n) 
 		      { case 'a': printf("%.2f + %.2f = %.2f\n",num1, num2, num1 + num2); break;
 		      	 case 's': printf("%.2f - %.2f = %.2f\n",num1, num2, num1 - num2); break; 
 		      	 case 'm': printf("%.2f * %.2f = %.2f\n",num1, num2, num1 * num2); break; 
 		      	 case 'd': printf("%.2f / %.2f = %.2f\n",num1, num2, num1 / num2); break;
 		      	 default : break; 
 		      } 
 	} 
return 0;
} 
 
  
  
 