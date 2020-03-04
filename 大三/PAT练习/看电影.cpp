#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
    int begin;
    int end;
};

bool cmp(node a,node b)
{
    return a.end<b.end;
}

int main() {
    int n;
    node f[101];
    while(scanf("%d",&n) && n)
    {
        for(int i=0; i<n; i++)
            cin>>f[i].begin>>f[i].end;

        int sum = 1;

        sort(f,f+n,cmp);
        int current_end = f[0].end;
        for(int i=1; i<n; i++) {
            if(f[i].begin>=current_end) {
                current_end = f[i].end;
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
