#include<stdio.h>
void main()
{
    int n, i, j;
    scanf("%d", &n);
    int a[100][100];
    for(i = 0; i < n; ++i)
     for(j = 0; j <= i; ++j)
      scanf("%d", &a[i][j]);

    for(i = n - 2; i >=0; --i)
      for(j = 0; j <= i; ++j)
       a[i][j] += a[i + 1][j] > a[i + 1][j + 1] ? a[i + 1][j] : a[i + 1][j + 1];

    printf("%d", a[0][0]);

}
