#include <stdio.h>
#include <string.h>

#define maxn 100
char s[maxn];

int main()
{
    while(scanf("%s",s),strcmp(s,"end"))
    {
        int len=strlen(s);
        int t1=0,t2=0,a=0,b=0;
        for(int i=0; i<len; i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||s[i]=='u')
            {
                t1 = 1;
                a++;
                b=0;
            }
            else b++,a=0;

            if(a==3 || b==3)
            {
                t2 = 1;
                break;
            }
            if(i!=0 && s[i]!='e'&&s[i]!='o' && s[i]==s[i-1])
            {
                t2 = 1;
                break;
            }
        }
        if(t2 || !t1)
            printf("<%s> is not acceptable.\n",s);
        else
            printf("<%s> is acceptable.\n",s);
    }
    return 0;
}
