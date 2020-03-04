#include<stdio.h>
#include<string.h>
int judge(char str[])
{
    int i;
    for(i=0;i<strlen(str);i++)
        if(str[i]<'0'||str[i]>'9')
           return 0;
    return 1;
}
int main()
{
    char a[100],b[100],sum[150];
    int i,j,k=0,t=0;

    scanf("%s %s",a,b);
    i=strlen(a)-1;
    j=strlen(b)-1;
    if(judge(a)&&judge(b)&&i>=1&&i<=100&&j>=1&&j<=100)
    {

     for(; i>=0&&j>=0; i--,j--)
    {
        sum[t++]=(a[i]-'0'+b[j]-'0'+k)%10+'0';
        k=(a[i]-'0'+b[j]-'0'+k)/10;
    }
    while(i>=0)
    {
        sum[t++]=(a[i]-'0'+k)%10+'0';
        k=(a[i]-'0'+k)/10;
        i--;
    }
    while(j>=0)
    {
        sum[t++]=(b[j]-'0'+k)%10+'0';
        k=(b[j]-'0'+k)/10;
        j--;
    }
    if(k)
        sum[t++]=k+'0';
    t--;
    i=0;
    while(t>=0)
     printf("%c",sum[t--]);
    }
 else printf("error\n");
    return 0;
}
