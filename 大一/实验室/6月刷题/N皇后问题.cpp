#include<stdio.h>
int chess[11]= {0,1,0,0,2,10,4,40,92,352,724};
int n;
int main()
{
    while(scanf("%d",&n),n)
        printf("%d\n",chess[n]);

    return 0;
}

#include<stdio.h>
#include "math.h"
int chess[11],sum=0;
int n;

int check(int k)
{
    int i;
    for(i=1;i<k;i++)
      if(fabs(k-i)==fabs(chess[k]-chess[i])||chess[k]==chess[i])
        return 0;
    return 1;
}

int judge(int t)
{
    if(t>n)
        sum++;
    else
        for(int i=1; i<=n; i++)
        {
            chess[t]=i;
            if(check(t))
                judge(t+1);
        }
   return 0;
}


int main()
{

    while(scanf("%d",&n),n)
    {
        sum=0;
        judge(1);
        printf("%d\n",sum);
    }
return 0;
}
