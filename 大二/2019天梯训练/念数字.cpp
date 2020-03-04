#include<cstdio>
#include<iostream>

using namespace std;

void judge(int m)
{
    switch(m)
    {
    case 0:
        cout << "ling ";
        break;
    case 1:
        cout << "yi ";
        break;
    case 2:
        cout << "er ";
        break;
    case 3:
        cout << "san ";
        break;
    case 4:
        cout << "si ";
        break;
    case 5:
        cout << "wu ";
        break;
    case 6:
        cout << "liu ";
        break;
    case 7:
        cout << "qi ";
        break;
    case 8:
        cout << "ba ";
        break;
    case 9:
        cout << "jiu ";
        break;
    }
}

void judge2(int m)
{
    switch(m)
    {
    case 0:
        cout << "ling";
        break;
    case 1:
        cout << "yi";
        break;
    case 2:
        cout << "er";
        break;
    case 3:
        cout << "san";
        break;
    case 4:
        cout << "si";
        break;
    case 5:
        cout << "wu";
        break;
    case 6:
        cout << "liu";
        break;
    case 7:
        cout << "qi";
        break;
    case 8:
        cout << "ba";
        break;
    case 9:
        cout << "jiu";
        break;
    }
}

int main()
{
    int n,num[10];
    cin >> n;
    if(n < 0)
    {
        cout << "fu ";
        n = n *-1;
    }
    else if(n == 0)
        cout  << "ling";

    int t = 0;
    while(n)
    {
        num[t++] = n % 10;
        n /= 10;

    }

    for(int i = t-1; i > 0; i--)
        judge(num[i]);
    judge2(num[0]);
    return 0;
}

