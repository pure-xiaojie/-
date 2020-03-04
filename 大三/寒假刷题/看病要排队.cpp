#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

struct Node {
    int doctor;
    int pri;
    int num;

    bool friend operator < (Node a, Node b)
    {
        if(a.pri == b.pri)
            return a.num > b.num;
        return a.pri < b.pri;
    }
}node;

int main()
{
    int n;
    char ch[4];
    while(~scanf("%d",&n))
    {
        priority_queue<Node> q1;
        priority_queue<Node> q2;
        priority_queue<Node> q3;
        int k = 1;
        for(int i = 0; i < n; i++)
        {
            scanf("%s",ch);
            if(ch[0] == 'I')
            {
                node.num = k++;
                scanf("%d %d",&node.doctor, &node.pri);
                if(node.doctor == 1)
                    q1.push(node);
                else if(node.doctor == 2)
                    q2.push(node);
                else if(node.doctor == 3)
                    q3.push(node);
            }
            else
            {
                int t;
                cin >> t;
                if(t == 1 && !q1.empty())
                {
                    node = q1.top();
                    q1.pop();
                    cout << node.num << endl;
                }
                else if(t == 2 && !q2.empty())
                {
                    node = q2.top();
                    q2.pop();
                    cout << node.num << endl;
                }
                else if(t == 3 && !q3.empty())
                {
                    node = q3.top();
                    q3.pop();
                    cout << node.num << endl;
                } else {
                    cout << "EMPTY" << endl;
                }
            }
        }
    }
    return 0;
}
