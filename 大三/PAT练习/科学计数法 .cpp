#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
    char a[10000];
    scanf("%s",a);

    if(a[0] == '-')
        putchar('-');
    char *p = (strchr(a,'E')+2);

    int n = 0;
    for(; *p != '\0'; p++) {
        n = n*10 + (*p - '0');
    }

    if(*(strchr(a,'E')+1) == '-'){
        if(n) {
            printf("0.");
            for(int i = 0; i < n-1; i++)
                putchar('0');
            putchar(a[1]);
            for(int i = 3; a[i] != 'E'; i++)
                putchar(a[i]);
        }
        else {
            for(int i = 0; a[i] != 'E'; i++)
                putchar(a[i]);
        }
    }
    else if(*(strchr(a,'E')+1) == '+') {
       putchar(a[1]);
       int i;
       for(i = 3; a[i] != 'E' && n >= 0; i++,n--)
           putchar(a[i]);
       if(n == 0 && a[i] != 'E') {
           putchar('.');
           for(; a[i] != 'E'; i++)
            putchar(a[i]);
       }
       else if(n > 0 && a[i] == 'E') {
           for(int i = 0; i < n; i++)
              putchar('0');
       }

    }
    return 0;
}
