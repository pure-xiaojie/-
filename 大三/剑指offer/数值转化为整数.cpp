#include<bits/stdc++.h>

using namespace std;

int StrToInt(string str)
{
    int len = str.size();
    if(len == 0)
        return 0;

    int sum = 0,i;

    if(str[0] == '+' || str[0] == '-')
        i = 1;
    else
        i = 0;

    for(; i < len; i++) {
        if(!(str[i] >= '0' && str[i] <= '9'))
            return 0;
        else {
            if(str[0] != '-' && (INT_MAX - (sum*10)) < (str[i] - '0'))
                return 0;
            if((INT_MAX - (sum*10)) < (str[i] - '1'))
                return 0;
            sum = sum*10 + (str[i] - '0');
        }
    }
    if(str[0] == '+' || (str[0] >= '0' && str[0] <= '9'))
        return sum;
    else
        return sum * -1;
}

int main()
{
    int n;
    cin >> n;
    getchar();
    while (n--)
    {
        string s;
        getline(cin,s);
        cout << StrToInt(s) << endl;
    }
    return 0;
}
