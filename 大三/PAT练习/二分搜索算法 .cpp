#include<stdio.h>
#include<string.h>

int a[1000000];

int main()
{
    int n, x;
    scanf("%d%d",&n,&x);

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    if(a[0] >= x)
    {
      a[0] > x ? printf("-1 0") : printf("0 0");
      return 0;
    }

    if(a[n-1] <= x)
    {
        a[n-1] < x ? printf("%d %d",n-1,n) : printf("%d %d",n-1,n-1);
        return 0;
    }


    int left = 0,right = n;
    int mid = left+(right-left)/2;

    int l,r;
    while(left < right)
    {
        if(right - left == 1)
        {
            printf("%d %d",left,right);
            break;
        }
        if(a[mid] == x)
        {
            printf("%d %d",mid,mid);
            break;
        }
        else if(a[mid] > x)
        {
            right = mid;
        }

        else if(a[mid] < x)
        {
            left = mid;
        }

        mid = left+(right-left)/2;
    }
    return 0;
}

