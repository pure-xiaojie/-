#include<stdio.h>
int main()
{
    int m,n,i,j=0,s=0,a[100];
    scanf("%d%d",&m,&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(i=1;i<n;i++)
        if(a[j]<a[i])
           j=i;

    for(i=0;i<n;i++)
       if(a[i]<=a[j])
         if(s<=m)
         s+=a[i];

    printf("%d",s);
 return 0;
}
