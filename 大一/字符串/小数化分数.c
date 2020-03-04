# include<stdio.h>
int fun_sort(int a,int b);

int main()
{
    int i,N,a,p,q,t,m,n,x,y,k,l;
    char c[25];
    scanf("%d",&N);
    while(N--)
    {
        scanf("%s",c);
        x=t=p=q=0;
        k=1,l=1;
        for(i=2; c[i]!=0; i++)
        {
            if(t==0 && c[i]!='(')
            {
                p++;
                x*=10;
                x+=c[i]-'0';
            }
            if(t==1&& c[i]!=')')
            q++,y*=10,y+=c[i]-'0';

            if(c[i]=='(')
             t=1,y=x,q=p;

        }
        if(q==0)
        {
            while(p--)
             k*=10;
            a=fun_sort(x,k);
            x/=a,k/=a;
            printf("%d/%d\n",x,k);
        }
        else
        {
            m=y-x;
            while(p--)
            k*=10;
            while(q--)
            l*=10,n=l-k;
            a=fun_sort(m,n);
            m/=a,n/=a;
            printf("%d/%d\n",m,n);
        }
    }
    return 0;
}

int fun_sort(int m,int n)
{
    if(m%n==0)
    return n;
    return fun_sort(n,m%n);
}
