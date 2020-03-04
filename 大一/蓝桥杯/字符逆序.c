#include"stdio.h"
#include"string.h"
main()
{
    char str[100];
    gets(str);
    int i;
    for(i=strlen(str)-1;i>=0;i--)
      putchar(str[i]);

}
