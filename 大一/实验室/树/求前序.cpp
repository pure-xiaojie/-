#include<stdio.h>
#include<string.h>
char a[30],b[30];

void fun(int ab, int ae, int bb, int be)
{//�ĸ������ֱ�Ϊ�������������ʼλ�úͽ���λ�ú������������ʼλ�úͽ���λ��
    int i;
    if(ab>ae)
        return;
    putchar(a[ae]);//���������������������Ҫ��������ڵ�
    putchar(' ');
    for(i=bb; b[i]!=a[ae]; ++i);//��Ӧ�ģ��������е����һ��Ϊ�������Ը�Ϊa[ae]
        fun(ab, ae-be+i-1, bb, i-1);//�ݹ������������������
    fun(ae-be+i, ae-1, i+1, be);//�ݹ��������������������ae-1Ϊȥ�������λ��
}

int main()
{
    int i,j;
    char str1[30],str2[30];
    gets(str1);
    gets(str2);

    for(i=0,j=0; i<strlen(str1); i++)
          if(str1[i] != ' ')
           b[j++]=str1[i];
    b[j]='\0';

    for(i=0,j=0; i<strlen(str2); i++)
          if(str2[i] != ' ')
           a[j++]=str2[i];
    a[j]='\0';

    //�������������������
    int len=strlen(a);

    fun(0,len-1,0,len-1);

    return 0;
}
