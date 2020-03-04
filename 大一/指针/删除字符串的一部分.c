#include<stdio.h>
#include<string.h>

int del_substr(char str[],char const substr[])
{
	int i,j;

	for(i=0;str[i];i++)
	{
		for(j=0;str[i+j]==substr[j] && substr[j];j++);
		if(!substr[j])
		{
			for(j+=i;str[i++]=str[j++];);
			return 1;
		}
	}
	return 0;
}

void main()
{
	char s1[65536],s2[65535];
	int r,T;
	scanf("%d",&T);
    while(T--)
    {
       scanf("%s %s",s1,s2);
	    r=del_substr(s1,s2);
	    if(r)
	      printf("YES,%s\n",s1);
	    else
	      printf("NO\n");
    }
}
