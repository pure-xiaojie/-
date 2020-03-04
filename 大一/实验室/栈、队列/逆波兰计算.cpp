#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;

stack<char> s;

int main()
{
    char a[200],c,e;
    int i=0;
    scanf("%c",&c);
    while( c != EOF)
    {
        while( c >= '0' && c <= '9')
        {
            a[i++]=c;
            scanf("%c",&c);
            if( c<'0' || c>'9' )
                a[i++]=' ';

        }

        if( ')' == c )
        {
            e=s.pop();
            while( '(' != e)
            {
                a[i++]=c;
                a[i++]=' ';
                e=s.pop();

            }

        }
        else if( '+' == c || '-' == c )
        {
            if( !s.size() )
            {
                s.push(c);
            }
            else
            {
                do
                {
                    e=s.pop();
                    if( '(' == e)
                        s.push(e);
                    else
                        a[i++]=e;
                        a[i++]=' ';

                }
                while( s.size() && '(' != e);
                s.push(c);
            }

        }
        else if( '*'==c || '/'==c || '('==c)
            s.push(c);
        else if( EOF== c)
            break;

        scanf("%c",&c);
    }
    while(s.size())
    {
        e=s.pop();
        a[i++]=e;
        a[i++]=' ';
    }
    a[i]='\0';
return 0;
}

