/* Note:Your choice is C IDE */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
int n;
int number;
srand((unsigned)time(NULL)); //�����������
number=rand()%100;
printf("��Ϸ��ʼ��\n");
printf("������1��100֮���������");
while(1)
{
scanf("%d",&n);
if(n==number)
{printf("��ϲ��¶��ˣ���Ϸ������\n");break;}
if(n>number)
printf("���ˣ�\n");
if(n<number)
printf("С�ˣ�\n");}
}