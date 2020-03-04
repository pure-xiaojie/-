#include<stdio.h>
#include<string.h>
char a[30],b[30];

void fun(int ab, int ae, int bb, int be)
{//四个参数分别为：先序遍历的起始位置和结束位置和中序遍历的起始位置和结束位置
    int i;
    if(ab>ae)
        return;
    putchar(a[ae]);//由于是求先序遍历，所以要先输出根节点
    putchar(' ');
    for(i=bb; b[i]!=a[ae]; ++i);//对应的，后序序列的最后一个为根，所以根为a[ae]
        fun(ab, ae-be+i-1, bb, i-1);//递归求左子树的先序遍历
    fun(ae-be+i, ae-1, i+1, be);//递归求右子树的先序遍历，ae-1为去掉根后的位置
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

    //先输入后序，在输入中序
    int len=strlen(a);

    fun(0,len-1,0,len-1);

    return 0;
}
