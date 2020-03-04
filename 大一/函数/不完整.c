/* Note:Your choice is C IDE */
#include "stdio.h"
#include "string.h"

void conversionDigit(char str[])
{ 
int i,j,ret=0; 
for (i=0; i<strlen(str); i++)
 { for (j=0; str[j]>='0'&&str[j]<='9'; j++)  
    {
    ret *= 10; 
    ret += str[j] - '0';
    } 
  printf("%d ",ret);
 }
 
}

int main() 
{ 
int i,n; 
char str[6536];
scanf("%d",&n);
for(i=0;i<n;i++)
 {gets(str);
 conversionDigit(str); }
return 0; 
}