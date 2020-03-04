/* Note:Your choice is C IDE */
#include<stdio.h>
void main()
{
    int N,str[1000]={0},i,j,m,k=0;
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++)
        {
            scanf("%d",&m);
            if(str[m]==0)
             k++;
            str[m]++;
        }
        printf("%d\n",k);
        for(i=0;i<1000;i++)
        if(str[i]!=0)
          printf("%d ",i);
 
}
