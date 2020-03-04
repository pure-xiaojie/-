#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{   char weeks[8][5] = {"","MON","TUE","WED","THU","FRI","SAT","SUN"};

    char a[60],b[60],c[60],d[60];
    scanf("%s%s%s%s",a,b,c,d);
    int alen = strlen(a);
    int blen = strlen(b);
    int clen = strlen(c);
    int dlen = strlen(d);

    int minab = (alen < blen)?alen:blen;
    int mincd = (clen < dlen)?clen:dlen;

    int week = 1,i;
    for(i = 0; i < minab; i++)
        if(a[i] == b[i] && a[i] >= 'A' && a[i] <= 'Z')
        {
            week = a[i] - 'A' + 1;
            break;
        }

    int time = 0;
    for(int j = i+1; j < minab; j++)
    {
        if(a[j] == b[j] && (a[j] >= '0' && a[j] <= '9' || a[j] >= 'A' && a[j] <= 'N') )
        {
            if(a[j] >= '0' && a[j] <= '9')
                time = a[j]-'0';
            else
                time = a[j] - 'A' + 10;
            break;
        }
    }

    int j;
    for(j = 0; j < mincd; j++)
        if(c[j] == d[j] && (c[j] >= 'a' && c[j] <= 'z' || c[j] >= 'A' && c[j] <= 'Z'))
        {
            break;
        }

    printf("%s %d%d:%d%d",weeks[week],time/10,time%10,j/10,j%10);
    return 0;
}


