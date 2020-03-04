#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;

int main()
{
    int k,i,a;
    cin >> a;
    for (k=0; k<a; k++)
    {
        queue<string> q[21];
        printf("Case #%d:\n",k+1);
        int n,m=0;
        cin >> n;
        for (i=0; i<n; i++)
        {
            char s[20];
            cin >> s;
            int j;
            if (s[0]=='A')
            {
                cin >> s >>j;
                m++;
                cout << m << endl;
                q[j].push(s);
            }
            else
            {
                cin >>j;
                while ( j<=20 && q[j].empty() )
                    j++;
                if ( j==21 || q[j].empty() )
                    printf("WAIT...\n");
                else
                {
                    const char *str1;
                    string str2;
                    str2=q[j].front();
                    str1=str2.c_str();
                    cout << str1 << endl;
                    q[j].pop();
                    m--;
                }
            }
        }
    }
    return 0;
}
