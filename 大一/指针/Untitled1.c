#include <stdio.h>
#include <malloc.h>

void main()
{
	int n,m,i,j,k=1,t;
	scanf("%d",&m);

	while(m--)
    {
    scanf("%d",&n);
    int *p =(int *)malloc(n*sizeof(int));
	for(i =0;i<n;i++)
    scanf("%d",p+i);

	for(i =0;i<n-1;i++)
     for(j =i+1;j<n;j++)
	if(p[i]>p[j])
	 {
		t = p[i];
	    p[i] = p[j];
		p[j] = t;
     }

     printf("Case %d: ",k++);
	 for(i =0;i<n;i++)
      printf("%d ",p[i]);
      printf("\n");
	}


}
