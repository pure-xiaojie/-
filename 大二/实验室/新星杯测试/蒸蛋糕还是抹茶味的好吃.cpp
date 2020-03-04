#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int t,n;
    char ch[31],id[101][31];

    while(~scanf("%d",&t))
    {
        for(int i = 0; i < t; i++)
        {
            scanf("%s",ch);
            scanf("%d",&n);
            int num = 0;
            for(int j = 0; j < n; j++)
            {
                scanf("%s",id[j]);
                if(strcmp(ch,id[j]) == 0)
                    num++;
            }
            cout << num << endl;

        }
    }

    return 0;
}
