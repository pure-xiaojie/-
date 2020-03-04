#include <iostream>
#include<stdio.h>
#include<math.h>
#include<string>
using namespace std;

int height[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};///对应位上的权重
char m[11]={'1','0','X','9','8','7','6','5','4','3','2'};///校验码

int main()
{
    int n,sum,bj1=0,i,bj2;///bj1是用来判断该组数据是否全对
    char s[20];
    scanf("%d",&n);
    for(int k=0;k<n;k++)
    {
        scanf("%s",s);
        sum=0;
        bj2=0;///bj2是用来判断当前这个身份证的前17位是否都是数字
        for(i=0;i<17;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
                sum+=(s[i]-'0')*height[i];
            else
            {
                bj2=1;
                break;
            }
        }
        if(bj2==1||m[sum%11]!=s[17])
        {
            printf("%s\n",s);
            bj1=1;
        }
    }
    if(bj1==0)
        printf("All passed\n");
    return 0;
}

