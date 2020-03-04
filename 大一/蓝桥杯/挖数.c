#include"stdio.h"
#include"string.h"
main()
{
    char a[100];
    int i,j,k=0,b[50]={0};
    gets(a);
    for(i=0,j=0;i<strlen(a);i++,j=i)
     while(a[j]>='0'&&a[j]<='9')
    {
        b[k]=b[k]*10+a[j]-'0';
        j++;
        i=j-1;
        if(!(a[j]>='0'&&a[j]<='9'))
          k++;
    }
    printf("%d\n",k);
    for(i=0;i<k;i++)
        printf("%d ",b[i]);


}
