#include<stdio.h>
#include<string.h>

int main()
{
    char a[100];
    gets(a);
    int len = strlen(a);
    for(int i = 0; i < len; i++)
        if(a[i] >= 'A' && a[i] <= 'Z')
            putchar('Z'-a[i]+'A');
        else
            putchar(a[i]);
    return 0;
}
