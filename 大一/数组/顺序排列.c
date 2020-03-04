/* Note:Your choice is C IDE */
#include<stdio.h>

int sum_m(int b[],int m)
{
    int i,sum=0;
    for(i=0;i<m;i++)
        sum+=b[i];
    return sum;
}

void fun_copy(int c1[],int c2[],int m)
{
    int i,t;
    for(i=0;i<m;i++)
    {
        t=c1[i];
        c1[i]=c2[i];
        c2[i]=t;
    }
}

void main()
{
    int str[50][50],ch[100];
    int n,i,j,t;
    scanf("%d",&n);
    getchar();
    
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
        scanf("%d",&str[i][j]);
   
    for(i=0;i<n;i++)
      ch[i]=sum_m(str+i,n);
   
    for(i=0;i<n-1;i++)
      for(j=0;j<n-1-i;j++)
      if(ch[j]>ch[j+1])
       {
        t=ch[j];
        ch[j]=ch[j+1];
        ch[j+1]=t;
         fun_copy(str+j,str+(j+1),n);
       }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
          printf("%d ",str[i][j]);
        printf("\n");
    }

}
