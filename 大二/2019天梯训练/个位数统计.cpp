#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[1005];
    int num[10] = {0};
    cin >> str;
    for(int i= 0; i < strlen(str); i++)
      num[str[i] - 48]++;

    for(int i = 0; i < 10; i++)
        if(num[i])
        cout << i << ':' << num[i] << endl;
    return 0;
}
