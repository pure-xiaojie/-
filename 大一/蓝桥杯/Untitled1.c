#include"stdio.h"
#include"string.h"
int main()
{
    int sum,i;
    char a[2000];
    while(~scanf("%s",a))
    {
        i=0;
        while(a[i]!='.')
          i++;
      printf("%d\n",strlen(&a[i])-1);
    }
    return 0;
}
