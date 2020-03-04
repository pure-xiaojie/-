/* Note:Your choice is C IDE */
#include<stdio.h>
int n;
void startJudge(int value)
{ if(Judge(value))
   printf("%d ",value);
  else
   if(value==n)
   printf("none");
  
}

int Judge(int n)
{
int i,s=0;
for(i = 1; i <=n/2; i ++)
if(n%i == 0) s+= i;
if(s == n) return 1;

return 0;
}

void main()
{
int sum,i,j;
scanf("%d",&sum);
for(i=1;i<=sum;i++)
  {
  scanf("%d",&n);
  if(n>28&&n<496)n=28;
   if(n>=496&&n<1000)n=496;
  for(j=1;j<=n;j++)
   startJudge(j);
   putchar('\n');
  }
}