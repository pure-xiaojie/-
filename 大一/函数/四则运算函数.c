/* Note:Your choice is C IDE */
#include "stdio.h"
int add(int a,int b)
{
 return a+b;
}

int sub(int a,int b)
{
 return a-b;
}

int mul(int a,int b)
{
 return a*b;
}

float div(float a,float b)
{	
 return a/b;
}
int main()
{int a,b,n;
 char c,d,e;
 scanf("%d",&n);getchar();
 while(n--)
 {
  scanf("%c%c%c(%d,%d)",&c,&d,&e,&a,&b);
  if(c=='a')
  printf("%d\n",add(a,b));
  
  if(c=='s')
  printf("%d\n",sub(a,b));
 
  if(c=='m')
  printf("%d\n",mul(a,b));
  
  if(c=='d')
  if(b==0)
    printf("error\n");
  else  
    printf("%.2f\n",div(a,b));
  getchar();
 }
 return 0;  
}
