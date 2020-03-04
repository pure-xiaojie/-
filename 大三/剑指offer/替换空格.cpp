#include<bits/stdc++.h>

using namespace std;

void replaceSpace(char *str,int length) {
    char ch[200];
    int k = 0;
    for (int i = 0; i < length; i++) {
        if(str[i] != ' ')
            ch[k++] = str[i];
        else
        {
            ch[k++] = '%';
            ch[k++] = '2';
            ch[k++] = '0';
        }
    }
    ch[k] = '\0';
    strcpy(str,ch);
}

int main()
{
    int n;
    cin >> n;
    getchar();
    while(n--) {
        char ch[100];
        gets(ch);
        replaceSpace(ch,strlen(ch));
        cout << ch << endl;
    }
    return 0;
}
