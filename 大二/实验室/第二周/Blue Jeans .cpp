#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

char str[15][65];
char sub[65];
char ans[65];
int len;

int main()
{
    int t,i,j,k,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(ans,'\0',sizeof(ans));
        for(i = 1; i<=n; i++)
            cin >> str[i];
        for(i = 1; i<=60; i++)
        {
            int find = 0;
            for(j = 0; j<=60-i; j++)
            {
                len = 0;
                int check = 1;
                for(k = j;;k++)
                {
                    sub[len++] = str[1][k];
                    if(len == i)
                        break;
                }
                sub[len] = '\0';
                for(k = 2; k<=n; k++)
                {
                    if(!strstr(str[k],sub))
                    {
                        check = 0;
                        break;
                    }
                }
                if(check)
                {
                    find = 1;
                    if(strlen(ans)<strlen(sub))
                        strcpy(ans,sub);
                    else if(strcmp(ans,sub)>0)
                        strcpy(ans,sub);
                }
            }
            if(!find)
            break;
        }
        if(strlen(ans)<3)
            cout << "no significant commonalities\n";
        else
            cout << ans << endl;
    }

    return 0;
}
