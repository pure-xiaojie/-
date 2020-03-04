#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 10010
char word[N][20];
int Judge1(char *a, char *b, int len)
{
    int i, ans = 0;
    for (i = 0; i < len; ++i)
    {
        if (a[i] != b[i])
        {
            ans ++;
            if (ans > 1)
                return 0;
        }
    }
    return 1;
}
int Judge2(char *a, char *b, int len)
{
    int i, j, ans = 0;
    for (i = 0, j = 0; i < len; ++i)
    {
        if (a[i] != b[j])
        {
            ans ++;
            j --;
            if (ans > 1)
                return 0;

        }
        j ++;
    }
    return 1;
}
int main()
{
    int i, s, flag, len1, len2;
    char c[20];
    memset(word, 0, sizeof(word));
    s = 0;
    while (scanf("%s", word[s]) && strcmp(word[s], "#") != 0)
        s++;

    while (scanf("%s", c) && strcmp(c, "#") != 0)
    {
        printf("%s", c);
        flag = 1;
        for (i = 0; i < s; ++i)
        {
            if (strcmp(c, word[i]) == 0)
            {
                printf(" is correct\n");
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf(":");
            len1 = strlen(c);
            for(i = 0; i < s; ++i)
            {
                len2 = strlen(word[i]);
                if (len1 == len2 && Judge1(c, word[i], len1))
                    printf(" %s", word[i]);

                if ((len1 - len2 == 1) && Judge2(c, word[i], len1))
                    printf(" %s", word[i]);

                if ((len2 - len1 == 1) && Judge2(word[i], c, len2))
                    printf(" %s", word[i]);

            }
            printf("\n");
        }
    }
    return 0;
}
