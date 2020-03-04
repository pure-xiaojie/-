#include<stdio.h>
#include<string.h>

 char a[200],S[200];

int main()
{
    int n,i,j=0;
    scanf("%d",&n);
    getchar();
    while(n-->0)
    {
        j=0;
        int flag=0;
        gets(a);
        if(strlen(a)==0)
        {
            printf("Yes\n");
            continue;
        }
        for(i=0; a[i]!='\0'; i++)
        {
            if((a[i]=='(')||(a[i]=='['))
            {
                S[j++]=a[i];
            }
            else if((a[i]==')')||(a[i]==']'))
            {
                if((a[i]==')'&&S[j-1]==a[i]-1)||(a[i]==']'&&S[j-1]==a[i]-2))
                j--;
                else
                {
                    flag=1;
                    break;
                }
            }
        }
        if(j==0&&flag==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
 return 0;
}
