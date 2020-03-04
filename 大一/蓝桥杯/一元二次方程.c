/* Note:Your choice is C IDE */
#include "stdio.h"
#include "math.h"
int main ()
{
int a,b,c,d; 
float x1,x2;

scanf("%d%d%d",&a,&b,&c);
d=b*b-4*a*c; 
if (d>0)
{
x1=(-b+sqrt(d))/(2.0*a); 
x2=(-b-sqrt(d))/(2.0*a);
printf ("%.2f %.2f\n", x1,x2);
}
else if (d == 0)
{
x1 = (-b +sqrt(d)) / (2.0*a);
x2 = x1;
printf ("%.2f %.2f\n" , x1,x2);
}
else 
{
printf("нч╫Б\n");
}
return 0;
} 