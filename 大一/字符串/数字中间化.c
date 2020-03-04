#include"stdio.h"
#include"string.h"
void main()
{
    char a[65536], b[65535],c[65535];
    int i,j=0,k=0,n;
    gets(a);
    n=strlen(a);
    for(i=0; i<n; i++)
    {
        if(a[i]>='0'&&a[i]<='9')
            b[j++]=a[i];
        else c[k++]=a[i];
    }
    b[j]='\0'; c[k]='\0';
    for(i=0;i<(strlen(c)/2);i++)
        putchar(c[i]);
    for(i=0;i<strlen(b);i++)
        putchar(b[i]);
    for(i=(strlen(c)/2);i<strlen(c);i++)
        putchar(c[i]);

}
