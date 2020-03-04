#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define max_n 100001

using namespace std;
int select[3];    //移动方式
int time[max_n];  //存储到达对应点的时间，且为0时表示未访问

int bfs(int n, int k)
{
    if(n == k)   //若当前结点为终点，返回0
        return  0;

    queue<int> que;
    que.push(n);
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        //三种移动方式
        select[0] = cur - 1;
        select[1] = cur + 1;
        select[2] = cur * 2;

        //对任意的三种方式进行bfs遍历
        for(int i = 0; i < 3; i++) {
            //越界与是否访问判断
            if(select[i] >= 0 && select[i] < max_n && time[select[i]] == 0) {
                que.push(select[i]);
                time[select[i]] = time[cur] + 1;   //时间加1
            }
        }
    }
    return time[k];  //返回到达终点时间

}

int main()
{
    int n, k;
    while(~scanf("%d%d",&n,&k))
    {
        memset(time, 0, sizeof(time));   //初始化时间为0
        int res = bfs(n,k);
        cout << res << endl;
    }
    return 0;
}
