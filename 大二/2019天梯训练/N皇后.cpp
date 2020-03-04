#include<cstdio>
#include<alg>
using namespace std;
int chess[11]= {0,1,0,0,2,10,4,40,92,352,724};
int n;

int main()
{
    while(scanf("%d",&n),n)
        printf("%d\n",chess[n]);
    return 0;
}
