#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
    int sum;
    cin >> sum;
    while(sum--)
    {

        char a[101],b[101],c[101];
        cin >> a >> b;

        int m,n,i,j;
        i=m=strlen(a);
        j=n=strlen(b);

        if(m<n)
        {
            strcpy(c,a);
            strcpy(a,b);
            strcpy(b,c);
            i=n;
            j=m;
        }
        int t,d=0;
        i-=1;
        j-=1;
        for(; i>=0&&j>=0; i--,j--)
        {
            t=a[i]-48+b[j]-48+d;
            if(t>10)
            {
                c[i+1]=t%10+48;
                d=1;
            }
            else
            {
                c[i+1]=t+48;
                d=0;
            }
        }
        if(d > 0)
        for(; i >= 0; i--)
        {
            t=a[i]-48+d;
            if(d > 10)
            {
               c[i+1]=t%10+48;
               d=1;
            }
            else
            {
               c[i+1]=t+48;
               break;
            }

        }

        cout << c << endl;
    }


    return 0;
}
