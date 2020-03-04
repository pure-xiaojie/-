#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>

using namespace std;

int main()
{
    int n;
    char num1[10], num2[10];
    while(~scanf("%d%s%s",&n,num1,num2)) {
        stack<int> s;
        int flag[10] = {0},k = 0;

        int i = 0, j = 0;
        for(; i < n; i++) {
            s.push(num1[i]);
            flag[k++] = 1;

            while(!s.empty() && s.top() == num2[j]) {
                j++;
                s.pop();
                flag[k++] = 0;
            }
        }

        if(n && j == n && s.empty()) {
            cout << "Yes." << endl;
            for(int i = 0; i < k; i++) {
                if(flag[i]) {
                    cout << "in" << endl;
                }
                else {
                    cout << "out" << endl;
                }
            }
            cout << "FINISH" << endl;
        }
        else {
            cout << "No." << endl << "FINISH" << endl;
        }
    }
    return 0;
}
