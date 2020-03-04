#include"stdio.h"
void main()
{
    int t,i,j,n[65536][100];
    scanf("%d",&t);
    for(i=0;i<t;i++)
     scanf("%s",n[i]);

     for(i=0;i<t;i++)
     printf("%s ",n[i]);

}
