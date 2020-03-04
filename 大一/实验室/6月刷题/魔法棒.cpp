#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,s,a[1000],b[1000],m[1000];;
    for(i=0; i<n; i++)
        scanf("%d",&m[i]);

    int j=0,k=0,t=0;
    for(i=0; i<n; i++)
        if(m[i]>0)
            a[j++]=m[i];
        else if(m[i]<0)
            b[k++]=m[i];
        else
            t++;

    for(i=0; i<j; i++)
        for(s=0; s<k; s++)
        {
            if(a[i]+b[s]==0)
            {
                a[i]=b[s]=0;
                break;
            }

        }

    int sum=0;
    for(s=0; s<k;  s++)
        if(b[s]!=0)
            sum++;
    if(t>=sum)
    {
        printf("Yes\n");
        for(i=0; i<k-1; i++)
            for(j=i+1; j<k; j++)
                if(b[i]>b[j])
                {
                    t=b[i];
                    b[i]=b[j];
                    b[j]=t;
                }
        for(i=sum; i>=0; i--)
        {
            if(b[i]!=0)
                {printf("%d",b[i]*-1);
                 if(i>0)
                 printf(" ");}
        }
    }
    else
        printf("No\n");

return 0;
}
