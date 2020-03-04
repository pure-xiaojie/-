#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

char a[1005];

void change(int i,int j)
{
    char t;
    i--;
    j--;
    while(i < j)
    {
       t = a[i];
       a[i] = a[j];
       a[j] = t;

       i++;
       j--;

    }
}

int main()
{
    int n,num[101];
    while(~scanf("%s",a))
    {
       int len = strlen(a);
       if(len < 2 || len > 1000)
            break;
       scanf("%d",&n);

       for(int i = 0; i< n; i++)
       {
           scanf("%d",&num[i]);

           change(num[i],len-num[i]+1);
       }
       printf("%s\n",a);

    }
    return 0;
}
