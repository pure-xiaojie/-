/* Note:Your choice is C IDE */
#include "stdio.h"
void main() 
{ 
 int n=0,i=0; 
 char a[65536],b[65536]; 
 gets(a);
 
 while(a[i]) 
 { 
  if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z')
    b[n++]=a[i]; 
    i++; 
 } 
  i=0; 
 while(a[i]) 
 { 
  if(a[i]>='0'&&a[i]<='9')
    b[n++]=a[i]; 
    i++; 
 } 
 printf("%s",b); 
} 