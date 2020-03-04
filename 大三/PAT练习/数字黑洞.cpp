#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

int getNum(char s[4])
{
    int sum = 0;
    for(int i = 0; i < 4; i++)
        sum = sum * 10 + (s[i] - '0');
    return sum;
}

int main()
{
    char n[4];
    scanf("%s",n);

    int len = strlen(n);
    if(len < 4)
    {
        for(int i = len; i< 4; i++)
            n[i] = '0';
    }
    cout << n << endl;

    if(n[0] == n[1] && n[0] == n[2] && n[0] == n[3])
        printf("%s - %s = 0000",n,n);
    else
    {
        while(1)
        {
            sort(n,n+4,greater<char>());
            printf("%s - ",n);
            int t = getNum(n);

            sort(n,n+4);
            printf("%s = ",n);
            int s = getNum(n);

            int m = t - s;
            printf("%d",m);

            int i = 0;
            while(m)
            {
              n[i++] = (m % 10) + '0';
              m /= 10;
            }
            if((n[0] == '4' && n[1] == '7' && n[2] == '1' && n[3] == '6'))
                break;
            printf("\n");

        }

    }
    return 0;
}
