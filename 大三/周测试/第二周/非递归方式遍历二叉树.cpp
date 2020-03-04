#include<bits/stdc++.h>

using namespace std;

struct node
{
    int left;
    int right;
};

int n;

//先序
void a1(struct node a[105],int left)
{
    if(left != 0) {
        cout << left << ' ';
        if(a[left].left != 0)
            a1(a,a[left].left);
        if(a[left].right != 0)
            a1(a,a[left].right);
    }
    /*非递归
    ustack<int> s;
    s.push(left);
    while(!s.empty()) {
        int p = s.top();
        s.pop();
        if(p != 0) {
            cout << p << ' ';
            s.push(a[p].right);
            s.push(a[p].left);

        }
    }*/
}

//中序
void a2(struct node a[105],int left)
{
    if(left != 0) {
        if(a[left].left != 0)
            a2(a,a[left].left);
        cout << left << ' ';
        if(a[left].right != 0)
            a2(a,a[left].right);
    }

}

//后序
void a3(struct node a[105],int left)
{
    if(left != 0) {
        if(a[left].left != 0)
            a3(a,a[left].left);
        if(a[left].right != 0)
            a3(a,a[left].right);
        cout << left << ' ';
    }
}

//层次
void a4(struct node a[105],int left)
{
    if(left != 0) {
        queue<int> q;
        q.push(left);
        while(!q.empty()) {
            int t = q.front();
            cout << t << ' ';
            if(a[t].left)
                q.push(a[t].left);
            if(a[t].right)
                q.push(a[t].right);
            q.pop();
        }
    }

}

int main()
{
    struct node a[105];
    int b[101] = {0};
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].left >> a[i].right;
        b[a[i].left] = 1;
        b[a[i].right] = 1;
    }

    int m = 1;
    for (int i = 1; i <= n; i++) {
        if(b[i] == 0)
        {
            m = i;
            break;
        }
    }
    a1(a,m);
    cout << endl;
    a2(a,m);
    cout << endl;
    a3(a,m);
    cout << endl;
    a4(a,m);

    return 0;
}
