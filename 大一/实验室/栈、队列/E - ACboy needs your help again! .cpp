#include<cstdio>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int m;
        char s1[10];
        cin >> m >> s1;
        if(!strcmp(s1,"FIFO"))
        {
            queue <int> q;
            while(m--)
            {
                char s2[10];
                cin >> s2;
                if(!strcmp(s2,"IN"))
                {
                    int t;
                    cin >> t;
                    q.push(t);

                }
                else
                {
                    if(q.empty())
                        printf("None\n");
                    else
                    {
                        printf("%d\n",q.front());
                        q.pop();
                    }

                }
            }

        }
        else
        {
            stack <int> s;
            while(m--)
            {
                char s2[10];
                cin >> s2;
                if(!strcmp(s2,"IN"))
                {
                    int t;
                    cin >> t;
                    s.push(t);
                }
                else
                {
                    if(s.empty())
                        printf("None\n");
                    else
                    {
                        printf("%d\n",s.top());
                        s.pop();
                    }

                }
            }


        }
    }
    return 0;
}
