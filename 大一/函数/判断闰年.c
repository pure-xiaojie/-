/* Note:Your choice is C IDE */
#include "stdio.h"
int isLeap(int year)
 { 
 	if((year%4==0&&year%100!=0)||(year%400==0)) 
 	  return 1; 
 	else 
 	  return 0; 
 }
void main()
{    int n;
	while(scanf("%d",&n)!=EOF)
	 if(isLeap(n))
       puts("yes");
     else
       puts("no");      
    
}