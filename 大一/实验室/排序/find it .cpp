#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;

#define T 501
int A[T],B[T],C[T],D[T*T];

bool compare(int a,int b)
{
    return a<b;
}

int main()
{
    int l,n,m,i,b=1;
    while(~scanf("%d%d%d",&l,&n,&m))
    {
        for(i=0; i<l; i++)
            scanf("%d",&A[i]);
        for(i=0; i<n; i++)
            scanf("%d",&B[i]);
        for(i=0; i<m; i++)
            scanf("%d",&C[i]);
        int j,k=0;
        for(i=0; i<l; i++)
            for(j=0; j<m; j++)
                D[k++]=A[i]+B[j];
        sort(D,D+k,compare);

        int S,x;
        scanf("%d",&S);
        printf("Case %d:\n",b++);

LOOP_VAL:
        while(S--)
        {
            scanf("%d",&x);
            for(i=0; i<m; i++)
            {
                int temp=x-C[i];
                int left=0,right=k-1,mid;
                while(left<right)
                {
                    mid=(left+right)/2;
                    if(D[mid]==temp)
                    {
                        cout<<"YES"<<endl;
                        goto LOOP_VAL;
                    }
                    else if(temp>D[mid])
                    {
                        left=mid+1;
                    }
                    else
                    {
                        right=mid;
                    }
                }


            }
            cout<<"NO"<<endl;

        }
    }
    return 0;
}

