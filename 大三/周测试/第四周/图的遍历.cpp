#include<bits/stdc++.h>

using namespace std;
int dep[100005];  //�����ȣ�Ĭ��Ϊ0

int main()
{
    int n;
    cin >> n;
    int a,b;
    for(int i = 1; i < n; i++) {
        cin >> a >> b;
        dep[b] = dep[a] + 1;    //��ǰ���b�����Ϊǰһ���������+1
    }
    int maxDeepth = 0;   //���������
    for(int i = 1; i <= n; i++) {
        maxDeepth = maxDeepth < dep[i] ? dep[i] : maxDeepth;
    }

    //n-maxDeepth-1Ϊ������㣬��������飬����*2     maxDeepth�����ȣ�������
    cout << 2 * (n-maxDeepth-1) + maxDeepth << endl;
    return 0;
}
