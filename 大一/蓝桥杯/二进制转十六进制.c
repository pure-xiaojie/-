#include"stdio.h"
#include"stdlib.h"
void convert( char *input)
{
   gets(input);

}
main()
{
    int n;
    scanf("%d",&n);
    char a[30];
    int i=1;
    getchar();
    while(n--)
    {
      convert(a);
      printf("Case %d: %X\n",i++,strtol(a,NULL,2));
    }
}
