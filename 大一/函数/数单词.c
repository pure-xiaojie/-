/* Note:Your choice is C IDE */
#include <stdio.h>
#include <string.h>
int Solve(char str[])
{
    return Count(str);
 
}
int Count(char str[])
{
    int i,c=0,f=0;
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]==' ')
            f=0;
        else if(f==0)
        {
            f=1;
            c++;
        }
    }
    return c;
}
 
int main()
{
 
    char a[100]= {'\0'};
    int n;
    scanf("%d",&n);getchar();
    
    while(n--)
    {
    gets(a);
    printf("%d\n",Solve(a));
    }
 
}
