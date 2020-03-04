#include<stdio.h>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
#define maxn 101

char p[maxn][maxn],str1[maxn],str2[maxn];
int len[maxn];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,k;
        scanf("%d",&n);
        int sum=0;
        for(i=1; i<=n; i++)
        {
            scanf("%s",p[i]);
            len[i]=strlen(p[i]);
        }
        for(i=0; i<len[1]; i++)
        {
            for(j=i; j<len[1]; j++)
            {
                for(k=i; k<=j; k++)
                {
                    str1[k-i]=p[1][k];
                    str2[k-i]=p[1][i+j-k];
                }
                str1[j-i+1]=0;
                str2[j-i+1]=0;
                int t=1;
                for(k=2; k<=n; k++)
                    if((!strstr(p[k],str1))&&(!strstr(p[k],str2)))
                    {
                        t=0;
                        break;
                    }

                if(t)
                {
                    if(sum < j-i+1)
                        sum = j-i+1;
                }

            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
