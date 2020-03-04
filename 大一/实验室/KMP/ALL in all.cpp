#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 100001
char a[maxn], b[maxn];

int judge(int c_i, int c_j, int s_i, int s_j)
{
    int c_len = c_j-c_i, s_len = s_j-s_i;
    if (c_len > s_len)
        return 0;
    int i;
    for (i=s_i; i<=s_j; i++)
        if (a[c_i] == b[i])
        {
            if (c_len == 0)
                return 1;
            return judge(c_i+1, c_j, i+1, s_j);
        }
    return 0;
}
int main()
{
    while (scanf("%s %s", a, b) != EOF)
        printf("%s\n", judge(0, strlen(a)-1, 0, strlen(b)-1) ? "Yes" : "No");

    return 0;
}
