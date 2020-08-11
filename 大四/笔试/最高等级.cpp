#include<bits/stdc++.h>

using namespace std;

int maxLevel(int x, int level, int **tasks, int tasksRowLen, int* tasksColLen) {
    // write code here
    sort(tasks,tasks+tasksRowLen);

    int res = 0;
    for(int i = 0; i < tasksRowLen; i++) {
        int s = 0, kill = level;
        for(int j = i; j < x+i; j++) {
            if(kill >= tasks[j][0]) {
                kill += tasks[j][1];
            } else {
                break;
            }
        }
        res = max(res,kill);
    }

    return res;
}

int main()
{
    int x,level,a[1000][2];
    int row,col = 2;

    cin >> x >> level >> row;
    for(int i = 0; i < row; i++) {
       cin >> a[i][0] >> a[i][1];
    }
    int **p = a;
    cout << maxLevel(x,level,p,row,&col) << endl;
    return 0;
}
