/* Note:Your choice is C IDE */
#include<stdio.h>
int main()
{
  double a,b,c,d,x1,x2;
  scanf("%lf%lf",&a,&b);
  scanf("%lf%lf",&c,&d);
  x1=a*c-b*d;
  x2=b*c+a*d;
  printf("%.0lf %.0lf\n",x1,x2);
 
return 0; 
}
