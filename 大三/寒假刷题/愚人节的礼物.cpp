#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

int main()
{
    char str[1000];
    while(~scanf("%s", str))
    {
        int len = strlen(str);
        stack<char> s;
        int res = 0;
        for(int i = 0; i < len; i++) {
            if(str[i] == '(')
            {
                s.push('(');
                res++;
            }
            else if(str[i] == ')' && !s.empty() && s.top() == '(')
            {
                s.pop();
                res--;
            }
            else
            {
                break;
            }

        }
        cout << res << endl;
    }
    return 0;
}
