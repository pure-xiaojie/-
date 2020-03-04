#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    char a[100],b[100],c[100];
    int T;
    int i,la,lb,laa,lbb,A[100];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",a,b);
        memset(A,0,sizeof(A));
        memset(c,0,sizeof(c));
        la=strlen(a);
        lb=strlen(b);
        laa=0;
        for(i=la-1; i>=0; i--)
            A[laa++]=a[i]-'0';
        lbb=0;
        for(i=lb-1; i>=0; i--)
            c[lbb++]=b[i]-'0';
        for(i=0; i<max(laa,lbb)+1; i++)
        {
            A[i]+=c[i];
            if(A[i]>=10)
            {
                A[i]-=10;
                A[i+1]++;
            }
        }
        int flat=0;
        for(i=max(laa,lbb)+1; i>=0; i--)
        {
            if( flat)
                printf("%d", A[i]);
            else if( A[i] )
            {
                printf("%d", A[i]);
                flat=1;
            }
        }
        printf("\n");
    }
    return 0;
}
