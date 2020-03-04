#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;

struct node {
    int time;
    int num;
    int pri;
    char msg[100];

    bool friend operator < (node a, node b) {
        if(a.pri == b.pri)
            return a.time > b.time;
        return a.pri > b.pri;
    }
};

int main()
{
    priority_queue<node> q;
    char get[5];
    int k = 0;
    struct node no;

    while(~scanf("%s",get))
    {
        if(get[0] == 'G') {
            if(q.empty())
            {
                cout << "EMPTY QUEUE!" << endl;
            }
            else
            {
                no = q.top();
                q.pop();
                cout << no.msg << " " << no.num << endl;
            }
        } else {
            cin >> no.msg >> no.num >> no.pri;
            no.time = k++;
            q.push(no);
        }
    }
    return 0;
}
