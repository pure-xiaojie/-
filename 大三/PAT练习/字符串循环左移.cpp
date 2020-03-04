#include<stdio.h>
#include<string.h>

int main()
{
    char a[100];
    int n;

    gets(a);
    scanf("%d",&n);

    int len = strlen(a);
    int t = n % len;
    for(int i = t; i < len; i++)
        printf("%c",a[i]);
    for(int k = 0; k < t; k++)
        printf("%c",a[k]);
    return 0;
}
