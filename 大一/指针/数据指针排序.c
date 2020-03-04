#include <stdio.h>
#include <malloc.h>
void main()
{
	int m,n,i,j,k,t;
	int *p,*r,**q;
	scanf("%d",&n);
	p =(int *)malloc(n*sizeof(int));
	q =(int **)malloc(n*sizeof(int*));
	for(i =0;i<n;i++)
	{
		scanf("%d",&m);
		p[i]=m;
		r = (int*)malloc(m*sizeof(int));
		q[i] = r;
		for(j=0;j<m;j++)
			scanf("%d",&r[j]);

	for(i =0;i<n;i++)
	{
		for(j=0;j<p[i]-1;j++)
		{
			for(k=j+1;k<p[i];k++)
				if(q[i][k]<q[i][j])
				{
					t = q[i][k];
					q[i][k] = q[i][j];
					q[i][j] = t;
				}
		}

	for(i =0;i<n;i++)
	{
		printf("Case %d:",i+1);
		for(j=0;j<p[i];j++)
		{
			printf("%d ",q[i][j]);
		}
		printf("\n");
	}
}}}
