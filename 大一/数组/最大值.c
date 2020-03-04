/* Note:Your choice is C IDE */
#include<stdio.h>
#define swap(a,b) {int c=a;a=b;b=c;}
int  main()
{
    int i,j,n,max=0,min=0;
    int a[9999];
    while(scanf("%d",&n)!=EOF)
    {
        max=min=0;

        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);

            if(a[i]<a[min])
                min=i;
        }
        swap(a[0],a[min]);
        for(i=0; i<n; i++)
        {
            if(a[i]>a[max])
                max=i;
        }
        swap(a[n-1],a[max]);
        for(i=0; i<n; i++)
            printf((i<n-1?"%d ":"%d\n"),a[i]);



    }


    return 0;
}
