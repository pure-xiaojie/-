#include"stdio.h"
#include"string.h"
main()
{
    char a[100000];
    while(gets(a)!=NULL)
    {
        int i,b[4]= {0};
        for(i=0; i<strlen(a); i++)
            if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z')
                b[0]++;
            else if(a[i]==' ')
                b[2]++;
            else if(a[i]>='0'&&a[i]<='9')
                b[1]++;
            else b[3]++;
        for(i=0; i<4; i++)
            printf("%d ",b[i]);
            putchar('\n');
    }

}
