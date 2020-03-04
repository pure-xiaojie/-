#include"stdio.h"
#include"string.h"
main()
{
    int m,i,j;
    scanf("%d\n",&m);

    char a[m][10000];

    for(i=0;i<m;i++)
    gets(a[i]);

    for(i=0;i<m-1;i++)
     for(j=i+1;j<m;j++)
     if(strcmp(a[i],a[j])>0)
    {
        char temp[1000];
        strcpy(temp,a[i]);
        strcpy(a[i],a[j]);
        strcpy(a[j],temp);
    }
    for(i=0;i<m;i++)
     puts(a[i]);

}

