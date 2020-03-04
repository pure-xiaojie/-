#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    double res[200];
    int n;
    while(scanf("%d",&n) ,n)
    {
        char op,space;
        double num;
        int k = 0;
        res[++k] = 1.0 * n;
        while(~scanf("%c %lf%c",&op,&num,&space))
        {
            if(op == '+')
                res[++k] = 1.0 * num;
            else if(op == '-')
                res[++k] = -1.0 * num;
            else if(op == '*')
                res[k] = res[k] * num;
            else if(op == '/')
                res[k] = res[k] / num;

            if(space != ' ')
                break;
        }
        double sum = 0;
        for(int i = 0; i < k; i++)
            sum += res[i];
        printf("%.2lf\n",sum);
    }
    return 0;
}
