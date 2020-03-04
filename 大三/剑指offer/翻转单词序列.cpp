#include<bits/stdc++.h>

using namespace std;

string ReverseSentence(string str) {
    int len = str.size();
    cout << len << endl;
    string res;
    if(len == 0)
        return res;

    for(int i = len - 1; i >= 0;) {
        if(str[i] != ' ')
            i--;
        else
        {
            int j = i + 1;
            while(j < len && str[j] != ' ') {
                res.push_back(str[j]);
                j++;
            }
            while(str[i] == ' ') {
                res.push_back(' ');
                i--;
            }
        }
    }
    for(int i = 0; str[i] != ' ' && i < len; i++)
        res.push_back(str[i]);
    return res;

}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        string str = "student.  a  am  I";
        cout << ReverseSentence(str) << endl;
    }

    return 0;
}
