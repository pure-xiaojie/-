
#include<stdio.h>
#include<string.h>
char strs[10001];
int gplt[4];
int main()
{
	scanf("%s",strs);
	for(int i=0;i<strlen(strs);i++)
	{
		if(strs[i]=='g'||strs[i]=='G')
		{
			gplt[0]++;
		}
		else if(strs[i]=='p'||strs[i]=='P')
		{
			gplt[1]++;
		}
		else if(strs[i]=='L'||strs[i]=='l')
		{
			gplt[2]++;
		}
		else if(strs[i]=='t'||strs[i]=='T')
		{
			gplt[3]++;
		}
	}
	while(gplt[0]>0||gplt[1]>0||gplt[2]>0||gplt[3]>0)
	{
		for(int i=0;i<4;i++)
		{
			if(gplt[i]>0)
			{
				switch(i)
				{
					case 0:
						putchar('G');
						break;
					case 1:
						putchar('P');
						break;
					case 2:
						putchar('L');
					    break;
					case 3:
						putchar('T');
						break;

				}
				gplt[i]--;
			}
		}
	}

	return 0;
}

