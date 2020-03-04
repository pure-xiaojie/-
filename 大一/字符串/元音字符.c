/* Note:Your choice is C IDE */
#include "stdio.h"
void main() 
{ 
 int num=0,i=0; 
 char str[256]; 
 gets(str);
 
 while(str[i]) 
 { 
  switch (str[i]) 
  { 
   case 'a': 
   case 'e':   
   case 'i': 
   case 'o':   
   case 'u':  num++; break; 
  
  } 
 i++; 
} 
 printf(" %d",num); 
} 