/* Note:Your choice is C IDE */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
int n;
int number;
srand((unsigned)time(NULL)); //产生随机数。
number=rand()%100;
printf("游戏开始！\n");
printf("请输入1—100之间的整数：");
while(1)
{
scanf("%d",&n);
if(n==number)
{printf("恭喜你猜对了，游戏结束。\n");break;}
if(n>number)
printf("大了！\n");
if(n<number)
printf("小了！\n");}
}