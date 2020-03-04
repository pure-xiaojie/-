/* Note:Your choice is C IDE */
#include "stdio.h"
int main()
{ void one();
  void two();
  void three();
  one();
  two();
  three();
return 0;  
}
 void one()
 {int n;
  scanf("%d",&n);
  while(n<100||n>999)
 	scanf("%d",&n);getchar();
  printf("%d\n",n%10*100+n/10%10*10+n/100);
 }
 void two()
 {char a,b,c;
  int s;
  scanf("%c%c%c",&a,&b,&c);
  getchar();
  s=a+b+c; 
  printf("%f\n",s/3.0);
 }
 void three()
 {int n;
  printf("============================= \n\n");
  printf("1 输入数据     2 修改数据 \n\n");
  printf("3 查询数据     4 打印数据 \n\n");
  printf("============================= \n\n");
  scanf("%d",&n);
  printf("hello world!");
  putchar(1);
 }