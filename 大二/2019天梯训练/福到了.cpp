#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

char str[101][101];
char temp[101][101];

int main()
{
    char ch;
    int N,flag=1;
    scanf("%c %d",&ch,&N);
    getchar();
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%c",&str[i][j]);
        }
        getchar();
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            temp[i][j]=str[N-1-i][N-1-j];
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(temp[i][j]!=str[i][j])
            {
                flag=0;
                break;
            }

        }
    }
    if(flag)
        printf("bu yong dao le\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(temp[i][j]=='@')
                putchar(ch);
            else if(temp[i][j]==' ')
                putchar(' ');
        }
        printf("\n");
    }
    return 0;
}
