#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,a[150005],is[150005];

int main()
{
    while(~scanf("%lld",&n)) {
        memset(is,0,sizeof(is));          //��ʼ��״̬����Ϊ�Ƕ����������
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a,a+n);

        ll sum = 0;   //���н�
        for(int i = 0; i < n; i++) {
            if(is[a[i]-1] == 0 && a[i] != 1) {     //���жϸ��������
                sum++;
                is[a[i-1]] = 1;
            }
            else if(is[a[i]] == 0 ) {       //��߲����㣬�жϸ���λ��
                sum++;
                is[a[i]] = 1;
            }
            else if(is[a[i]+1] == 0) {    //��������λ�ò����㣬�ж��ұ�
                sum++;
                is[a[i]+1] = 1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
