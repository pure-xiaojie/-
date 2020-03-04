#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

char getMax(int acjbnum[])
{
    char amax;
    if(acjbnum[0] >= acjbnum[1] && acjbnum[0] >= acjbnum[2])
        amax = 'B';
    else if(acjbnum[1] >= acjbnum[0] && acjbnum[1] >= acjbnum[2])
        amax = 'C';
    else if(acjbnum[2] >= acjbnum[0] && acjbnum[2] >= acjbnum[1])
        amax = 'B';

    return amax;
}

int main()
{
    int num,sum;
    scanf("%d",&num);
    sum = num;
    char a,b;

    int awin = 0,alos = 0;
    int acjbnum[3] = {0};
    int bcjbnum[3] = {0};
    while(num--)
    {
        getchar();
        scanf("%c %c",&a,&b);
        if((a == 'C' && b == 'J') || (a == 'B' && b == 'C') ||
           (a == 'J' && b == 'B'))
           {
               awin++;
               if(a == 'B')
                 acjbnum[0]++;
               else if(a == 'C')
                 acjbnum[1]++;
               else
                 acjbnum[2]++;
           }

        else if(a != b)
        {
            alos++;
            if(b == 'B')
             bcjbnum[0]++;
            else if(b == 'C')
             bcjbnum[1]++;
            else
             bcjbnum[2]++;
        }

    }

    char amax,bmax;
    amax = getMax(acjbnum);
    bmax = getMax(bcjbnum);

    printf("%d %d %d\n",awin,sum-awin-alos,alos);
    printf("%d %d %d\n",alos,sum-awin-alos,awin);
    printf("%c %c",amax,bmax);
    return 0;
}

