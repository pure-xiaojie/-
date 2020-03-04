/* Note:Your choice is C IDE */
#include <stdio.h>
void main()
{ 
	int N,i,j;
	long int a[10][10],sum=0;
		scanf("%d",&N);
	
	 for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			scanf("%lld",&a[i][j]);
			if(i==j||i+j==N-1)
				sum=sum+a[i][j];
		}
		printf("%lld\n",sum);
    return 0;
}