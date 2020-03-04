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
    char a[2000],b[1000];
    int i,la,lb,laa,lbb,A[1000],c[1000];

    while(~scanf("%s",a))
    {    getchar();
        for(i=0;i<strlen(a);i++)
           if(a[i]==',')
            break;
        strcat(b,a+i+1);
        a[i]='\0';
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
