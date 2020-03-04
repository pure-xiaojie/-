#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

stack <char> s;

int main ()
{
    int n,i,j,k,judge[50];;
    char in[20],out[20];

    while (~scanf ("%d%s%s",&n,in,out))
    {
        while (!s.empty())
            s.pop();

        memset(judge, 0, sizeof(judge));
        j = k = 0;
        for (i=0; i<n; i++)
        {
            s.push(in[i]);
            judge[k++] = 1;
            while (!s.empty() && s.top() == out[j])
            {
                judge[k++] = 0;
                s.pop();
                j++;
            }
        }
        if (j == n)
        {
            printf ("Yes.\n");
            for (i=0; i<k; i++)
            {
                if (judge[i])
                    printf ("in\n");
                else
                    printf ("out\n");
            }
        }
        else
            printf ("No.\n");
        printf ("FINISH\n");
    }
    return 0;
}

