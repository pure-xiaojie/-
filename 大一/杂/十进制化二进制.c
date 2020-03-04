#include"stdio.h"
int change(int n)
{
    if(n!=1)
      change(n/2);
      printf("%d",n%2);


}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        change(n);
        putchar('\n');
    }
 return 0;
}
