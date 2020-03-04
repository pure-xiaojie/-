#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[5001];

    while(cin >> str)
    {
        int a = 0,b = 0,c = 0,t = 1;
        for(int i = 0; i < strlen(str); i++)
        {
            if(str[i] > str[i+1] && i+1 < strlen(str))
                {
                    t = 0;
                    break;
                }

            if(str[i] == 'a')
                a += 1;
            else if(str[i] == 'b')
                b += 1;
            else if(str[i] == 'c')
                c += 1;
        }
        if(t && (a == c || b == c ) && a && b && a+b+c == strlen(str))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
