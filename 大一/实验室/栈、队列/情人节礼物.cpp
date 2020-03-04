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
    char a[1000],c;
    while(cin>>a)
    {
        int n=strlen(a);
        for( int i=0; i<n; i++)
            if(a[i] == '(')
                s.push(1);
            else if(a[i] == ')')
                s.pop();
            else
                break;
        int k=0;
        while(!s.empty())
        {
            k++;
            s.pop();
        }
        cout<<k<<endl;
    }
    return 0;
}

