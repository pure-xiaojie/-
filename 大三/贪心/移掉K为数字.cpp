#include<bits/stdc++.h>

using namespace std;

string removeKdigits(string num, int k) {
        int N=num.size();
        //特殊情况处理
        if(k==0)
        {
            return num;
        }
        if(N<=k)
        {
            return "0";
        }
        vector<char> storage;
        //计算
        for(int i=0;i<N;i++)
        {
            while(storage.size()!=0&&storage.back()>num[i]&&k!=0)
            {
                storage.pop_back();
                k--;
            }
            storage.push_back(num[i]);
        }
        //末尾处理
        while(k!=0)
        {
            storage.pop_back();
            k--;
        }
        //前缀去0操作
        int i=0;
        for(;i<storage.size();i++)
        {
            if(storage[i]!='0')
            {
                break;
            }
        }
        string res="";
        for(int j=i;j<storage.size();j++)
        {
            res+=storage[j];
        }
        return res==""?"0":res;
}

int main()
{
    string s;
    int k,n;
    cin >> n;
    while(n--) {
        cin >> s >>k;
        cout << removeKdigits(s,k) << endl;
    }
    return 0;
}
