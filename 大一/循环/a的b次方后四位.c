/* Note:Your choice is C IDE */
#include <stdio.h>

int main ()
{
	int n;
    scanf ("%d",&n);
    while (n--)
    {
        long long int a,b,s;
        scanf("%ld%ld",&a,&b);
        s=1;
		while(b--)
	    s=s*a%10000;
		
		printf("%04ld\n",s);
    }
    return 0;
}