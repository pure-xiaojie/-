/* Note:Your choice is C IDE */
#include<stdio.h>
#include<math.h>
int isprime(int n)
{
  int i;
  for(i=2; i<=sqrt(n); i++)
  {
     if(n%i == 0)
      
       return 0;
      
     if(i>sqrt(n))

       return 1;

  }
 return 1;
}


int main()
{
int i,m;

scanf("%d",&m);
for(i=2; i<=sqrt(m); i++)
  {
    if(m%i == 0)
    {
     if(isprime(i))
      {
      printf("%d ",i);
      m /= i;
      i = 1;
      }
    }
  }
   if(i>sqrt(m))
   printf("%d ",m);

return 0;
}