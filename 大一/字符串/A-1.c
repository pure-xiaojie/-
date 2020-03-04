#include "stdio.h"
#include "string.h"
void main() 
{ 
 int num,i; 
 char a[1000]; 
  while(scanf("%s",a)!=EOF) 
   {
   num=strlen(a);
   if(a[0]=='1'&&num==1)
      printf("0\n");
   else
   { 
   for(i=num-1;i>=0;i--)
   if(a[i]>'0') 
     {a[i]-=1;break;}
   else
     a[i]='9';
   
   if(a[0]!='0')
     puts(a);
   else 
     puts(a+1);
   }}
}
