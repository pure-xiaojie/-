#include<iostream>
#include<algorithm>
#include<cstdio>
#include<stack>
#include<cstring>
#include<cctype>
using namespace std;

struct Matrix
{
    int a, b;
    Matrix(int a = 0, int b = 0) :a(a), b(b) {}

} m[26];

stack<Matrix> s;
char str[2000];

int main()
{
    int n,len,ans;
    bool error;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> str;
        int k = str[0] - 'A';
        cin >> m[k].a >> m[k].b;
    }
    while (~scanf("%s", str))
    {
        len = strlen(str);
        error = false;
        ans = 0;
        for (int i = 0; i < len; i++)
        {
            if (isalpha(str[i])) s.push(m[str[i] - 'A']);
            else if (str[i] == ')')
            {
                Matrix m2 = s.top();
                s.pop();
                Matrix m1 = s.top();
                s.pop();
                if (m1.b != m2.a)
                {
                    error = true;
                    break;
                }
                ans += m1.a*m1.b*m2.b;
                s.push(Matrix(m1.a, m2.b));
            }
        }
        if (error)
            printf("error\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
