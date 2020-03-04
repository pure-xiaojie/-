#include"stdio.h"
#include"string.h"
int max_length(char ch[])
{
    int i,flag=0,max=0,k=0;
    for(i=0;i<strlen(ch);i++)
      if(ch[i]!=' ')
        flag++;
      else
      {
          if(max<flag)
          {max=flag;k=i-flag-1;}
           flag=0;
      }
    if(max<flag)
    {max=flag;k=i-flag-1;}

  return k;
}
main()
{
    char str[1000];
    gets(str);
    int k=max_length(str)+1;
    for(;str[k]!=' '&&str[k];k++)
     putchar(str[k]);
}
