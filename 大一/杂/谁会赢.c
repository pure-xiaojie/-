#include<stdio.h>
int main()
{
    int n, m,i=0;
    while(scanf("%d",&n)!=EOF)
    {
      if(n%2==0)
        printf("1\n");
      else
        printf("0\n");
    }
    return 0;

}
