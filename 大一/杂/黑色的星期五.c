#include<stdio.h>
int fun(int year,int month);
int main()
{
    int i,n,j,week[7]={0},a=13;
    scanf("%d",&n);
    for(i=1900;i<=1900+(n-1);i++)
    {
         for(j=1;j<=12;j++)
         {
            week[a%7]++;
            a+=fun(i,j);
         }
    }
    printf("%d ",week[6]);
    for(i=0;i<6;i++)
        printf("%d ",week[i]);
    return 0;
}


int fun(int year,int month)
{
    int i;
    if((year%4==0&&year%100!=0)||(year%400==0)) i=1;
    else i=0;
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    return 31;
    else if (month==2)
        {
            if(i==1)
            return 29;
            else return 28;
        }
    return 30;
}
