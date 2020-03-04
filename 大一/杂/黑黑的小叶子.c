/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
	int n,day,i;
	float m,s;
	scanf("%d",&n);
	scanf("%d%f",&day,&m);
	for(i=0,s=n;i<day;i++)
	  s=s-(m*s);
	printf("%.1f",s);
    
}