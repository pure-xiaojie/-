#include<cstdio>
#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int n;
    char s1[20],s2[20];
    while(~scanf("%d %s %s",&n,s1,s2))
    {
        stack <char> s;
        int flag[100]={0};
        int j=0,k=0;
        for(int i=0; i < n; i++)
        {
            s.push(s1[i]);
            flag[k++] = 1;
            while(!s.empty() && s.top() == s2[j])
            {
                flag[k++] = -1;
                s.pop();
                j++;
            }
        }
        if(j == n)
        {
            printf("Yes.\n");
            for(int i = 0; i < k; i++)
            {
                if(flag[i] == 1)
                    printf("in\n");
                else if(flag[i] == -1)
                    printf("out\n");
            }
        }
        else
            printf("No.\n");
		printf("FINISH\n");

    }
    return 0;
}
