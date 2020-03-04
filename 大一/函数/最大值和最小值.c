/* Note:Your choice is C IDE */
#include<stdio.h>
double sub(double a[],int i)
{
    double min,max;
    int n;
    min=a[0];
    max=a[0];
    for(n=0;n<i;n++)
    {
        if(min>a[n])
            min=a[n];
        if(max<a[n])
            max=a[n];
    }
    return max-min;
}
void main()
{    int n,i;
    double a[1000];
    scanf("%d",&n);
            
        for(i=0;i<n;i++)
         scanf("%lf",&a[i]);
    
    printf("%.2lf",sub(a,n));
    
}
 
