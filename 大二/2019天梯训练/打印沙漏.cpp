#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    char sympol;
    scanf("%d %c", &n, &sympol);
    int m = sqrt(2 * (n + 1)) - 1;//m为总共的层数，以及一层最大的符号个数
    if (m % 2 == 0)  //这里是防止放大了m使它变为偶数（而题目要求是奇数）
    {
        m--;
    }
    int tag = 0, count = 0;//tag控制左侧空格的输出，count计数
    for (int i = m; i >= 1; i -= 2)
    {
        for (int j = 0; j < tag; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("%c", sympol );
            count++;
        }
        printf("\n");
        tag++;
    }
    tag -= 2;
    for (int i = 3; i <= m; i += 2)
    {
        for (int j = 0; j < tag; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("%c", sympol );
            count++;
        }
        printf("\n");
        tag--;
    }
    printf("%d\n", n - count);
}
