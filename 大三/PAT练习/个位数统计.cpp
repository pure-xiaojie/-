#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

char num[1005];
int n[10];

int main()
{
    scanf("%s",num);

    for(int i = 0; i < strlen(num); i++)
        n[num[i]-'0']++;

    for(int i = 0; i < 10; i++)
        if(n[i] > 0)
            printf("%d:%d\n",i,n[i]);
    return 0;
}
