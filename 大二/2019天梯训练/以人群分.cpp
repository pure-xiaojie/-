#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn=1e5+7;

int n,n1,n2;

int a[maxn],sum[maxn];

int main()
{

    while(~scanf("%d",&n))
    {

        memset(sum,0,sizeof(sum));

        for(int i=1; i<=n; i++)
        {

            scanf("%d",&a[i]);

        }

        sort(a+1,a+n+1);

        for(int i=1; i<=n; i++)
        {

            sum[i]=sum[i-1]+a[i];

        }

        if(n%2)
        {

            n1=n/2+1;

            n2=n/2;

        }

        else
        {

            n1=n2=n/2;

        }

        printf("Outgoing #: %d\n",n1);

        printf("Introverted #: %d\n",n2);

        printf("Diff = %d\n",sum[n]-2*sum[n2]);

    }
    return 0;
}
