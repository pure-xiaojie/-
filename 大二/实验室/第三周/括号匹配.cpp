#include<cstdio>
#include<iostream>
#include<stack>
#include<cstring>

using namespace std;
char str[1000];

int main()
{
    while(gets(str) != NULL)
    {
        stack<char>s;
        int i,flg,n = strlen(str);
        for(i = 0; i < n; i++)
        {
            int t = 0,t2 = 1;
            flg = 1;
            if(str[i] == '{' || str[i] == '(')
            {

                if(str[i] == '(' && t2)
                    {
                        t = i;
                        t2 = 0;
                    }
                else if(str[i] == '{' && t < i)
                    {
                        flg = 0;
                        break;
                    }
                s.push(str[i]);
            }
            else
            {
                if(!s.empty())
                    if(str[i] == ')' && s.top() == '(' ||
                            str[i] == '}' && s.top() == '{' )
                        s.pop();
                    else
                        {
                            flg = 0;
                            break;
                        }
                else
                    {
                        flg = 0;
                        break;
                    }
            }
        }

        if(flg == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
