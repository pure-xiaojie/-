#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int n;
    char ch;
    scanf("%d %c",&n,&ch);

    if(n ==0)
    {
        printf("%d",n);
        return 0;
    }
    if(n == 1)
    {
        printf("%c\n",ch);
        printf("%d",n-1);
        return 0;
    }
    int len = sqrt(n/2);

    for(int i = len; i > 0; i--)
    {
        for(int k = i; k < len; k++)
            printf(" ");
        for(int j = 0; j < 2 * i - 1; j++)
            printf("%c",ch);
        printf("\n");
    }
    for(int i = 2; i <= len; i++)
    {
        for(int k = i; k < len; k++)
            printf(" ");
        for(int j = 0; j < 2 * i - 1; j++)
            printf("%c",ch);
        printf("\n");
    }
    printf("%d",n-(2*len*len-1));
    return 0;
}
