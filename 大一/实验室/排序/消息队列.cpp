#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>

using namespace std;

struct node
{
    int sign,vip,num;
    char msg[400];
    bool friend operator < (node a,node b)
    {
        if (a.vip == b.vip)
           return a.sign > b.sign;
        return a.vip > b.vip;     //越大优先级越小
    }
}s;
int main()
{
    char get[4];
    priority_queue<node> q;
    int k = 1;
    while (~scanf("%s",get))
    {
        if (get[0] == 'G')
        {
            if (q.empty())
              printf("EMPTY QUEUE!\n");
            else
            {
                s = q.top();
                printf("%s %d\n",s.msg,s.num);
                q.pop();
            }
        }
        else
        {
            scanf("%s %d %d",s.msg,&s.num,&s.vip);
            s.sign = k;
            k++;
            q.push(s);
        }
    }
    return 0;
}
