/* Note:Your choice is C IDE */
#include<stdio.h>
#include "math.h"
int fun(int n)
    {
       
        int i;

        { for (i=2;i<=sqrt(n);++i)
            if(n%i==0)
                break;
        }
        if(i>sqrt(n))
            return 1;
        else
            return 0;
    }


void main()
{
      int i,n=0;
      
      scanf("%d",&n); 
      for(i=2;i<=n;i++)
      {
          if(fun(i))
          {
             printf("%d ",i);
          }
      }
      
}