/* Note:Your choice is C IDE */
#include<stdio.h>
void countmove(int n,char a,char b,char c);
int sum=0;
void main()
{
    int n,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        countmove(m,'a','b','c');
        printf("%dÌì\n",sum);
        sum=0;
    } 
}

void countmove(int n,char a,char b,char c)
{
    if(n==1)
        sum++;
    else
    {
        countmove(n-1,a,c,b);
        sum++;
        countmove(n-1,b,a,c);
    }
} 