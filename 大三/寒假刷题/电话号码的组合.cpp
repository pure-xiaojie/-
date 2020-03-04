#include<bits/stdc++.h>

using namespace std;

map<char, string> table{
    {'0'," "},{'1',"*"},{'2',"abc"},
    {'3',"def"},{'4',"ghi"},{'5',"jkl"},
    {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},
    {'9',"wxyz"}
};

void getRes(vector<string> &res, string str, string digits)
{
    int lenStr = str.size();
    if(lenStr == digits.size()) {
        res.push_back(str);
        return;
    }
    string temp = table[digits[lenStr]];
    for(char ch : temp) {
        str += ch;
        getRes(res, str, digits);
        str.pop_back();
    }
    return;
}

vector<string> letterCombinations(string digits)
{
    vector<string> res;
    if(digits == "")
        return res;
    getRes(res,"",digits);
    return res;
}

int main()
{
   string str;
   int n;
   cin >> n;
   while(n--) {
        cin >> str;
        vector<string> res = letterCombinations(str);
        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
   }
}
