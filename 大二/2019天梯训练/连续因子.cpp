#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    int n=sqrt(N);
    int i,j;
    long long int sum;
    for(int len=11; len>=1; len--) //len�����������ӵĸ���������N��Χ���������ֻ�ܵ�12�Ľ׳�
    {
        for( i=2; i<=n; i++) //�������Ӳ�����1����2��ʼ�ˣ����˵�N�����Ϳ϶�����
        {
            sum=1;
            for(  j=i; j<=len-1+i; j++) //�ӵ�ǰ��i��ʼ�����Եĸ���Ϊlen�ĳ���
            {
                sum*=j;
                if(sum>N)//�����û�б�Ҫ��������
                    break;
            }
            if(N%sum==0)//��ǰ��sumֵ��N��һ������
            {
                printf("%d\n%d",len,i);
                for(int k=i+1; k<j; k++)
                    printf("*%d",k);
                printf("\n");
                return 0;
            }
        }
    }
    printf("1\n%d\n",N);//���������
    return 0;
}
