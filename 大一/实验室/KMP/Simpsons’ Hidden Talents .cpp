#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAX 50007

using namespace std;

char s1[MAX<<1],s2[MAX];

void get_next ( char p[] , int next[] )
{
    int i = 0 , k = -1 , len = strlen (p);
    next[0] = -1;
    while ( i < len )
        if ( k == -1 || p[i] == p[k] )
            i++,k++,next[i] = k;
        else k = next[k];
}

void solve ( char s[] )
{
    int len = strlen ( s );
    int next[MAX<<1];
    get_next ( s , next );
    if ( next[len] )
    {
        for ( int i = 0 ; i < next[len] ; i++ )
            printf ( "%c" , s[i] );
        printf ( " " );
    }
    printf ( "%d\n" , next[len] );
}

int main ( )
{
    while ( ~scanf ( "%s" , s1 ) )
    {
        scanf ( "%s" , s2 );
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        for ( int i = 0 ; i < len2 ; i++ )
            s1[i+len1+1] = s2[i];
        s1[len1] = '#';
        s1[len1+len2+1] = 0;
        solve ( s1 );
    }
}
