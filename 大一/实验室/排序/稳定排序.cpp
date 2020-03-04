#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 301
struct node
{
    char name[51];
    int score;
    int num;

}a[maxn];

bool cmp(node a,node b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.num < b.num;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int T1,T2;
        T1=T2=1;
        for (int i = 0 ; i < n ; i++)
        {
            cin >> a[i].name >> a[i].score;
            a[i].num = i;
        }
        sort(a,a+n,cmp);

        for (int i = 0 ; i < n ; i++)
        {
            char t1[55];
            int t2;
            cin >>t1 >> t2;
            if (t2 != a[i].score)
                T1 = 0;
            else if (strcmp (t1,a[i].name) != 0)
                T2 = 0;
        }
        if (!T1)
        {
            printf ("Error\n");
            for (int i = 0 ; i < n ; i++)
                printf ("%s %d\n",a[i].name,a[i].score);
        }
        else
        {
            if (T2)
                printf ("Right\n");
            else
            {
                printf ("Not Stable\n");
                for (int i = 0 ; i < n ; i++)
                    printf ("%s %d\n",a[i].name,a[i].score);
            }
        }
    }
  return 0;
}
