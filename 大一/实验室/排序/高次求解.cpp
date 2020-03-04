#include<stdio.h>
#include<math.h>
#define type double

type find_x(type x)
{
    return 8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*x+6;
}
int main()
{
    int T;
    type y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf",&y);
        if(find_x(0)>y||find_x(100)<y)
        {
            printf("No solution!\n");

        }
        else
        {
            type left=0,right=100,mid;
            while(right-left > 1e-10)
            {
                mid=(right+left)/2.0;
                if(find_x(mid) > y)
                    right=mid;
                else
                    left=mid;
            }
            printf("%.4lf\n",mid);
        }
    }
    return 0;
}
