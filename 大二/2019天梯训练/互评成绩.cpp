#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
double a[10500] = {0};

int main()
{
    double max, min;
    int n, m, k;
    cin >> n >> m >> k;

    double sum,score;
    for (int i = 0; i <= n - 1; i ++)
    {
        sum = 0;
        max = -1;
        min = 101;
        for (int j = 0; j <= m - 1; j ++)
        {
            cin >> score;
            if (score > max)
                max = score;
            if (score < min)
                min = score;
            sum = sum + score;
        }
        sum = (sum - max - min) / (m - 2.0);
        a[i] = sum;
    }
    sort(a,a+n-2);
    for (int i = 0; i < n; i++)
        printf("%.3lf\n", a[i]);
    for (int i = k - 1; i >= 0; i --)
    {
        if (i == 0)
            printf("%.3lf\n", a[i]);
        else
            printf("%.3lf ",a[i]);
    }
    return 0;
}
