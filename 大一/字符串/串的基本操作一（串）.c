#include<stdio.h>
#include<string.h>
void main()
{
    char a[100],b[100]={0};
    int i,j,len,k=0;
    scanf("%s",a);
    len=strlen(a);
    for(i=0; i<len-1; i++)
        for(j=i+1; j<len; j++)
            if(a[j]==a[i])
                b[k++]=a[j],a[j]='0';

    for(i=0; i<len; i++)
        if(a[i]!='0')
            putchar(a[i]);
    putchar('\n');
    putchar('\n');

    len=strlen(b);
     for(i=0; i<len-1; i++)
        for(j=i+1; j<len; j++)
            if(b[j]==b[i])
                b[j]='0';
    for(i=0; i<len; i++)
        if(b[i]!='0')
            putchar(b[i]);

}
