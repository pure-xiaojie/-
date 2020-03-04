#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int k=0; k<n; k++)
    {
        char a[50],b[20];
        gets(a);
        int i=0,j=0,t=1,m=strlen(a);
        for(; i<m; i++)
            if(a[i]!=' '&&t&&a[i]>='a'&&a[i]<='z')
            {
                b[j++]=a[i]-32;
                t=0;
            }
            else if(a[i]!=' '&&t&&a[i]>='A'&&a[i]<='Z')
            {
                b[j++]=a[i];
                t=0;
            }
            else
            {
                if(a[i]==' '&&((a[i+1]>='a'&&a[i+1]<='z')||(a[i+1]>='A'&&a[i+1]<='Z')))
                    t=1;
            }
        b[j]='\0';
        puts(b);
    }

    return 0;
}
