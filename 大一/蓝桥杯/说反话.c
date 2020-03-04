/* Note:Your choice is C IDE */
#include "stdio.h"
#include "string.h"
void main()
{char a[1000];
 int i,n;
 scanf("%d",&n);
 getchar();
 while(n--)
 { 
   gets(a);
  
   i=strlen(a)-1;
   for(;i>=0;i--) 
   printf("%c",a[i]);
   printf("\n");
 }
   return ;   
}