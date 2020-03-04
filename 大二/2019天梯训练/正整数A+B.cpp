#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int sum(char str[])
{
    int len = strlen(str);
    int sum = 0;
    for(int i = 0; i < len; i++)
    {

        if(str[i] >= '0' && str[i] <= '9')
            sum = sum*10 + (str[i] - 48);
        else
            return -1;
    }
    if(sum>=1 && sum<=1000)
        return sum;
    else
        return -1;
}
int main()
{
    char str1[1000],str2[1000];

    cin >> str1 >> str2;

    int sum1 = sum(str1);
    int sum2 = sum(str2);

    if(sum1==-1)
        printf("? + ");
    else
        printf("%d + ",sum1);

    if(sum2==-1)
        printf("? = ");
    else
        printf("%d = ",sum2);

    if(sum1==-1||sum2==-1)
        printf("?\n");
    else
        printf("%d\n",sum1+sum2);

    return 0;
}
